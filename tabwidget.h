#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "addressboxmodel.h"

class TabWidget : public QTabWidget
{
	Q_OBJECT

public:
	TabWidget(QWidget *parent = 0);
	~TabWidget();

	bool ReadFromFile(const QString &filePath);
	bool WriteToFile(const QString &filePath);

public slots:
	bool AddEntry();
	bool AddEntry(const AddressBox &addressBox);
	bool RemoveEntry();
	void EditEntry();

signals:
	void selectionChanged(QItemSelection);

private:
	AddressBoxModel		*m_tableModel;
	AddressBoxs			m_addressBoxs;

};

#endif // TABWIDGET_H
