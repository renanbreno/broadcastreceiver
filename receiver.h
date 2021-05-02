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
    Q_PROPERTY(int messageNo READ messageNo NOTIFY messageNoChanged);
    Q_INVOKABLE void processPendingDatagrams();

public slots:
    int messageNo();
    QString message();

signals:
    void messageNoChanged();
    void messageChanged();

private:
    QUdpSocket *udpSocket = nullptr;
    QString m_message = "Nenhuma informação transmitida";
    int m_messageNo = 0;

};

#endif // RECEIVER_H
