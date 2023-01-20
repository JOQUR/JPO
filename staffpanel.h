#ifndef STAFFPANEL_H
#define STAFFPANEL_H

#include <QMainWindow>
#include <QtXml>
namespace Ui {
class StaffPanel;
}

class StaffPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaffPanel(QWidget *parent = nullptr);
    ~StaffPanel();

private slots:
    void importDataSlot();

private:
    Ui::StaffPanel *ui;
    QDomElement root;
    QDomElement itemele;
    std::vector<QDomElement> xml_elements;
    void readXML(void);
    void ListElements(QDomElement root, QString tagname);
};

#endif // STAFFPANEL_H
