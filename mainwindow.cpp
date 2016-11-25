#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateMenu();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSettings()
{
    Dialog *pDialog = new Dialog;
    if(pDialog->exec() == QDialog::Accepted){
        QSettings settings(ORGAN_NAME, APP_NAME);

        settings.setValue(SETTINGS_IP, pDialog->getIP());
        settings.setValue(SETTINGS_UN, pDialog->getUserName());
        settings.sync();

        QMessageBox::information(0, "Settings", "Saved configuration");
    }
}

void MainWindow::CreateMenu()
{
    auto actSettings = new QAction("Settings", this);
    ui->menuBar->addAction(actSettings);
    connect(actSettings, SIGNAL(triggered()), this, SLOT(openSettings()));
}
