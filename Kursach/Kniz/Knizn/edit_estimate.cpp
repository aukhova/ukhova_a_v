#include "edit_estimate.h"
#include "ui_edit_estimate.h"

Edit_Estimate::Edit_Estimate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit_Estimate)
{
    ui->setupUi(this);
    model=new QSqlQueryModel();
    ui->New_Estimate->setMaximum(5);
}

Edit_Estimate::~Edit_Estimate()
{
    delete ui;
}

void Edit_Estimate::on_Edit_clicked()
{
    int estim=(ui->New_Estimate->value());
    QSqlQuery* query =new QSqlQuery();
    QMessageBox* mes=new QMessageBox();
    if(estimat!="Нет оценки")
    {
        estimat=QString::number(estim);


        model->setQuery("SELECT dbo.Estimates_Books.ID_Estimate FROM dbo.Estimates_Books LEFT OUTER JOIN dbo.Books ON dbo.Estimates_Books.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Estimates_Books.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"' AND dbo.Users.Login_=SUSER_SNAME()");
        QString id=model->data(model->index(0,0)).toString();

        query->prepare("UPDATE dbo.Estimates_Books SET Estimate="+estimat+"WHERE dbo.Estimates_Books.ID_Estimate="+id+"");
        if(query->exec())
        {
            mes->setText("Оценка изменена");
            mes->show();
        }
        else
        {
            mes->setText("Изменения не внесены");
            mes->show();
        }
    }
    else
    {
        estimat=QString::number(estim);
        model->setQuery("SELECT dbo.Users.ID_User FROM dbo.Users WHERE dbo.Users.Login_=SUSER_SNAME()");
        QString id_us=model->data(model->index(0,0)).toString();
        model->setQuery("SELECT dbo.Books.ID_Book FROM dbo.Books WHERE Book_Name=N'"+name_book+"'");
        QString id_book=model->data(model->index(0,0)).toString();
        query->prepare("INSERT INTO dbo.Estimates_Books(ID_Book,ID_User,Estimate) VALUES (:ID_Book,:ID_User,:Estimate)");
        query->bindValue(":ID_Book",id_book);
        query->bindValue(":ID_User",id_us);
        query->bindValue(":Estimate",estimat);

        if(query->exec())
        {
            mes->setText("Оценка добавлена");
            mes->show();
        }
        else
        {
            mes->setText("Изменения не внесены");
            mes->show();
        }
    }

    Book *obj=new Book();


    obj->show();
    this->Name_Send();
    obj->recieveName(name_book);
    this->close();
}

void Edit_Estimate:: recieveBookName_Estimate(QString str,QString est)
{
    name_book=str;
    estimat=est;
    ui->BookName->setText(name_book);
    ui->EstimateLine->setText(estimat);
}
void Edit_Estimate::Name_Send()
{
    emit sendName(ui->BookName->text()); // вызываем сигнал, в котором передаём введённые данные
}
