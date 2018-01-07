#include "authors_books.h"
#include "ui_authors_books.h"

Authors_books::Authors_books(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authors_books)
{
    ui->setupUi(this);
    //name="No";
    name_book="Книга не выбрана";
    ui->ChengeBook->setText(name_book);

    model=new QSqlQueryModel();
    model->setQuery("SELECT Book_Name FROM dbo.Authors_Books LEFT OUTER JOIN dbo.Authors ON dbo.Authors_Books.ID_Author=dbo.Authors.ID_Author LEFT OUTER JOIN dbo.Books ON dbo.Authors_Books.ID_Book=dbo.Books.ID_Book WHERE Author_Name=N'"+name+"' ");


    ui->columnView->setModel(model);
    ui->columnView->show();
}

Authors_books::~Authors_books()
{
    delete ui;
}

void Authors_books:: recieveName(QString str)
{
    name=str;
    ui->ChengeAuthor->setText(name);
    ui->ChengeAuthor->resize(ui->ChengeAuthor->sizeHint());
    model->setQuery("SELECT Book_Name FROM dbo.Authors_Books LEFT OUTER JOIN dbo.Authors ON dbo.Authors_Books.ID_Author=dbo.Authors.ID_Author LEFT OUTER JOIN dbo.Books ON dbo.Authors_Books.ID_Book=dbo.Books.ID_Book WHERE Author_Name=N'"+name+"' ");


    ui->columnView->setModel(model);
    ui->columnView->show();
}

void Authors_books::on_columnView_clicked(const QModelIndex &index)
{
    name_book=ui->columnView->model()->data(ui->columnView->model()->index(index.row(),0)).toString();
    ui->ChengeBook->setText(name_book);
}

void Authors_books::on_back_clicked()
{
    find_book_by_author *obj=new find_book_by_author(0);
    obj->show();
    this->close();
}
void Authors_books:: on_show_book_Send()
{
    emit sendName(ui->ChengeBook->text()); // вызываем сигнал, в котором передаём введённые данные
}
void Authors_books::on_show_book_clicked()
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
