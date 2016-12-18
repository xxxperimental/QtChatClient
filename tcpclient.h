#pragma once
#include <QObject>
#include <QtNetwork>
#include <memory>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = 0);
    void connect(const QHostAddress &addr, const quint16 port);
    void write(QByteArray &data);
    QByteArray read();
    QTcpSocket* GetSocket();
private:
    std::shared_ptr<QTcpSocket> socket;
signals:

public slots:
};
