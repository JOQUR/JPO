#include "ticket.h"

Ticket::Ticket(QString& title, QString& desc, QString& severity, QString& date, int id)
{
    this->title = title;
    this->description = desc;
    this->severity = severity;
    this->date = date;
    this->id = id;
}

QString Ticket::getTitle(void)
{
    return this->title;
}

QString Ticket::getDescription(void)
{
    return this->description;
}
QString Ticket::getSeverity(void)
{
    return this->severity;
}
QString Ticket::getDate(void)
{
    return this->date;
}
int Ticket::getID(void)
{
    return this->id;
}

Ticket::~Ticket()
{
    delete this;
}
