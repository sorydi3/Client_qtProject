#include "graph.h"

Graph::Graph(QWidget *parent,int height,int width) : QOpenGLWidget(parent)
{
    //QWidget::setGeometry(QRect(110,40,width-110,height));
    background = QColor("#e6f7ff");
    signalColor = QColor("#073ab0");
    zoom = 100.0;

}

void Graph::addData(const float &data)
{

    while(signal.size() > width()){
        signal.removeFirst();
    }
    signal.append(data);
    update();

}

void Graph::clearSignal()
{
    signal.clear();
}

void Graph::setParentWidgett(QWidget &widget)
{

}



void Graph::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF()); // color que se queda cuando se borra la pantalla

}

void Graph::resizeGL(int w, int h)
{

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0f,w*1.0f,0.0f,h*1.0f,-1.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Graph::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor3f(signalColor.redF(),background.greenF(),signalColor.blueF());
    glLineWidth(2.0f);

    for (int i = 0; i < signal.size()-1; ++i) {
        glVertex3f(i*1.0f,signal[i]*zoom*1.0,0.0f);
        glVertex3f((i+1)*1.0f,signal[i+1]*zoom*1.0,0.0f);
    }

    glEnd();
    glPopMatrix();

    glFlush();

}

void Graph::agregarDato(QString &dato)
{


    if(dato.contains("VALUE")){
        QString dato_aux =  dato.split("\r\n")[0].split("=")[1];
        float value = dato_aux.toFloat();
        addData(value);
    }
}


void Graph::wheelEvent(QWheelEvent *event)
{


    if(!event->angleDelta().isNull()){

        if(event->angleDelta().y()>0){

            zoom+=10;

        }else{

            zoom-=10;

        }

    }

    update();
}

void Graph::resizeEvent(QResizeEvent *event)
{

    qDebug("size even called!!");
    QSize newSize = event->size();



    setGeometry(QRect(110,40,newSize.width()-100,newSize.height()-100));

}


