#ifndef QWIDGETINTERFACE_H
#define QWIDGETINTERFACE_H

#include "reader.h"
#include <QObject>

class QWidgetInterface : public Reader
{
    Q_OBJECT
public:
    explicit QWidgetInterface(QObject *parent = nullptr);
    QStringList getListButtons() const;

private slots:
    void readData();

signals:
    void enviaDatoRecibido(QString &dato);

private:
    QStringList stringListButtons;
    QString datoRecibido;

};

#endif // QWIDGETINTERFACE_H
