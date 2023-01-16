#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <adminpanel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_login_clicked();
    void loginSlot(void);

private:
    ManageUsers man;
    Ui::LoginWindow *ui;
    int isUser(QString& login, QString& pass);
};
#endif // LOGINWINDOW_H
