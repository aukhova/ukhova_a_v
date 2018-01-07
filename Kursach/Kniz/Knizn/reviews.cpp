#include "reviews.h"
#include "ui_reviews.h"

Reviews::Reviews(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reviews)
{
    ui->setupUi(this);

    user="";
    review="Рецензия не выбрана";
    ui->textReview->setText(review);
    model=new QSqlQueryModel();

    ui->tableView->setModel(model);
    ui->tableView->show();
}

Reviews::~Reviews()
{
    delete ui;
}

void Reviews:: recieveName(QString str)
{
    name_book=str;
    //ui->ChengeAuthor->setText(name_book);
    ui->book_name->setText(name_book);
    ui->book_name->resize(ui->book_name->sizeHint());
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Reviews.Review AS N'Рецензия' FROM dbo.Reviews LEFT OUTER JOIN dbo.Books ON dbo.Reviews.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Reviews.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'");

    ui->tableView->setModel(model);
    ui->tableView->show();

}

void Reviews::on_Book_clicked()
{
    Book *obj=new Book();

    obj->show();
    this->Name_Send();
    obj->recieveName(name_book);
    this->close();
}

void Reviews::Name_Send()
{
    emit sendName(ui->book_name->text()); // вызываем сигнал, в котором передаём введённые данные
}

void Reviews::Name_Review_Send()
{
    emit sendName_Review(name_book,review); // вызываем сигнал, в котором передаём введённые данные
}

void Reviews::on_tableView_clicked(const QModelIndex &index)
{
    review=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    user=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    //QString N=QString::number(name);
    ui->textReview->setText(review);
}

void Reviews::on_findReview_clicked()
{
    review="Рецензия не выбрана";
    ui->textReview->setText(review);
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Reviews.Review AS N'Рецензия' FROM dbo.Reviews LEFT OUTER JOIN dbo.Books ON dbo.Reviews.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Reviews.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'AND dbo.Reviews.Review LIKE N'%"+ui->lineReview ->text()+"%'");

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->lineReview->setText("");
    user="";
}

void Reviews::on_findUser_clicked()
{
    review="Рецензия не выбрана";
    ui->textReview->setText(review);
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Reviews.Review AS N'Рецензия' FROM dbo.Reviews LEFT OUTER JOIN dbo.Books ON dbo.Reviews.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Reviews.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"'AND dbo.Users.Login_ LIKE N'%"+ui->lineUser->text()+"%'");


    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->lineUser->setText("");
    user="";
}

void Reviews::on_My_Reviews_clicked()
{
    review="Рецензия не выбрана";
    ui->textReview->setText(review);
    model->setQuery("SELECT  dbo.Users.Login_ AS N'Пользователь',dbo.Reviews.Review AS N'Рецензия' FROM dbo.Reviews LEFT OUTER JOIN dbo.Books ON dbo.Reviews.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Reviews.ID_User=dbo.Users.ID_User  WHERE Book_Name=N'"+name_book+"'AND dbo.Users.Login_=SUSER_SNAME()");

    user="";
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void Reviews::on_Chenge_Review_clicked()
{
    if(review=="Рецензия не выбрана")
    {
        mes =new QMessageBox;
        mes->setText("Рецензия не выбрана");
        mes->show();

    }
    else
    {
        QSqlQueryModel *vs = new QSqlQueryModel();
        vs->setQuery("SELECT SUSER_SNAME()");
        if(vs->data(vs->index(0,0)).toString()!=user)
        {
            mes =new QMessageBox;
            mes->setText("Вы не можете изменить чужую рецензию");
            mes->show();
        }
        else
        {
            Edit_Review *obj=new Edit_Review();

            obj->show();
            this->Name_Review_Send();
            obj->recieveName(name_book,review,0);
            this->close();
        }

    }
}

void Reviews::on_Add_clicked()
{
    Add_Review *obj=new Add_Review();

    obj->show();
    this->Name_Review_Send();
    obj->recieveName(name_book);
    this->close();
}
