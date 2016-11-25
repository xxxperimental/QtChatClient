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
    ~Dialog();

private:
    Ui::Dialog *ui;
    inline void SetValidator();
};

#endif // DIALOG_H
