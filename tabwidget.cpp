#include "stdafx.h"
#include "tabwidget.h"

#include "adddialog.h"


TabWidget::TabWidget(QWidget *parent)
	: QTabWidget(parent)
{
	m_tableModel = new AddressBoxModel(&m_addressBoxs, this);

	QStringList headerList;
	headerList << "ABC" << "DEF" << "GHI" << "JKL" << "NMO" << "PQR" << "STU" << "VWX" << "YZ";
	for (int i = 0; i < headerList.size(); ++i)
	{
		QString header = headerList.at(i);

		QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
		proxyModel->setSourceModel(m_tableModel);
		proxyModel->setDynamicSortFilter(true);

		QTableView *view = new QTableView;
		view->setModel(proxyModel);
		view->setSortingEnabled(true);
		view->setSelectionMode(QAbstractItemView::SingleSelection);
		view->setSelectionBehavior(QAbstractItemView::SelectRows);
		view->horizontalHeader()->setStretchLastSection(true);
		view->verticalHeader()->hide();

		QString newStr = QString("^[%1].*").arg(header);
		proxyModel->setFilterRegExp(QRegExp(newStr, Qt::CaseInsensitive));
		proxyModel->setFilterKeyColumn(AddressBoxModel::NAME);
		proxyModel->sort(0, Qt::AscendingOrder);

		//connect(view->selectionModel(),
		//	SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
		//	this, SIGNAL(selectionChanged(QItemSelection)));

		this->addTab(view, header);
	}
}

TabWidget::~TabWidget()
{

}

bool TabWidget::ReadFromFile( const QString &filePath )
{
	return true;
}

bool TabWidget::WriteToFile( const QString &filePath )
{
	return true;
}

bool TabWidget::AddEntry()
{

	AddDialog addDialog(this);
	if (addDialog.DoModal())
	{
		AddEntry(addDialog.addressBox);
		return true;
	}
	else
	{
		return false;
	}
}

bool TabWidget::AddEntry( const AddressBox &addressBox )
{

	if (!m_addressBoxs.contains(addressBox))
	{
		m_tableModel->insertRows(0, 1, QModelIndex());

		QModelIndex index = m_tableModel->index(0, 0);
		m_tableModel->setData(index, addressBox.name, Qt::EditRole);
		index = m_tableModel->index(0, 1);
		m_tableModel->setData(index, addressBox.address, Qt::EditRole);
	}
	return true;
}

bool TabWidget::RemoveEntry()
{

	QTableView *view = static_cast<QTableView*>(currentWidget());
	QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(view->model());
	QModelIndexList indexList = view->selectionModel()->selectedRows();
	for (int i = 0; i < indexList.size(); ++i)
	{
		const QModelIndex &index = indexList.at(i);
		int row = proxy->mapToSource(index).row();
		m_tableModel->removeRows(row, 1);
	}


	return true;
}

void TabWidget::EditEntry()
{
	QTableView *view = static_cast<QTableView*>(currentWidget());
	QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(view->model());
	QModelIndexList indexList = view->selectionModel()->selectedRows();

	if (indexList.isEmpty())
	{
		return;
	}

	int row = -1;
	AddressBox addressBox;
	for (int i = 0; i < indexList.size(); ++i)
	{
		const QModelIndex &index = indexList.at(i);
		row = proxy->mapToSource(index).row();
		QModelIndex temp = m_tableModel->index(row, 0);
		addressBox.name = m_tableModel->data(temp).toString();
		temp = m_tableModel->index(row, 1);
		addressBox.address = m_tableModel->data(temp).toString();
		break;
	}

	AddDialog addDialog(this);
	addDialog.SetData(addressBox);
	addDialog.m_nameLineEdit->setReadOnly(true);
	addDialog.m_addressTextEdit->setFocus();

	if (addDialog.DoModal())
	{
		QModelIndex temp = m_tableModel->index(row, 1);
		m_tableModel->setData(temp, addDialog.addressBox.address, Qt::EditRole);
	}

}
