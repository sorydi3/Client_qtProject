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

     qDebug() << "data is available!!!!";
     /**
    while(port.bytesAvailable()){
        QByteArray data;
        // Read data from the serial port
        qint64 read =  port.read((char*)&data,sizeof(data));

        QString str = QString::number(read);
        qDebug() << str;
    }
    */

     datoRecibido="";

     QByteArray byteArray = port.readAll();
     QString str = QString::fromUtf8(byteArray);
     if(stringListButtons.empty()){
         stringListButtons = str.split("\r\n");
         for (int var = 0; var < stringListButtons.size(); ++var) {
            qDebug() << stringListButtons[var];
         }
     }else{
        datoRecibido = str;
        emit enviaDatoRecibido(datoRecibido);
     }

}
