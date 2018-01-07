#include "edit_review.h"
#include "ui_edit_review.h"

Edit_Review::Edit_Review(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit_Review)
{
    ui->setupUi(this);
    model=new QSqlQueryModel();
}

Edit_Review::~Edit_Review()
{
    delete ui;
}

void Edit_Review::Name_Send()
{
    emit sendName(ui->book_name->text()); // вызываем сигнал, в котором передаём введённые данные
}

void Edit_Review:: recieveName(QString str,QString str2,int w)
{
    name_book=str;
    //ui->ChengeAuthor->setText(name_book);
    ui->book_name->setText(name_book);
    //ui->book_name->resize(ui->book_name->sizeHint());
    review=str2;
    ui->OldReview->setText(review);
    where=w;

}

void Edit_Review::on_back_clicked()
{
    if(where==0)
    {
    Reviews *rev =new Reviews();
    rev->show();
    this->Name_Send();
    rev->recieveName(name_book);
    this->close();
    }
    if(where==1)
    {
    My_Reviews *my_rev =new My_Reviews();
    my_rev->show();

    this->close();
    }
}

void Edit_Review::on_chenge_clicked()
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

        query->prepare("UPDATE dbo.Reviews SET dbo.Reviews.Review=N'"+new_review+"' WHERE dbo.Reviews.ID_Book="+id_book+" AND dbo.Reviews.ID_User="+id_us+" AND dbo.Reviews.Review=N'"+review+"'");
        if(query->exec())
        {
          mes->setText("Рецензия изменена");
          mes->show();
          if(where==0)
          {
          Reviews *rev =new Reviews();
          rev->show();
          this->Name_Send();
          rev->recieveName(name_book);
          this->close();
          }
          if(where==1)
          {
          My_Reviews *my_rev =new My_Reviews();
         my_rev->show();

          this->close();
          }
        }
        else
        {
          mes->setText("Изменения не внесены");
          mes->show();
        }
     }
     else
    {
        mes->setText("Напишите новый вариант рецензии");
        mes->show();
    }
}

void Edit_Review::on_del_clicked()
{
    QSqlQuery* query =new QSqlQuery();
    QMessageBox* mes=new QMessageBox();

    model->setQuery("SELECT dbo.Users.ID_User FROM dbo.Users WHERE dbo.Users.Login_=SUSER_SNAME()");
    QString id_us=model->data(model->index(0,0)).toString();

    model->setQuery("SELECT dbo.Books.ID_Book FROM dbo.Books WHERE Book_Name=N'"+name_book+"'");
    QString id_book=model->data(model->index(0,0)).toString();

    query->prepare("DELETE dbo.Reviews WHERE dbo.Reviews.ID_Book="+id_book+" AND dbo.Reviews.ID_User="+id_us+" AND dbo.Reviews.Review=N'"+review+"'");
    if(query->exec())
    {
      mes->setText("Рецензия удалена");
      mes->show();

      if(where==0)
      {
      Reviews *rev =new Reviews();
      rev->show();
      this->Name_Send();
      rev->recieveName(name_book);
      this->close();
      }
      if(where==1)
      {
      My_Reviews *my_rev =new My_Reviews();
      my_rev->show();

      this->close();
      }

    }
    else
    {
      mes->setText("Не удалось удалить рецензию");
      mes->show();
    }
}
