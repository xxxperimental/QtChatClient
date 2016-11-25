#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include "dialog.h"

#define ORGAN_NAME "ggg"
#define ORGAN_DOMAIN "GGG"
#define APP_NAME "CHAT"

#define SETTINGS_IP "settings/ip"
#define SETTINGS_UN "settings/username"

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

    inline void CreateMenu();
private slots:
    void openSettings();
};

#endif // MAINWINDOW_H
