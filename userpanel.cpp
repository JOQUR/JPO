#include "userpanel.h"
#include "ui_userpanel.h"

userpanel::userpanel(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::userpanel)
{
    ui->setupUi(this);
    ui->user->setText("User: " + login);
    ui->user->adjustSize();
    ui->curr_date->setText("Today's date: " + ui->calendarWidget->selectedDate().toString("dd/MM/yy"));
    ui->curr_date->adjustSize();
}

userpanel::~userpanel()
{
    delete ui;
}
