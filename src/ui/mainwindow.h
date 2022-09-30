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

/**
 * @brief MainWindow class realises main window GUI.
 */
class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    /**
     * Create a new MainWindow object.
     * @brief Default constructor.
     * @see MainWindow(QWidget *parent = 0).
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * Destruct the current MainWindow object.
     * @brief Default desructor.
     */
    ~MainWindow() override;

private:
    /**
     * @brief The UI object of mainwindow.ui file.
     */
    Ui::MainWindow *ui;

    /**
     * @brief The time object to iterates over processing loop each 2 seconds.
     */
    QTimer *timer{};

    /**
     * @brief The list of color names to add to style sheet by index.
     */
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

    /**
     * @brief The current integer number to need click.
     */
    int currentValue{};

    /**
     * @brief The amount value of success user answers.
     */
    int successAnswers{};

    /**
     * @brief The amount value of incorrect user answers.
     */
    int incorrectAnswers{};

    /**
     * @brief The mouse click amount for current loop iteration.
     */
    int mouseClickCounter{};

    /**
     * @brief Generates random integer value int range 0 - 5.
     * @return A generated random int value.
     */
    static int generateRandomValue();

    /**
     * @brief Clears all int attributes when start button triggered again.
     */
    void clearStatisticData();

    /**
     * @brief Updates all labels text data.
     * @param random the current generated random int value.
     */
    void updateLabelsTextData(const QString &random);

    /**
     * @brief Generates style sheet for random int value label.
     * @return generated style sheet string value.
     */
    QString generateRandomStyleSheet();

public slots:
    /**
     * @brief Closes current window and application by event.
     * @param event The triggered close event.
     */
    void closeEvent(QCloseEvent* event) override;

private slots:
    /**
     * @brief Launches loop iteration (QTimer).
     */
    void onStartButtonClicked();

    /**
     * @brief Terminates loop iteration (QTimer).
     */
    void onStopButtonClicked();

    /**
     * @brief Launches new loop iteration and check user answer (QTimer).
     */
    void updateLoopIteration();

    /**
     * @brief Filtering event to check mouse event (QTimer).
     * @param watched The watched object.
     * @param event The current triggered event.
     * @return The true/false result value.
     */
    bool eventFilter(QObject *watched, QEvent *event) override;

    /**
     * @brief Executes counting mouse clicking by event.
     * @param event The current triggered event.
     */
    void onMousePressTriggered(QMouseEvent *event);

};

#endif //TOPSYSTEMSINTERVIEWTESTCASE_MAINWINDOW_H
