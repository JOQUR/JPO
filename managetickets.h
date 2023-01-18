#ifndef MANAGETICKETS_H
#define MANAGETICKETS_H
#include <QMainWindow>
#include <QtXml>

#include <vector>
#include <map>
#include "ticket.h"

class ManageTickets
{
public:
    ManageTickets();
    void addTicket(std::vector<Ticket*>& tickets, QString title, QString desc, QString severity);
    void removeUser(std::vector<Ticket*>& tickets, int id);
    void writeXML(std::vector<Ticket*>& tickets);
    void readXML(void);
    int readHighestIndex();
    //TODO:
    //void editUser(std::vector<User>& user);


private:
    int counter = 0, size = 0;
    QDomDocument document;
    QDomElement root;
};

#endif // MANAGETICKETS_H
