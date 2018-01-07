#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->password_line->setEchoMode(QLineEdit::Password);
    mes =new QMessageBox;
    //login_="нет логина";
}

Login::~Login()
{
    delete ui;
}

void Login::on_Enter_clicked()
{
    QString str=".\\SQLEXPRESS";
    QString str2="Knizhnye_polki";
    //QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //db.setConnectOptions();
    //db.setDatabaseName(str2);

    //QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //db.setDatabaseName("Driver={SQL Server};Server=.\\SQLEXPRESS;Database=Knizhnye_polki;Trusted_Connection=yes;");

    //db.setUserName(ui->login_line->text());
    //db.setPassword(ui->password_line->text());
    login_=ui->login_line->text();

    //db.setHostName(str); // или, например, "my1.server.ru"
    //db.setDatabaseName("Knizhnye_polki");
    //db.setUserName(ui->login_line->text());
    //db.setPassword(ui->password_line->text());

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //db.setConnectOptions();
    db.setDatabaseName(QString("Driver={SQL Server};Server=%1;Database={%2};UID=%3;pwd=%4").arg(str,str2,login_,ui->password_line->text()));
    //db.setUserName(ui->login_line->text());
    //db.setPassword(ui->password_line->text());

    if((db.open())&&(login_!=""))
    {
        //mes->setText("Соединилось");
        main_menu *obj = new main_menu();
        obj->show();
        this->close();

    }
    else
    {
        mes->setText("Ошибка соединения");
        mes->show();
    }


}


