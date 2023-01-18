#ifndef STAFFPANEL_H
#define STAFFPANEL_H

#include <QMainWindow>

namespace Ui {
class StaffPanel;
}

class StaffPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaffPanel(QWidget *parent = nullptr);
    ~StaffPanel();

private:
    Ui::StaffPanel *ui;
};

#endif // STAFFPANEL_H
