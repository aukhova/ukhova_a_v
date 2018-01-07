#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "main_menu.h"
#include "ui_main_menu.h"
#include <QtSql>
#include <QMessageBox>
#include <QString>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();


    QMessageBox* mes;
    QString login_;

private slots:
    void on_Enter_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase db;


};

#endif // LOGIN_H
