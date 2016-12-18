#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    SetValidator();
}

void Dialog::setUserName(const QString& str)
{
    this->ui->leUserName->setText(str);
}

void Dialog::setIp(const QString& str)
{
    this->ui->leIp->setText(str);
}

void Dialog::setPort(const QString& str)
{
    this->ui->lePort->setText(str);
}

QString Dialog::getUserName() const
{
    return ui->leUserName->text();
}

QString Dialog::getIP() const
{
    return ui->leIp->text();
}

QString Dialog::getPort() const
{
    return ui->lePort->text();
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::SetValidator()
{
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";

    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");

    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);

    ui->leIp->setValidator(ipValidator);
}
