#ifndef USERPANEL_H
#define USERPANEL_H

#include "manageTickets.h"
#include "qdatetime.h"
#include <QMainWindow>
#define SEV_LVLS 4
namespace Ui {
class userpanel;
}

class userpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit userpanel(QWidget *parent = nullptr, QString login = "");
    ~userpanel();
    QDateTime date;

private slots:
    void on_ticket_btn_clicked();
    void ticketSlot(void);

private:
    Ui::userpanel *ui;
    QString severity[SEV_LVLS] = {"LOW", "MEDIUM", "HIGH", "SECURITY ISSUE"};
};

#endif // USERPANEL_H
