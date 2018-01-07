#include "edit_quote.h"
#include "ui_edit_quote.h"

Edit_Quote::Edit_Quote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit_Quote)
{
    ui->setupUi(this);
    model=new QSqlQueryModel();
}

Edit_Quote::~Edit_Quote()
{
    delete ui;
}

void Edit_Quote::Name_Send()
{
    emit sendName(ui->book_name->text()); // вызываем сигнал, в котором передаём введённые данные
}

void Edit_Quote:: recieveName(QString str,QString str2,int w)
{
    name_book=str;
    //ui->ChengeAuthor->setText(name_book);
    ui->book_name->setText(name_book);
    //ui->book_name->resize(ui->book_name->sizeHint());
    quote=str2;
    ui->OldQuote->setText(quote);
    where=w;

}

void Edit_Quote::on_back_clicked()
{
    if(where==0)
    {
    Quotations *quote =new Quotations();
    quote->show();
    this->Name_Send();
    quote->recieveName(name_book);
    this->close();
    }
    if(where==1)
    {
    My_Quotations *my_quote =new My_Quotations();
    my_quote->show();

    this->close();
    }
}

void Edit_Quote::on_chenge_clicked()
{
    QString new_quote="";
    new_quote=ui->NewQuote->toPlainText();
    QSqlQuery* query =new QSqlQuery();
    QMessageBox* mes=new QMessageBox();

    if(new_quote!="")
    {
        model->setQuery("SELECT dbo.Users.ID_User FROM dbo.Users WHERE dbo.Users.Login_=SUSER_SNAME()");
        QString id_us=model->data(model->index(0,0)).toString();
        model->setQuery("SELECT dbo.Books.ID_Book FROM dbo.Books WHERE Book_Name=N'"+name_book+"'");
        QString id_book=model->data(model->index(0,0)).toString();

        query->prepare("UPDATE dbo.Quotes SET dbo.Quotes.Quote=N'"+new_quote+"' WHERE dbo.Quotes.ID_Book="+id_book+" AND dbo.Quotes.ID_User="+id_us+" AND dbo.Quotes.Quote=N'"+quote+"'");
        if(query->exec())
        {
          mes->setText("Цитата изменена");
          mes->show();
          if(where==0)
          {
          Quotations *quote =new Quotations();
          quote->show();
          this->Name_Send();
          quote->recieveName(name_book);
          this->close();
          }
          if(where==1)
          {
          My_Quotations *my_quote =new My_Quotations();
          my_quote->show();

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
        mes->setText("Напишите новый вариант цитаты");
        mes->show();
    }
}

void Edit_Quote::on_del_clicked()
{
    QSqlQuery* query =new QSqlQuery();
    QMessageBox* mes=new QMessageBox();

    model->setQuery("SELECT dbo.Users.ID_User FROM dbo.Users WHERE dbo.Users.Login_=SUSER_SNAME()");
    QString id_us=model->data(model->index(0,0)).toString();

    model->setQuery("SELECT dbo.Books.ID_Book FROM dbo.Books WHERE Book_Name=N'"+name_book+"'");
    QString id_book=model->data(model->index(0,0)).toString();

    query->prepare("DELETE dbo.Quotes WHERE dbo.Quotes.ID_Book="+id_book+" AND dbo.Quotes.ID_User="+id_us+"AND dbo.Quotes.Quote=N'"+quote+"'");
    if(query->exec())
    {
      mes->setText("Цитата удалена");
      mes->show();

      if(where==0)
      {
      Quotations *quote =new Quotations();
      quote->show();
      this->Name_Send();
      quote->recieveName(name_book);
      this->close();
      }
      if(where==1)
      {
      My_Quotations *my_quote =new My_Quotations();
      my_quote->show();

      this->close();
      }

    }
    else
    {
      mes->setText("Не удалось удалить цитату");
      mes->show();
    }
}
