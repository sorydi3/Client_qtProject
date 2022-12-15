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
    connect(ui->min,SIGNAL(clicked()),this,SLOT(buttonSlot()));
    connect(ui->max,SIGNAL(clicked()),this,SLOT(buttonSlot()));
    connect(&widgetreader,SIGNAL(enviaDatoRecibido(QString&)),this,SLOT(response(QString&)));
    widgetreader.getSignals();


    response_label.setParent(ui->centralwidget);
    response_label.setGeometry(QRect(600,500,120,50));
    _graph = new Graph(ui->mainWidget,height(),width());

}

MainWindow::~MainWindow()
{
    widgetreader.stop();
    delete ui;
    delete _graph;
}

void MainWindow::generateSignalsButtons()
{
    QStringList arrayStringButton = widgetreader.getListButtons();

    for (int i = 0; i < arrayStringButton.size(); ++i) {
        QPushButton* button = new QPushButton(QString(arrayStringButton[i].split("+")[1]),ui->centralwidget);
        button->setObjectName(QString(arrayStringButton[i].split("+")[1]));
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
    connect(&widgetreader,SIGNAL(enviaDatoRecibido(QString&)),_graph,SLOT(agregarDato(QString&)));
}

void MainWindow::buttonSlot()
{
    QString senderName = this->sender()->objectName();
    response_label.setText("");
    qDebug() << "the name of the sender is::> " << senderName;
    if(senderName=="RAND" || senderName=="TRIANGULAR" || senderName=="SINE" || senderName=="SQUARE"){
        widgetreader.setSignal(senderName);
    }


    if(senderName.contains("start")){
        widgetreader.start();

    }

    if(senderName.contains("stop")){

        widgetreader.stop();
    }

    if(senderName.contains("current")){
        widgetreader.currentSignal();
    }

    if(senderName.contains("min")){
        widgetreader.minimum();
    }

    if(senderName.contains("max")){
         widgetreader.maximun();
    }
}

void MainWindow::response(QString &strResponse)
{

    response_label.setText(strResponse);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    /*
    QSize size = event->size();

    int h = size.height();
    int w = size.width();



    qDebug() <<"max size h: "<<h <<"  max size width w:"<<w;

    //_graph->resize(size);

    QRect rect(w-100,100,80,40);

    qDebug() << ui->mainWidget->size() << " <----widgett";

    qDebug("new size of init button");
    qDebug() << rect;

    QRect rectw(w-100,100,80,40);

    //ui->mainWidget-set


    ui->verticalLayout->setGeometry(rect);

    QRect rectw(w-100,100,80,40);

    ui->verticalLayout->raise();


    //ui->verticalLayout->s
    */

}

