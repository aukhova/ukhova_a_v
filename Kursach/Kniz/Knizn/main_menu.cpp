#include "main_menu.h"
#include "ui_main_menu.h"

main_menu::main_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
}

main_menu::~main_menu()
{
    delete ui;
}

void main_menu::on_findBook_clicked()
{
    find_book *find_books  = new find_book();
    find_books->show();
    this->close();
}


void main_menu::on_my_bookss_clicked()
{
    My_Books *my_books  = new My_Books();
    my_books->show();
    this->close();
}

void main_menu::on_My_quotations_clicked()
{
    My_Quotations *my_Quots  = new My_Quotations ();
    my_Quots->show();
    this->close();
}

void main_menu::on_My_reviews_clicked()
{
    My_Reviews *my_reviews  = new My_Reviews ();
    my_reviews->show();
    this->close();
}
