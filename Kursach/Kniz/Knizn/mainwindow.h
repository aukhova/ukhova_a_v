#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "ui_login.h"
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Login* logwin;

private slots:

    void on_Enter_clicked();

    void on_Registration_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
