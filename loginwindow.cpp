#include "loginwindow.h"
#include "staffpanel.h"
#include "ui_loginwindow.h"
#include "userpanel.h"

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
    if(isUser(login, password, "Admin")){
        AdminPanel* admin = new AdminPanel(this);
        admin->show();
    }
    else if(isUser(login, password, "Student")){
        userpanel* usr = new userpanel(this, login);
        usr->show();
    }
    else if(isUser(login, password, "Staff")){
        StaffPanel* staff = new StaffPanel();
        staff->show();
    }
    else{
        qDebug() << "Wrong Input";
    }
}


int LoginWindow::isUser(QString& login, QString& pass, QString role)
{
    if((login == "admin") && (pass == "admin")){
        ui->login_in->setText("");
        ui->pass_in->setText("");
        return 1;
    }
    else if((pass == man.readCredentials(login, "Password")) && (man.readCredentials(login, "Role") == role)){
        ui->login_in->setText("");
        ui->pass_in->setText("");
        return 1;
    }
    else{
        return 0;
    }
}
