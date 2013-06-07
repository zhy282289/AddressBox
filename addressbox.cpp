#include "stdafx.h"
#include "addressbox.h"

#include "tabwidget.h"

AddressBoxMain::AddressBoxMain(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	m_centralWidget = new TabWidget;
	setCentralWidget(m_centralWidget);
	CreateMenu();


	setWindowTitle("Address Box");
	resize(800, 600);
}

AddressBoxMain::~AddressBoxMain()
{

}

void AddressBoxMain::CreateMenu()
{

	m_fileMenu = menuBar()->addMenu("&File");

	m_editMenu = menuBar()->addMenu("&Edit");
	m_addEntry = new QAction("add", this);
	m_removeEntry = new QAction("remove", this);
	m_editEntry = new QAction("edit", this);


	m_editMenu->addAction(m_addEntry);
	m_editMenu->addAction(m_removeEntry);
	m_editMenu->addAction(m_editEntry);


	m_toolBar = addToolBar("boy");

	m_toolBar->addAction(m_addEntry);
	m_toolBar->addAction(m_removeEntry);
	m_toolBar->addAction(m_editEntry);


	connect(m_addEntry, SIGNAL(triggered()), m_centralWidget, SLOT(AddEntry()));
	connect(m_removeEntry, SIGNAL(triggered()), m_centralWidget, SLOT(RemoveEntry()));
	connect(m_editEntry, SIGNAL(triggered()), m_centralWidget, SLOT(EditEntry()));



}
