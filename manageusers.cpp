#include "manageusers.h"




ManageUsers::ManageUsers()
{
    size = readHighestIndex();
}


void ManageUsers::addUser(std::vector<User*>& user, QString fullName, QString login, QString pass, QString role)
{

    user.push_back(new User(fullName, login, pass, role, this->counter++));
}

void ManageUsers::removeUser(std::vector<User*>& user, int id)
{
    for(int i = 0; i < (int)user.size(); ++i){
        if(user[i]->getID() == id){
            user.erase(user.begin() + i);
        }
    }
}


void ManageUsers::writeXML(std::vector<User*>& user)
{
    QDomElement node;
    QFile file("D:/jpo-projekt/QuickFix/example.xml");
    if(!file.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
        qDebug () << "Error saving XML file....";
        file.close();
    }

    document.setContent(&file);
    root = document.documentElement();
    file.close();
    for(int i = 0; i < (int)user.size(); ++i){

        node = document.createElement(user[i]->getLogin());
        node.setAttribute("Role", user[i]->getRole());
        node.setAttribute("Password", user[i]->getPass());
        node.setAttribute("FullName", user[i]->getFullName());
        node.setAttribute("ID", size++);
        root.appendChild(node);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream output(&file);
        output << document.toString();
        file.close();
    }
    readXML();
}

void ManageUsers::readXML(void)
{
    QDomDocument document;

    QFile file("D:/jpo-projekt/QuickFix/example.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "Failed to open File";
    }
    else {
        if(!document.setContent(&file)){
            qDebug() << "Failed to load document";
        }
        file.close();
    }
    QDomElement root = document.firstChildElement();

}

int ManageUsers::readHighestIndex()
{
    QDomDocument document;

    QFile file("D:/jpo-projekt/QuickFix/example.xml");
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

QString ManageUsers::ListElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    qDebug() << "Total Items: " << items.count();

    for(int i=0; i < items.count(); i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            itemele = itemnode.toElement();
            xml_elements.push_back(itemele);
            qDebug() << itemele.attribute(attribute);
        }
    }
    return itemele.attribute(attribute);
}

QString ManageUsers::readCredentials(QString login, QString attr)
{
    QDomDocument document;

    QFile file("D:/jpo-projekt/QuickFix/example.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "Failed to open File";
    }
    else {
        if(!document.setContent(&file)){
            qDebug() << "Failed to load document";
        }
        file.close();
    }
    QDomElement root = document.firstChildElement();
    return ListElements(root, login, attr);
}
