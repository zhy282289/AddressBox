#ifndef ADDRESSBOX_H
#define ADDRESSBOX_H

#include <QtGui/QMainWindow>



class TabWidget;
class AddressBoxMain : public QMainWindow
{
	Q_OBJECT

public:
	AddressBoxMain(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AddressBoxMain();

private:

	void	CreateMenu();

private:

	QMenu		*m_fileMenu;
	QMenu		*m_editMenu;

	QAction		*m_addEntry;
	QAction		*m_removeEntry;
	QAction		*m_editEntry;

	QToolBar	*m_toolBar;
	TabWidget	*m_centralWidget;
};

#endif // ADDRESSBOX_H
