#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

#include "addressboxmodel.h"

class AddDialog : public QDialog
{
	Q_OBJECT

public:
	AddDialog(QWidget *parent);
	~AddDialog();

	bool DoModal();
	void SetData(const AddressBox &addressBox);
	

	AddressBox	addressBox;
private slots:
	void Done(bool f);

public:
	QPushButton *m_okBtn;
	QLineEdit	*m_nameLineEdit;
	QTextEdit	*m_addressTextEdit;
};

#endif // ADDDIALOG_H
