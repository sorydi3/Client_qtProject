#include "qwidgetinterface.h"

QWidgetInterface::QWidgetInterface(QObject *parent)
    : Reader{parent}
{


    connect(&port,SIGNAL(readyRead()),this,SLOT(readData()));
}

QStringList QWidgetInterface::getListButtons() const
{
    return stringListButtons;
}



void QWidgetInterface::readData()
{

    // Create a QByteArray to store the read data

    datoRecibido="";

    QByteArray byteArray = port.readAll();
    QString str = QString::fromUtf8(byteArray);
    if(stringListButtons.empty() && !str.contains("VALUE")){
        stringListButtons = str.split("\r\n");
        stringListButtons.removeLast();
        for (int var = 0; var < stringListButtons.size(); ++var) {
            qDebug() << stringListButtons[var];
        }
    }else{
        datoRecibido = str;
        emit enviaDatoRecibido(datoRecibido);
    }

}
