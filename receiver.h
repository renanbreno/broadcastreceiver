#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>


QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

class Receiver : public QObject
{
    Q_OBJECT
public:
    Receiver();
    Q_PROPERTY(QString message READ message NOTIFY messageChanged);
    Q_INVOKABLE void processPendingDatagrams();

public slots:
    QString message();

signals:
    void messageChanged();

private:
    QUdpSocket *udpSocket = nullptr;
    QString m_message = "Nenhuma informação transmitida";

};

#endif // RECEIVER_H
