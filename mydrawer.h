#ifndef MYDRAWER_H
#define MYDRAWER_H

#include <QObject>
#include <QtOpenGLWidgets/QtOpenGLWidgets>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>

class MyDrawer :
{
    Q_OBJECT
public:
    explicit MyDrawer(QObject *parent = nullptr);

signals:

};

#endif // MYDRAWER_H
