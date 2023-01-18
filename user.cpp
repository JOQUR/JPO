#include "user.h"


User::User(QString& fullName, QString& login, QString& pass, QString& role, int id)
{
    this->FullName = fullName;
    this->login = login;
    this->password = pass;
    this->role = role;
    this->id = id;
}

QString User::getFullName(void)
{
    return this->FullName;
}

QString User::getLogin(void)
{
    return this->login;
}
QString User::getPass(void)
{
    return this->password;
}
QString User::getRole(void)
{
    return this->role;
}

int User::getID(void)
{
    return this->id;
}

User::~User()
{
    delete this;
}
