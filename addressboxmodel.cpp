#include "stdafx.h"
#include "addressboxmodel.h"


AddressBoxModel::AddressBoxModel( AddressBoxs *addressBox, QObject *parent )
	: QAbstractTableModel(parent)
	, m_addressBoxs(addressBox)
{

}

AddressBoxModel::~AddressBoxModel()
{

}

Qt::ItemFlags AddressBoxModel::flags( const QModelIndex & index ) const
{
	if (!index.isValid())
	{
		return Qt::ItemIsEnabled;
	}

	return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant AddressBoxModel::data( const QModelIndex & index, int role /*= Qt::DisplayRole */ ) const
{
	if (!index.isValid())
	{
		return QVariant();
	}

	int row = index.row();
	if (row >= m_addressBoxs->size() || row < 0)
	{
		return QVariant();
	}
	int column = index.column();
	switch (role)
	{
	case Qt::DisplayRole:
		{
			if (column == NAME)
			{
				return m_addressBoxs->at(row).name;
			}
			else if (column == ADDRESS)
			{
				return m_addressBoxs->at(row).address;
			}
		}
		break;
	}


	return QVariant();
}

int AddressBoxModel::rowCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	Q_UNUSED(parent)
	return m_addressBoxs->count();
}

int AddressBoxModel::columnCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	Q_UNUSED(parent)
	return 2;
}

bool AddressBoxModel::setData( const QModelIndex & index, const QVariant & value, int role /*= Qt::EditRole */ )
{
	if (role != Qt::EditRole || !index.isValid())
	{
		return false;
	}
	int row = index.row();
	AddressBox &addressBox = (*m_addressBoxs)[row];
	if (index.column() == NAME)
	{
		addressBox.name = value.toString();
	}
	else if (index.column() == ADDRESS)
	{
		addressBox.address = value.toString();
	}
	else
	{
		return false;
	}

	emit dataChanged(index, index);

	return true;

}

bool AddressBoxModel::insertRows( int row, int count, const QModelIndex & parent /*= QModelIndex() */ )
{
	Q_UNUSED(parent)
	beginInsertRows(QModelIndex(), row, row + count -1);
	for (int i = 0; i < count; ++i)
	{
		m_addressBoxs->insert(row, AddressBox());
	}
	endInsertRows();
	return true;

}

bool AddressBoxModel::removeRows( int row, int count, const QModelIndex & parent /*= QModelIndex() */ )
{
	beginRemoveRows(QModelIndex(), row, row + count -1);
	for (int i = 0; i < count; ++i)
	{
		m_addressBoxs->removeAt(row);
	}
	endRemoveRows();
	return true;
}

AddressBoxs* AddressBoxModel::GetAddressBoxs()
{
	return m_addressBoxs;
}

QVariant AddressBoxModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			if (section == NAME)
			{
				return "name";
			}
			else if (section == ADDRESS)
			{
				return "address";
			}
			else
			{
				return QVariant();
			}
		}
	}

	return QVariant();
}

bool AddressBox::operator==( const AddressBox &right )
{
	return name == right.name && address == right.address;
}
