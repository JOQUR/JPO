#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->login, SIGNAL(clicked()), this, SLOT(loginSlot()));
    ui->pass_in->setEchoMode(QLineEdit::Password);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_login_clicked()
{

}


void LoginWindow::loginSlot(void)
{
    QString login = ui->login_in->text();
    QString password = ui->pass_in->text();
    if(isUser(login, password)){
        AdminPanel* admin = new AdminPanel(this);
        admin->show();
    }
    else{
        qDebug() << "Wrong Input";
    }
}


int LoginWindow::isUser(QString& login, QString& pass)
{
    if((login == "admin") && (pass == "admin")){
        ui->login_in->setText("");
        ui->pass_in->setText("");
        return 1;
    }
    else if((pass == man.readCredentials(login, "Password")) && (man.readCredentials(login, "Role") == "Admin")){
        ui->login_in->setText("");
        ui->pass_in->setText("");
        return 1;
    }
    else{
        return 0;
    }
}
