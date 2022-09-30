/**
 * @mainpage TopSystems Interview project Documentation.
 * @section intro_sec Introduction
 * So, there is simple project to demonstrate my C/C++ skills while processing interview.
 * There is no clear code because i was writing it for about a one hour. I just wanna save
 * it here to dilute program languages statistic of my account.
 *
 * @section install_sec Installation
 * Just buid CMakeList.txt file.
 */

#include <QApplication>

#include "ui/mainwindow.h"


static void onSignalRecv(int sig)
{
    if (sig == SIGINT || sig == SIGTERM) {
        qApp->quit();
    } else {
        qWarning("Unhandled signal %d", sig);
    }
}

void setupApplication(QApplication &application)
{
    signal(SIGINT, onSignalRecv);
    signal(SIGTERM, onSignalRecv);

    QApplication::setApplicationName(QString("TopSystems test case"));
    QApplication::setApplicationDisplayName(QString("TopSystems test case"));
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    setupApplication(application);

    MainWindow mainWindow;
    mainWindow.show();

    return QApplication::exec();
}
