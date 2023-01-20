#include "staffpanel.h"
#include "ui_staffpanel.h"

StaffPanel::StaffPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaffPanel)
{
    ui->setupUi(this);
    connect(ui->importData, SIGNAL(clicked()), this, SLOT(importDataSlot()));
}

StaffPanel::~StaffPanel()
{
    delete ui;
}


void StaffPanel::readXML(void)
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
    root = document.firstChildElement();
    ListElements(root, "Tickets");
}


void StaffPanel::ListElements(QDomElement root, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    qDebug() << "Total Items: " << items.count();

    for(int i=0; i < items.count(); i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            itemele = itemnode.toElement();
            xml_elements.push_back(itemele);
            ui->Tickets->insertRow(ui->Tickets->rowCount());
            ui->Tickets->setItem(i, 0, new QTableWidgetItem(itemele.attribute("Title")));
            ui->Tickets->setItem(i, 1, new QTableWidgetItem(itemele.attribute("Description")));
            ui->Tickets->setItem(i, 2, new QTableWidgetItem(itemele.attribute("Severity")));
            ui->Tickets->setItem(i, 3, new QTableWidgetItem(itemele.attribute("Date")));
        }
    }
}
void StaffPanel::importDataSlot()
{
    readXML();
}

