#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Enter_clicked()
{
    logwin =new Login();
    logwin->show();
    this->close();
}

void MainWindow::on_Registration_clicked()
{
    Registration *reg= new Registration();
    reg->show();
    this->close();
}
