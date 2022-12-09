#ifndef READER_H
#define READER_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>


class Reader : public  QObject
{
    Q_OBJECT

public: //for static variables
    const static QString AT_SIGNALS;
    const static QString AT_SIGNAL;
    const static QString AT_CURR;
    const static QString AT_START;
    const static QString AT_STOP;
    const static QString AT_MAX;
    const static QString AT_MIN;




public:

    Reader(QObject *parent = nullptr);
    void setup_port();
    void start();
    void stop();
    void currentSignal();
    void getSignals();
    void setSignal(QString signal);
    void setMaximun(float max);
    void setMinimum(float min);
private:
    bool isOpenPort();
    void writeData(QByteArray & data );

protected:
    QSerialPort port;


};



#endif // READER_H


