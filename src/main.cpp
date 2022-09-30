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
