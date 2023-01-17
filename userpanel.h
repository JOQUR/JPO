#ifndef USERPANEL_H
#define USERPANEL_H

#include <QMainWindow>

namespace Ui {
class userpanel;
}

class userpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit userpanel(QWidget *parent = nullptr, QString login = "");
    ~userpanel();

private:
    Ui::userpanel *ui;
};

#endif // USERPANEL_H
