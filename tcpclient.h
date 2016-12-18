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
private:
    std::unique_ptr<QTcpSocket> socket;
signals:

public slots:
};
