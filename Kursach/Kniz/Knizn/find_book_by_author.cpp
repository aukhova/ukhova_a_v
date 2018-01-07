#include "find_book_by_author.h"
#include "ui_find_book_by_author.h"

find_book_by_author::find_book_by_author(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::find_book_by_author)
{
    ui->setupUi(this);

    model=new QSqlQueryModel();
    model->setQuery("SELECT Author_Name  FROM dbo.Authors ");

    mes =new QMessageBox;

    name="Автор не выбран";
    ui->ChengeAuthor->setText(name);


    ui->tableView->setModel(model);
    ui->tableView->show();

    //au_books=new Authors_books();
    //connect(ui->show_books, SIGNAL(clicked()), au_books, SLOT(show()));
    //connect(ui->show_books, SIGNAL(clicked()), this, SLOT(on_show_books_Send())); // подключаем клик по кнопке к определенному нами слоту
    //connect(this, SIGNAL(sendName(QString)), au_books, SLOT(recieveName(QString))); // подключение сигнала к слоту нашей формы
    //connect(ui->show_books, SIGNAL(clicked()), this, SLOT(close());

}

void find_book_by_author:: on_show_books_Send()
{
    emit sendName(ui->ChengeAuthor->text()); // вызываем сигнал, в котором передаём введённые данные
}

find_book_by_author::~find_book_by_author()
{
    delete ui;
}

void find_book_by_author::on_findAuthor_clicked()
{
    name="Автор не выбран";
    ui->ChengeAuthor->setText(name);
    model->setQuery("SELECT Author_Name FROM dbo.Authors WHERE Author_Name LIKE N'%"+ui->lineAuthor->text()+"%'");
    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->lineAuthor->setText("");
}

void find_book_by_author::on_tableView_clicked(const QModelIndex &index)
{
    //QString name;
    name=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    //QString N=QString::number(name);
    ui->ChengeAuthor->setText(name);
    //ui->ChengeAuthor->show();

    //QSqlQuery* q = new QSqlQuery();
    //q->prepare("SELECT Author_Name FROM dbo.Authors WHERE ID_Author=ID_Author");
    //q->bindValue("ID_Author",name);
    //ui->ChengeAuthor->setText(q->value(0).toString());

    //if(q->exec())
    //{
      //  q->next();
        //ui->ChengeAuthor->setText(q->value(0).toString());
    //}
}

void find_book_by_author::on_back_clicked()
{
    find_book *obj = new find_book();
    obj->show();
    this->close();
}

void find_book_by_author::on_show_books_clicked()
{
    if(name=="Автор не выбран")
    {
        mes->setText("Автор не выбран");
        mes->show();
        //au_books->close();
    }
    else
    {
    Authors_books *au_books =new Authors_books();
    au_books->show();
    this->on_show_books_Send();
    au_books->recieveName(name);
    this->close();
    }
}
