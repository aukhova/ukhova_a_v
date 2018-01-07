#include "find_book_by_name.h"
#include "ui_find_book_by_name.h"

find_book_by_name::find_book_by_name(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::find_book_by_name)
{
    ui->setupUi(this);

    model=new QSqlQueryModel();
    model->setQuery("SELECT Book_Name  FROM dbo.Books ");


    name_book="Книга не выбрана";
    ui->ChengeBook->setText(name_book);


    ui->columnView->setModel(model);
    ui->columnView->show();
}

find_book_by_name::~find_book_by_name()
{
    delete ui;
}

void find_book_by_name::on_find_book_clicked()
{
    name_book="Книга не выбрана";
    ui->ChengeBook->setText(name_book);
    model->setQuery("SELECT Book_Name FROM dbo.Books WHERE Book_Name LIKE N'%"+ui->lineName->text()+"%'");
    ui->columnView->setModel(model);
    ui->columnView->show();
    ui->lineName->setText("");
}

void find_book_by_name::on_columnView_clicked(const QModelIndex &index)
{
    name_book=ui->columnView->model()->data(ui->columnView->model()->index(index.row(),0)).toString();
    ui->ChengeBook->setText(name_book);
}

void find_book_by_name::on_back_clicked()
{
    find_book *obj = new find_book();
    obj->show();
    this->close();
}

void find_book_by_name:: on_show_book_Send()
{
    emit sendName(ui->ChengeBook->text()); // вызываем сигнал, в котором передаём введённые данные
}


void find_book_by_name::on_show_book_clicked()
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
