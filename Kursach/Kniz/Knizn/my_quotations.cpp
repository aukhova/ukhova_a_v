#include "my_quotations.h"
#include "ui_my_quotations.h"

My_Quotations::My_Quotations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_Quotations)
{
    ui->setupUi(this);
    quote="Цитата не выбрана";
    name_book="Книга не выбрана";
    ui->book_name->setText(name_book);

    model=new QSqlQueryModel();

    //ui->ChengeAuthor->setText(name_book);
    model->setQuery("SELECT Book_Name AS N'Книга',dbo.Quotes.Quote AS N'Цитата' FROM dbo.Quotes LEFT OUTER JOIN dbo.Books ON dbo.Quotes.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Quotes.ID_User=dbo.Users.ID_User WHERE dbo.Users.Login_=SUSER_SNAME()");

    ui->tableView->setModel(model);
    ui->tableView->show();

}

My_Quotations::~My_Quotations()
{
    delete ui;
}

void My_Quotations::on_Book_clicked()
{
    if(name_book!="Книга не выбрана")
    {
    Book *obj=new Book();

    obj->show();
    this->Name_Send();
    obj->recieveName(name_book);
    this->close();
    }
    else
    {
         mes =new QMessageBox;
        mes->setText("Выберите цитату, чтобу перейти к книге");
        mes->show();
    }
}

void My_Quotations::Name_Send()
{
    emit sendName(name_book); // вызываем сигнал, в котором передаём введённые данные
}

void My_Quotations::Name_Quote_Send()
{
    emit sendName_Quote(name_book,quote,1); // вызываем сигнал, в котором передаём введённые данные
}

void My_Quotations::on_tableView_clicked(const QModelIndex &index)
{
    quote=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    name_book=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    //QString N=QString::number(name);
    ui->textQuote->setText(quote);
    ui->book_name->setText(name_book);
}

void My_Quotations::on_findQuote_clicked()
{
    quote="Цитата не выбрана";
    ui->textQuote->setText(quote);
    model->setQuery("SELECT  Book_Name AS N'Книга',dbo.Quotes.Quote AS N'Цитата' FROM dbo.Quotes LEFT OUTER JOIN dbo.Books ON dbo.Quotes.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Quotes.ID_User=dbo.Users.ID_User WHERE dbo.Users.Login_=SUSER_SNAME() AND dbo.Quotes.Quote LIKE N'%"+ui->lineQuote->text()+"%'");

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->lineQuote->setText("");
    name_book="Книга не выбрана";
    ui->book_name->setText(name_book);
}

void My_Quotations::on_Chenge_Quote_clicked()
{
    if(quote=="Цитата не выбрана")
    {
        mes =new QMessageBox;
        mes->setText("Цитата не выбрана");
        mes->show();

    }
    else
    {

            Edit_Quote *obj=new Edit_Quote();

            obj->show();
            this->Name_Quote_Send();
            obj->recieveName(name_book,quote,1);
            this->close();


    }
}

void My_Quotations::on_back_main_menu_clicked()
{
    main_menu *obj = new main_menu();
    obj->show();
    this->close();
}
