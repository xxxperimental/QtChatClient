#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGAN_NAME);
    QCoreApplication::setOrganizationDomain(ORGAN_DOMAIN);
    QCoreApplication::setApplicationName(APP_NAME);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
