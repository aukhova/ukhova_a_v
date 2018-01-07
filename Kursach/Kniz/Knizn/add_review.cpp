#include "add_review.h"
#include "ui_add_review.h"

Add_Review::Add_Review(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Review)
{
    ui->setupUi(this);
    model=new QSqlQueryModel();
}

Add_Review::~Add_Review()
{
    delete ui;
}

void Add_Review::Name_Send()
{
    emit sendName(ui->book_name->text()); // вызываем сигнал, в котором передаём введённые данные
}

void Add_Review:: recieveName(QString str)
{
    name_book=str;
    //ui->ChengeAuthor->setText(name_book);
    ui->book_name->setText(name_book);
    //ui->book_name->resize(ui->book_name->sizeHint());

}

void Add_Review::on_back_clicked()
{
    Reviews *rev =new Reviews();
    rev->show();
    this->Name_Send();
    rev->recieveName(name_book);
    this->close();
}

void Add_Review::on_Add_clicked()
{
    QString new_review="";
    new_review=ui->NewReview->toPlainText();
    QSqlQuery* query =new QSqlQuery();
    QMessageBox* mes=new QMessageBox();

    if(new_review!="")
    {
        model->setQuery("SELECT dbo.Users.ID_User FROM dbo.Users WHERE dbo.Users.Login_=SUSER_SNAME()");
        QString id_us=model->data(model->index(0,0)).toString();

        model->setQuery("SELECT dbo.Books.ID_Book FROM dbo.Books WHERE Book_Name=N'"+name_book+"'");
        QString id_book=model->data(model->index(0,0)).toString();

        query->prepare("INSERT INTO dbo.Reviews(ID_Book,ID_User,Review) VALUES (:ID_Book,:ID_User,:Review)");
        query->bindValue(":ID_Book",id_book);
        query->bindValue(":ID_User",id_us);
        query->bindValue(":Review",new_review);


        if(query->exec())
        {
          mes->setText("Рецензия добавлена");
          mes->show();
          Reviews *rev =new Reviews();
          rev->show();
          this->Name_Send();
          rev->recieveName(name_book);
          this->close();
        }
        else
        {
          mes->setText("Не удалось добавить рецензию");
          mes->show();
        }
     }
     else
    {
        mes->setText("Напишите новую рецензию");
        mes->show();
    }
}
