#include "stdafx.h"
#include "addressbox.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AddressBoxMain w;
	w.showMaximized();
	return a.exec();
}
