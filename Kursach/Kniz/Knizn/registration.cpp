#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    mes =new QMessageBox;




}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_Registration_2_clicked()
{
    QString str=".\\SQLEXPRESS";
    QString str2="Knizhnye_polki";

    //QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    //QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //db.setConnectOptions();
    //db.setDatabaseName(str2);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL Server};Server=.\\SQLEXPRESS;Database=Knizhnye_polki;Trusted_Connection=yes;");

    //db.setDatabaseName(QString("Driver={SQL Server};Server=%1;Database={%2};UID=%3;pwd=%4").arg(str,str2,"A","A"));
    //db.setDatabaseName(QString("Driver={SQL Server};Server=%1;Database={%2}").arg(str,str2));

    if(db.open())
    {
        mes->setText("Соединилось");
        mes->show();
        //main_menu *obj = new main_menu();
        //obj->show();
        //this->close();

        QSqlQuery* query =new QSqlQuery();



        if((ui->Age_line->text()!="")&&(ui->e_mail_line->text()!="")&&(ui->login_line->text()!="")&&(ui->Name_line->text()!="")&&(ui->password_line->text()!="")&&(ui->Surname_line->text()!=""))
        {


            query->prepare("INSERT INTO dbo.Users(Login_, Password_, e_mail, Name, Surname,Age) VALUES (:Login_,:Password_,:e_mail,:Name,:Surname,:Age)");
            query->bindValue(":Login_",ui->login_line->text());
            query->bindValue(":Password_",ui->password_line->text());
            query->bindValue(":e_mail",ui->e_mail_line->text());
            query->bindValue(":Name",ui->Name_line->text());
            query->bindValue(":Surname",ui->Surname_line->text());
            query->bindValue(":Age",ui->Age_line->text());
            //query->bindValue(":Age",ui->Age_line->text());
            if(query->exec())
            {
              mes->setText("Пользователь добавлен");
              mes->show();

              query->prepare("CREATE LOGIN "+ui->login_line->text()+" WITH PASSWORD='"+ui->password_line->text()+"';");
              if(query->exec())
              {
                 //QMessageBox* mes2 =new QMessageBox();
                mes->setText("LOGIN добавлен");
                mes->show();
              }
              query->prepare("CREATE USER "+ui->login_line->text()+" FOR LOGIN "+ui->login_line->text()+";");
              if(query->exec())
              {
                  //QMessageBox* mes3 =new QMessageBox();
                mes->setText("USER добавлен");
                mes->show();
              }
              query->prepare("ALTER ROLE Users ADD MEMBER "+ui->login_line->text()+";");
              if(query->exec())
              {
                  //QMessageBox* mes4 =new QMessageBox();
                mes->setText("ALTER ROLE");
                mes->show();
              }

              query->prepare("EXECUTE AS LOGIN='"+ui->login_line->text()+"'");
              if(query->exec())
              {
                  //QMessageBox* mes5 =new QMessageBox();
                mes->setText("Пользователь зарегистрирован");
                mes->show();

                main_menu *obj = new main_menu();
                obj->show();
                this->close();
              }

              }

            else
            {
              mes->setText("Пользователь не зарегистрирован, возможно такой логин уже существует");
              mes->show();
            }
         }
         else
        {
            mes->setText("Введите данные");
            mes->show();
        }

    }
    else
    {
        mes->setText("Ошибка соединения");
        mes->show();
    }


}
