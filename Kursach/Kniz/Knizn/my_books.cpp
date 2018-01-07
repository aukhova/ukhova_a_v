#include "my_books.h"
#include "ui_my_books.h"

My_Books::My_Books(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_Books)
{
    ui->setupUi(this);

    model=new QSqlQueryModel();
    model->setQuery("SELECT Book_Name FROM dbo.Users_Books LEFT OUTER JOIN dbo.Books ON dbo.Users_Books.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Users_Books.ID_User=dbo.Users.ID_User WHERE dbo.Users.Login_=SUSER_SNAME()");


    name_book="Книга не выбрана";
    ui->ChengeBook->setText(name_book);


    ui->columnView->setModel(model);
    ui->columnView->show();
}

My_Books::~My_Books()
{
    delete ui;
}

void My_Books::on_find_book_clicked()
{
    name_book="Книга не выбрана";
    ui->ChengeBook->setText(name_book);
    model->setQuery("SELECT Book_Name FROM dbo.Users_Books LEFT OUTER JOIN dbo.Books ON dbo.Users_Books.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Users_Books.ID_User=dbo.Users.ID_User WHERE dbo.Users.Login_=SUSER_SNAME()AND Book_Name LIKE N'%"+ui->lineName->text()+"%'");
    ui->columnView->setModel(model);
    ui->columnView->show();
}

void My_Books::on_columnView_clicked(const QModelIndex &index)
{
    name_book=ui->columnView->model()->data(ui->columnView->model()->index(index.row(),0)).toString();
    ui->ChengeBook->setText(name_book);
}

void My_Books::on_back_clicked()
{
    find_book *obj = new find_book();
    obj->show();
    this->close();
}

void My_Books:: on_show_book_Send()
{
    emit sendName(ui->ChengeBook->text()); // вызываем сигнал, в котором передаём введённые данные
}


void My_Books::on_show_book_clicked()
{
    QMessageBox* mes=new QMessageBox();
    if(name_book=="Книга не выбрана")
    {
        mes->setText("Книга не выбрана");
        mes->show();
        //au_books->close();
    }
    else
    {
    Book *au_book =new Book();
    au_book->show();
    this->on_show_book_Send();
    au_book->recieveName(name_book);
    this->close();
    }
}
