#ifndef GRAPH_H
#define GRAPH_H

#include <QtOpenGLWidgets>
#include <QObject>
#include <QOpenGLFunctions_1_1>
#include <QEvent>
#include <QWheelEvent>
#include "qwidgetinterface.h"
#include <QWidget>

class Graph : public QOpenGLWidget,protected QOpenGLFunctions_1_1

{
    Q_OBJECT
public:
    Graph(QWidget *parent=0,int height=0,int width=0);
    void addData(const float &data);
    void clearSignal();
    void setParentWidgett(QWidget & widget);

    // QOpenGLWidget interface+
private slots:
    void agregarDato(QString &datos);


protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QColor signalColor,background;
    int zoom;
    QVector<float> signal;
    QWidget *parent;

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event) override;


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // GRAPH_H
