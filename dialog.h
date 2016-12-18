#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    QString getUserName() const;
    QString getIP() const;
    QString getPort() const;
    void setUserName(const QString& str);
    void setIp(const QString& str);
    void setPort(const QString& str);
    ~Dialog();

private:
    Ui::Dialog *ui;
    inline void SetValidator();
};

#endif // DIALOG_H
