#include <QtNetwork>
#include "receiver.h"

Receiver::Receiver()
{
    udpSocket = new QUdpSocket();
    udpSocket->bind(45454, QUdpSocket::ShareAddress);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

void Receiver::processPendingDatagrams()
{
    QByteArray datagram;
    while (udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size());
        m_message = datagram.data();

        ++m_messageNo;
        emit messageChanged();
        emit messageNoChanged();
    }
}

int Receiver::messageNo()
{
    return m_messageNo;
}

QString Receiver::message()
{
    return m_message;
}
