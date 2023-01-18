#ifndef TICKET_H
#define TICKET_H
#include "qdatetime.h"
#include <iostream>
#include <QMainWindow>


class Ticket
{
public:
    Ticket(QString& title, QString& desc, QString& severity, QString& Date, int id);
    ~Ticket();
    QString getTitle();
    QString getDescription();
    QString getSeverity();
    QString getDate();
    int getID();


private:
    QString title;
    QString description;
    QString severity;
    QString date;
    int id;
};

#endif // TICKET_H
