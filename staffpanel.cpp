#include "staffpanel.h"
#include "ui_staffpanel.h"

StaffPanel::StaffPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaffPanel)
{
    ui->setupUi(this);
}

StaffPanel::~StaffPanel()
{
    delete ui;
}
