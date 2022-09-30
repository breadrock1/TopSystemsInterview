//
// Created by Gleb Akimov on 25.09.2022.
//

#include <QMouseEvent>
#include <QPushButton>
#include <QRandomGenerator>
#include <QString>
#include <QTextFormat>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        timer(new QTimer(this)),
        currentValue(0),
        successAnswers(0),
        incorrectAnswers(0),
        mouseClickCounter(0)
{
    ui->setupUi(this);
    this->centralWidget()->setMouseTracking(true);
    this->centralWidget()->installEventFilter(this);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(updateLoopIteration()));
    connect(ui->startPushButton, &QPushButton::clicked,
            this, &MainWindow::onStartButtonClicked);
    connect(ui->stopPushButton, &QPushButton::clicked,
            this, &MainWindow::onStopButtonClicked);
}

MainWindow::~MainWindow() noexcept
{
    delete ui;
}


void MainWindow::clearStatisticData()
{
    currentValue = 0;
    successAnswers = 0;
    incorrectAnswers = 0;
    mouseClickCounter = 0;
}

int MainWindow::generateRandomValue()
{
    return QRandomGenerator::global()->bounded(1, 4);
}

QString MainWindow::generateRandomStyleSheet() {
    QString qmlLabelAttrs = QString("QLabel { ")
            .append("background-color : %1; ")
            .append("color : white; ")
            .append("height : 20; ")
            .append("width : 20; ")
            .append("}");

    QString randomColor = MainWindow::textColors.at(generateRandomValue());
    return QString(qmlLabelAttrs).arg(randomColor);
}

void MainWindow::updateLabelsTextData(const QString &random)
{
    ui->randomNumberLabel->setText(random);
    QString styleSheet = generateRandomStyleSheet();
    ui->randomNumberLabel->setStyleSheet(styleSheet);

    ui->successLabel->setText("Success answers: " + QString::number(successAnswers));
    ui->incorrectLabel->setText("Incorrect answers: " + QString::number(incorrectAnswers));
}

void MainWindow::updateLoopIteration()
{
    currentValue = MainWindow::generateRandomValue();
    if (mouseClickCounter == currentValue)
    {
        successAnswers++;
    }

    else
    {
        incorrectAnswers++;
    }

    mouseClickCounter = 0;
    updateLabelsTextData(QString::number(currentValue));
}


void MainWindow::onStartButtonClicked()
{
    clearStatisticData();

    currentValue = MainWindow::generateRandomValue();
    updateLabelsTextData(QString::number(currentValue));

    timer->start(2000);
}

void MainWindow::onStopButtonClicked()
{
    if (timer->isActive())
    {
        timer->stop();
    }

    updateLabelsTextData("");
}


void MainWindow::closeEvent(QCloseEvent* event)
{
    onStopButtonClicked();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonRelease)
    {
        onMousePressTriggered((QMouseEvent *) event);
    }

    return false;
}

void MainWindow::onMousePressTriggered(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouseClickCounter++;
        if (mouseClickCounter > currentValue)
        {
            incorrectAnswers++;
        }
    }
}
