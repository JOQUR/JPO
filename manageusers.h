#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H


#include <iostream>
#include <QMainWindow>
#include <QtXml>

#include <vector>
#include <map>
#include "user.h"

class ManageUsers
{
public:
    ManageUsers();
    void addUser(std::vector<User*>& user, QString fullName, QString login, QString pass, QString role);
    void removeUser(std::vector<User*>& user, int id);
    void writeXML(std::vector<User*>& user);
    void readXML(void);
    QString readCredentials(QString login, QString attr);
    //TODO:
    //void editUser(std::vector<User>& user);


private:
    QDomElement itemele;
    std::vector<QDomElement> xml_elements;
    QDomDocument document;
    QDomElement root;
    QString ListElements(QDomElement root, QString tagname, QString attribute);
    int counter = 0;
};

#endif // MANAGEUSERS_H
