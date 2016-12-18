#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpclient.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
     settings(ORGAN_NAME, APP_NAME)
{
    ui->setupUi(this);
    CreateMenu();

   QObject::connect(ui->btnSend, SIGNAL(clicked()), this, SLOT(send()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSettings()
{
    Dialog *pDialog = new Dialog;

    pDialog->setUserName(settings.value(SETTINGS_UN).toString());
    pDialog->setIp(settings.value(SETTINGS_IP).toString());
    pDialog->setPort(settings.value(SETTINGS_PORT).toString());

    if(pDialog->exec() == QDialog::Accepted) {
        settings.setValue(SETTINGS_IP, pDialog->getIP());
        settings.setValue(SETTINGS_UN, pDialog->getUserName());
        settings.setValue(SETTINGS_PORT, pDialog->getPort());
        settings.sync();

        QMessageBox::information(0, "Settings", "Saved configuration");
    }
}

void MainWindow::connect()
{
    this->client = std::unique_ptr<TcpClient>(new TcpClient(this));
    client->connect(QHostAddress(settings.value(SETTINGS_IP).toString()),
                   settings.value(SETTINGS_PORT).toInt());
    QObject::connect(client->GetSocket(), SIGNAL(readyRead()), this, SLOT(RecvData()));
    ui->txtOutput->append("Connected to " +
                          settings.value(SETTINGS_IP).toString() +
                          ":" +
                          settings.value(SETTINGS_PORT).toString());
}

void MainWindow::RecvData()
{
    QString data(this->client->read());
    ui->txtOutput->append("<- : " + data);
}

void MainWindow::send()
{
    QString sendData = ui->txtInput->toPlainText();
    ui->txtInput->setText("");
    ui->txtOutput->append("-> : " + sendData);
    QByteArray array (sendData.toStdString().c_str());
    client->write(array);
}

void MainWindow::CreateMenu()
{
    auto actSettings = new QAction("Settings", this);
    auto actConnect = new QAction("Connect", this);
    ui->menuBar->addAction(actConnect);
    ui->menuBar->addAction(actSettings);
    QObject::connect(actConnect, SIGNAL(triggered()), this, SLOT(connect()));
    QObject::connect(actSettings, SIGNAL(triggered()), this, SLOT(openSettings()));
}
