#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpclient.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings(ORGAN_NAME, APP_NAME);
    CreateMenu();
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
}

void MainWindow::send()
{
    QString sendData = ui->txtInput->toPlainText();
    QByteArray array (sendData.toStdString().c_str());
    client->write(array);
}

void MainWindow::CreateMenu()
{
    auto actSettings = new QAction("Settings", this);
    auto actConnect = new QAction("Connect", this);
    ui->menuBar->addAction(actConnect);
    ui->menuBar->addAction(actSettings);
    connect(actConnect, SIGNAL(triggered()), this, SLOT(connect()));
    connect(actSettings, SIGNAL(triggered()), this, SLOT(openSettings()));
}
