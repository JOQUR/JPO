#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include <QtXml>
#include <QTextStream>
#include "manageusers.h"

#define MAX_ROLES 3

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();
    ManageUsers man;
    std::vector<User*> users;

private slots:
    void submitSlot(void);
    void readSlot(void);
    void remSlot(void);
    void saveSlot(void);
private:
    Ui::AdminPanel *ui;
    QString rl[MAX_ROLES] = {"Staff", "Employee", "Admin"};
};

#endif // ADMINPANEL_H
