#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //definicoes painel web

    QString path = QCoreApplication::applicationDirPath() + "/";
    QSettings settings(path+"settings.ini", QSettings::IniFormat);

    QString webhost = settings.value("host").toString();
    QString webtoken = settings.value("token").toString();

    ui->lineEdit->setText(webhost);
    ui->lineEdit_2->setText(webtoken);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString path = QCoreApplication::applicationDirPath() + "/";
    QSettings settings(path+"settings.ini", QSettings::IniFormat);

    QString nohttp = ui->lineEdit->text().remove("http://");
    settings.setValue("host",nohttp);
    settings.setValue("token", ui->lineEdit_2->text());
    QMessageBox::information(this,"Sucesso","Definições guardadas com sucesso!");
    this->close();

}
