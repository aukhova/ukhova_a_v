#include "my_reviews.h"
#include "ui_my_reviews.h"

My_Reviews::My_Reviews(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_Reviews)
{
    ui->setupUi(this);

    review="Рецензия не выбрана";
    name_book="Книга не выбрана";
    ui->book_name->setText(name_book);

    model=new QSqlQueryModel();

    //ui->ChengeAuthor->setText(name_book);
    model->setQuery("SELECT Book_Name AS N'Книга',dbo.Reviews.Review AS N'Рецензия' FROM dbo.Reviews LEFT OUTER JOIN dbo.Books ON dbo.Reviews.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Reviews.ID_User=dbo.Users.ID_User WHERE dbo.Users.Login_=SUSER_SNAME()");

    ui->tableView->setModel(model);
    ui->tableView->show();
}

My_Reviews::~My_Reviews()
{
    delete ui;
}

void My_Reviews::on_Book_clicked()
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
        mes->setText("Выберите рецензию, чтобу перейти к книге");
        mes->show();
    }
}

void My_Reviews::Name_Send()
{
    emit sendName(name_book); // вызываем сигнал, в котором передаём введённые данные
}

void My_Reviews::Name_Review_Send()
{
    emit sendName_Review(name_book,review,1); // вызываем сигнал, в котором передаём введённые данные
}

void My_Reviews::on_tableView_clicked(const QModelIndex &index)
{
    review=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    name_book=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    //QString N=QString::number(name);
    ui->textReview->setText(review);
    ui->book_name->setText(name_book);
}

void My_Reviews::on_findReview_clicked()
{
    review="Рецензия не выбрана";
    ui->textReview->setText(review);
    model->setQuery("SELECT  Book_Name AS N'Книга',dbo.Reviews.Review AS N'Рецензия' FROM dbo.Reviews LEFT OUTER JOIN dbo.Books ON dbo.Reviews.ID_Book=dbo.Books.ID_Book  LEFT OUTER JOIN dbo.Users on dbo.Reviews.ID_User=dbo.Users.ID_User WHERE dbo.Users.Login_=SUSER_SNAME() AND dbo.Reviews.Review LIKE N'%"+ui->lineReview->text()+"%'");

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->lineReview->setText("");
    name_book="Книга не выбрана";
    ui->book_name->setText(name_book);
}

void My_Reviews::on_Chenge_Review_clicked()
{
    if( review=="Рецензия не выбрана")
    {
        mes =new QMessageBox;
        mes->setText("Рецензия не выбрана");
        mes->show();

    }
    else
    {

            Edit_Review *obj=new Edit_Review();

            obj->show();
            this->Name_Review_Send();
            obj->recieveName(name_book,review,1);
            this->close();


    }
}

void My_Reviews::on_back_main_menu_clicked()
{
    main_menu *obj = new main_menu();
    obj->show();
    this->close();
}
