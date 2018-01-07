#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include "main_menu.h"
#include <QtSql>
#include <QMessageBox>
#include <QString>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();
    QMessageBox* mes;

private slots:
    void on_Registration_2_clicked();

private:
    Ui::Registration *ui;
    QSqlDatabase db;
};

#endif // REGISTRATION_H
