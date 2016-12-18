#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include "dialog.h"
#include <tcpclient.h>
#include <memory>

#define ORGAN_NAME "ggg"
#define ORGAN_DOMAIN "GGG"
#define APP_NAME "CHAT"

#define SETTINGS_IP "settings/ip"
#define SETTINGS_UN "settings/username"
#define SETTINGS_PORT "settings/port"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<TcpClient> client;
    inline void CreateMenu();
    QSettings settings;

private slots:
    void send();
    void openSettings();
    void connect();

public slots:
    void RecvData();
};

#endif // MAINWINDOW_H
