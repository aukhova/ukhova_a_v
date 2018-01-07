#include "find_book.h"
#include "ui_find_book.h"


find_book::find_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::find_book)
{
    ui->setupUi(this);
}

find_book::~find_book()
{
    delete ui;
}

void find_book::on_back_clicked()
{
    main_menu *obj = new main_menu();
    obj->show();
    this->close();
}

void find_book::on_find_book_by_authors_clicked()
{
    find_book_by_author *obj=new find_book_by_author(0);
    obj->show();
    this->close();

}

void find_book::on_find_book_by_names_clicked()
{
    find_book_by_name *obj=new find_book_by_name(0);
    obj->show();
    this->close();
}
