#include "quotations.h"
#include "ui_quotations.h"

Quotations::Quotations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Quotations)
{
    ui->setupUi(this);
    //mes =new QMessageBox;
    user="";
    quote="Цитата не выбрана";
    ui->textQuote->setText(quote);
    model=new QSqlQueryModel();
   // model->setQuery("SELECT  dbo.Users.Login_,dbo.Quotes.Quote FROM dbo.Quotes LEFT OUTER JOIN dbo.Books ON dbo.Quotes.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Quotes.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'");


    //name_book="Книга не выбрана";
    //ui->ChengeBook->setText(name_book);


    ui->tableView->setModel(model);
    ui->tableView->show();
}

Quotations::~Quotations()
{
    delete ui;
}

void Quotations:: recieveName(QString str)
{
    name_book=str;
    //ui->ChengeAuthor->setText(name_book);
    ui->book_name->setText(name_book);
    ui->book_name->resize(ui->book_name->sizeHint());
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Quotes.Quote AS N'Цитата' FROM dbo.Quotes LEFT OUTER JOIN dbo.Books ON dbo.Quotes.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Quotes.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'");

    ui->tableView->setModel(model);
    ui->tableView->show();

}
void Quotations::on_Book_clicked()
{
    Book *obj=new Book();

    obj->show();
    this->Name_Send();
    obj->recieveName(name_book);
    this->close();
}

void Quotations::Name_Send()
{
    emit sendName(ui->book_name->text()); // вызываем сигнал, в котором передаём введённые данные
}

void Quotations::Name_Quote_Send()
{
    emit sendName_Quote(name_book,quote); // вызываем сигнал, в котором передаём введённые данные
}

void Quotations::on_tableView_clicked(const QModelIndex &index)
{
    quote=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    user=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    //QString N=QString::number(name);
    ui->textQuote->setText(quote);
}

void Quotations::on_findQuote_clicked()
{
    quote="Цитата не выбрана";
    ui->textQuote->setText(quote);
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Quotes.Quote AS N'Цитата' FROM dbo.Quotes LEFT OUTER JOIN dbo.Books ON dbo.Quotes.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Quotes.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'AND dbo.Quotes.Quote LIKE N'%"+ui->lineQuote->text()+"%'");

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->lineQuote->setText("");
    user="";
}

void Quotations::on_findUser_clicked()
{
    quote="Цитата не выбрана";
    ui->textQuote->setText(quote);
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Quotes.Quote AS N'Цитата' FROM dbo.Quotes LEFT OUTER JOIN dbo.Books ON dbo.Quotes.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Quotes.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'AND dbo.Users.Login_ LIKE N'%"+ui->lineUser->text()+"%'");


    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->lineUser->setText("");
    user="";
}

void Quotations::on_My_Quote_clicked()
{
    quote="Цитата не выбрана";
    ui->textQuote->setText(quote);
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Quotes.Quote AS N'Цитата' FROM dbo.Quotes LEFT OUTER JOIN dbo.Books ON dbo.Quotes.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Quotes.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'AND dbo.Users.Login_=SUSER_SNAME()");

    user="";
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void Quotations::on_Chenge_Quote_clicked()
{
    if(quote=="Цитата не выбрана")
    {
        mes =new QMessageBox;
        mes->setText("Цитата не выбрана");
        mes->show();

    }
    else
    {
        QSqlQueryModel *vs = new QSqlQueryModel();
        vs->setQuery("SELECT SUSER_SNAME()");
        if(vs->data(vs->index(0,0)).toString()!=user)
        {
            mes =new QMessageBox;
            mes->setText("Вы не можете изменить чужую цитату");
            mes->show();
        }
        else
        {
            Edit_Quote *obj=new Edit_Quote();

            obj->show();
            this->Name_Quote_Send();
            obj->recieveName(name_book,quote,0);
            this->close();
        }

    }
}

void Quotations::on_Add_clicked()
{
    Add_Quote *obj=new Add_Quote();

    obj->show();
    this->Name_Quote_Send();
    obj->recieveName(name_book);
    this->close();
}
