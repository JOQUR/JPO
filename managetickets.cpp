#include "managetickets.h"

ManageTickets::ManageTickets()
{
    size = readHighestIndex();
}

void ManageTickets::addTicket(std::vector<Ticket*>& tickets, QString title, QString desc, QString severity)
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm");
    tickets.push_back(new Ticket(title, desc, severity, formattedTime, this->counter++));
}



void ManageTickets::writeXML(std::vector<Ticket*>& tickets)
{
    QDomElement node;
    QFile file("D:/jpo-projekt/QuickFix/tickets.xml");
    if(!file.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
        qDebug () << "Error saving XML file....";
        file.close();
    }

    document.setContent(&file);
    root = document.documentElement();
    file.close();
    for(int i = 0; i < (int)tickets.size(); ++i){

        node = document.createElement("Tickets");
        node.setAttribute("Title", tickets[i]->getTitle());
        node.setAttribute("Description", tickets[i]->getDescription());
        node.setAttribute("Severity", tickets[i]->getSeverity());
        node.setAttribute("Date", tickets[i]->getDate());
        node.setAttribute("ID", size++);
        root.appendChild(node);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream output(&file);
        output << document.toString();
        file.close();
    }
}


int ManageTickets::readHighestIndex()
{
    QDomDocument document;

    QFile file("D:/jpo-projekt/QuickFix/tickets.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "Failed to open File";
    }
    else {
        if(!document.setContent(&file)){
            qDebug() << "Failed to load document";
        }
        file.close();
    }
    return document.lastChildElement().childNodes().size();
}
