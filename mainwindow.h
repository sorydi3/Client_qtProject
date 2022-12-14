#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qwidgetinterface.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generateSignalsButtons();

private slots:
    void generateButtons();
    void buttonSlot();
    void response(QString &strResponse);

private:
    Ui::MainWindow *ui;
    QLabel response_label;
    QWidgetInterface widgetreader;
    QVBoxLayout layout;
    QList<QPushButton*> buttons;
    Graph * _graph;

};
#endif // MAINWINDOW_H
