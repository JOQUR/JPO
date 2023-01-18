#include "userpanel.h"
#include "qdatetime.h"
#include "ui_userpanel.h"

userpanel::userpanel(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::userpanel)
{
    ui->setupUi(this);
    ui->user->setText("User: " + login);
    ui->user->adjustSize();
    connect(ui->ticket_btn, SIGNAL(clicked()), this, SLOT(ticketSlot()));
    for(int i = 0; i < SEV_LVLS; ++i){
        ui->severity->addItem(severity[i]);
    }
}

userpanel::~userpanel()
{
    delete ui;
}

void userpanel::ticketSlot(void)
{
    date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    qDebug() <<"Actual Date: " <<  formattedTime;
    mant.addTicket(tickets, ui->title->text(), ui->descript->toPlainText(), ui->severity->currentText());
    mant.writeXML(tickets);
    this->close();
}

void userpanel::on_ticket_btn_clicked()
{

}

