#include "reader.h"

const QString Reader::AT_SIGNALS = "AT+SIGNALS=?";

const QString Reader::AT_SIGNAL = "AT+SIGNAL";
const QString Reader::AT_CURR = "AT+CURR";

const QString Reader::AT_START = "AT+START";
const QString Reader::AT_STOP = "AT+STOP";

const QString Reader::AT_MAX = "AT+MAX";

const QString Reader::AT_MIN = "AT+MIN";



Reader::Reader(QObject *parent) : QObject{parent}
{

    setup_port();

}

void Reader::getSignals()
{
    // Convert the string to a QByteArray
    QByteArray signal = AT_SIGNALS.toLatin1();
    writeData(signal);

}



void Reader::setSignal(QString signal)
{
     QByteArray signalfinal = (AT_SIGNAL + "="+ signal).toLatin1();
     writeData(signalfinal);
}

bool Reader::isOpenPort()
{
    return port.isOpen();
}

void Reader::writeData(QByteArray &data)
{

    if(isOpenPort()){

        QByteArray signal = data;

        // Write the data to the serial port
        qint64 bytesWritten = port.write(signal);

        if (bytesWritten != signal.size())
        {
            qDebug() << "Data has not been written!!";
            throw std::exception();
        }

    }else{
        qDebug() << "port is not open";
        throw std::exception();
    }

}

void Reader::setup_port()
{
    port.setPortName("COM1");
    port.setBaudRate(QSerialPort::Baud115200);
    port.setParity(QSerialPort::NoParity);
    port.setStopBits(QSerialPort::TwoStop);
    port.open(QSerialPort::ReadWrite);

}

void Reader::start()
{

    QByteArray signal = AT_START.toLatin1();
    writeData(signal);

}

void Reader::stop()
{

    QByteArray signal = AT_STOP.toLatin1();
    writeData(signal);
}

void Reader::currentSignal()
{
     QByteArray signal = AT_CURR.toLatin1();
     writeData(signal);
}
