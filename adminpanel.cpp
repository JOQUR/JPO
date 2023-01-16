#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    for(int i = 0; i < MAX_ROLES; ++i){
        ui->roles->addItem(rl[i]);
    }
    connect(ui->submitB, SIGNAL(clicked()), this, SLOT(submitSlot()));
    connect(ui->read, SIGNAL(clicked()), this, SLOT(readSlot()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(remSlot()));
    connect(ui->back, SIGNAL(clicked()), this, SLOT(saveSlot()));
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::submitSlot()
{
    man.addUser(users, ui->name->text(), ui->login->text(), ui->pass->text(), ui->roles->currentText());
}

void AdminPanel::readSlot()
{
    QStringList list, list2;
    for (int i = 0; i < (int)users.size(); ++i) {
        qDebug() << users[i]->getFullName();
        qDebug() << users[i]->getRole();
        qDebug() << users[i]->getID();
        qDebug() << "===================";
        list.append(users[i]->getFullName());
        list2.append(users[i]->getLogin());
    }
    qDebug() << "===================\n\n";
    QStringListModel* model;
    QStringListModel* login;
    login = new QStringListModel(this);
    model = new QStringListModel(this);
    model->setStringList(list);
    ui->sh_fullname->setModel(model);

    login->setStringList(list2);
    ui->sh_login->setModel(login);


    man.readXML();
}

void AdminPanel::remSlot(void)
{
    int id = ui->idtorem->text().toInt();
    man.removeUser(users, id);
}

void AdminPanel::saveSlot(void)
{
    man.writeXML(users);
    this->close();
}
