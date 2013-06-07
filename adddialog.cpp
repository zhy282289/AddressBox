#include "stdafx.h"
#include "adddialog.h"




AddDialog::AddDialog(QWidget *parent)
	: QDialog(parent)
{
	m_okBtn = new QPushButton("ok");
	m_okBtn->setFixedWidth(72);
	connect(m_okBtn, SIGNAL(clicked(bool)), this, SLOT(Done(bool)));

	QLabel *nameLabel = new QLabel("name:");
	QLabel *addressLabel = new QLabel("name:");
	m_nameLineEdit = new QLineEdit;
	m_addressTextEdit = new QTextEdit;


	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(nameLabel, 0, 0);
	mainLayout->addWidget(m_nameLineEdit, 0, 1);

	mainLayout->addWidget(addressLabel, 1, 0);
	mainLayout->addWidget(m_addressTextEdit, 1, 1);
	mainLayout->addWidget(m_okBtn, 2, 1, 1, 1, Qt::AlignRight);

	mainLayout->setColumnStretch(1,1);
	mainLayout->setRowStretch(1,1);
	
	setLayout(mainLayout);

}

AddDialog::~AddDialog()
{

}

bool AddDialog::DoModal()
{
	bool ret = exec();
	if (ret)
	{
		addressBox.name = m_nameLineEdit->text();
		addressBox.address = m_addressTextEdit->toPlainText();
	}
	return ret;
}

void AddDialog::SetData( const AddressBox &addressBox )
{
	m_nameLineEdit->setText(addressBox.name);
	m_addressTextEdit->setPlainText(addressBox.address);
}

void AddDialog::Done( bool f )
{
	done(1);
}
