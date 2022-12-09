#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->init,SIGNAL(clicked()),this,SLOT(generateButtons()));
    connect(ui->current,SIGNAL(clicked()),this,SLOT(buttonSlot()));
    connect(ui->start,SIGNAL(clicked()),this,SLOT(buttonSlot()));
    connect(ui->stop,SIGNAL(clicked()),this,SLOT(buttonSlot()));
    connect(&widgetreader,SIGNAL(enviaDatoRecibido(QString&)),this,SLOT(response(QString&)));
    widgetreader.getSignals();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateSignalsButtons()
{
    QStringList arrayStringButton = widgetreader.getListButtons();

    for (int i = 0; i < arrayStringButton.size(); ++i) {
      QPushButton* button = new QPushButton(QString(arrayStringButton[i]),ui->centralwidget);
      button->setObjectName(QString(arrayStringButton[i]));
      button->setVisible(true);
      button->setGeometry(QRect(10,50*(i+1),100,50));
      connect(button,SIGNAL(clicked()),this,SLOT(buttonSlot()));
    }

    foreach (QPushButton* button, buttons) {
      layout.addWidget(button);
    }
}

void MainWindow::generateButtons()
{
    generateSignalsButtons();
}

void MainWindow::buttonSlot()
{
  QString senderName = this->sender()->objectName();
    qDebug() << "the name of the sender is::> " << senderName;
    if(senderName=="AT+RAND" || senderName=="AT+TRIANGULAR" || senderName=="AT+SINE" || senderName=="AT+SQUARE")
        widgetreader.setSignal(senderName.split("+")[1]);


    if(senderName.contains("Start")){

    }

    if(senderName.contains("Stop")){

    }

    if(senderName.contains("current")){
        widgetreader.currentSignal();
    }



    /*
    if(senderName.contains("AT+RAND")){
        widgetreader.setSignal()
    }

    if(senderName.contains("AT+TRIANGULAR")){

    }

    if(senderName.contains("AT+SINE")){

    }

    if(senderName.contains("AT+SQUARE")){

    }
    */
}

void MainWindow::response(QString &strResponse)
{
    qDebug() << "response sent "<< strResponse;
}

