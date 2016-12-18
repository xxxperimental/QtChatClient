#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{

}
void TcpClient::connect(const QHostAddress &addr, const quint16 port)
{
    this->socket = std::shared_ptr<QTcpSocket>(new QTcpSocket(this));
    socket->connectToHost(addr, port);
    socket->waitForConnected();
}

void TcpClient::write(QByteArray &data)
{
    socket->write(data);
}

QByteArray TcpClient::read()
{
    return socket->readAll();
}

QTcpSocket* TcpClient::GetSocket()
{
    return this->socket.get();
}
