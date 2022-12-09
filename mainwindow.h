#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qwidgetinterface.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

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
    QLabel response;
    QWidgetInterface widgetreader;
    QVBoxLayout layout;
    QList<QPushButton*> buttons;

};
#endif // MAINWINDOW_H
