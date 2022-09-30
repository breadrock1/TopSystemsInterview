//
// Created by Gleb Akimov on 25.09.2022.
//

#ifndef TOPSYSTEMSINTERVIEWTESTCASE_MAINWINDOW_H
#define TOPSYSTEMSINTERVIEWTESTCASE_MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QtGlobal>

QT_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QTimer *timer{};

    QList<QString> textColors {
        "red",
        "blue",
        "cadetblue",
        "chocolate",
        "darkgreen",
        "darksalmon",
        "yellow",
        "deeppink",
        "indigo"
    };

    int currentValue{};
    int successAnswers{};
    int incorrectAnswers{};
    int mouseClickCounter{};

    static int generateRandomValue();

    void clearStatisticData();
    void updateLabelsTextData(const QString &random);
    QString generateRandomStyleSheet();

public slots:
    virtual void closeEvent(QCloseEvent* event) override;

private slots:
    void onStartButtonClicked();
    void onStopButtonClicked();
    void updateLoopIteration();

    bool eventFilter(QObject *watched, QEvent *event) override;
    void onMousePressTriggered(QMouseEvent *event);

};

#endif //TOPSYSTEMSINTERVIEWTESTCASE_MAINWINDOW_H
