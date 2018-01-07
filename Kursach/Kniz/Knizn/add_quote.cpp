#include "add_quote.h"
#include "ui_add_quote.h"

Add_Quote::Add_Quote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Quote)
{
    ui->setupUi(this);
    model=new QSqlQueryModel();
}

Add_Quote::~Add_Quote()
{
    delete ui;
}
void Add_Quote::Name_Send()
{
    emit sendName(ui->book_name->text()); // вызываем сигнал, в котором передаём введённые данные
}

void Add_Quote:: recieveName(QString str)
{
    name_book=str;
    //ui->ChengeAuthor->setText(name_book);
    ui->book_name->setText(name_book);
    //ui->book_name->resize(ui->book_name->sizeHint());

}

void Add_Quote::on_back_clicked()
{
    Quotations *quote =new Quotations();
    quote->show();
    this->Name_Send();
    quote->recieveName(name_book);
    this->close();
}

void Add_Quote::on_Add_clicked()
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

        query->prepare("INSERT INTO dbo.Quotes(ID_Book,ID_User,Quote) VALUES (:ID_Book,:ID_User,:Quote)");
        query->bindValue(":ID_Book",id_book);
        query->bindValue(":ID_User",id_us);
        query->bindValue(":Quote",new_quote);


        if(query->exec())
        {
          mes->setText("Цитата добавлена");
          mes->show();
          Quotations *quote =new Quotations();
          quote->show();
          this->Name_Send();
          quote->recieveName(name_book);
          this->close();
        }
        else
        {
          mes->setText("Не удалось добавить цитату");
          mes->show();
        }
     }
     else
    {
        mes->setText("Напишите новую цитату");
        mes->show();
    }
}
