#ifndef USER_H
#define USER_H
#include <iostream>
#include <QMainWindow>

class User
{
public:
    User(QString& fullName, QString& login, QString& pass, QString& role, int id);

    QString getFullName(void);
    QString getLogin(void);
    QString getPass(void);
    QString getRole(void);
    int getID(void);

private:
    QString FullName;
    QString login;
    QString password;
    QString role;
    int id;
};

#endif // USER_H
