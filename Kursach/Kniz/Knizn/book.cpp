#include "book.h"
#include "ui_book.h"

Book::Book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Book)
{
    ui->setupUi(this);
     model=new QSqlQueryModel();
     estimat="Нет оценки";
    //ui->Estimate->setText(estimat);
     ui->EstimateLine->setText(estimat);
     //obj=new Edit_Estimate();
     //connect(obj,SIGNAL(refresh()),this,SLOT(refresh_Estimate());
}

Book::~Book()
{
    delete ui;
}

void Book:: recieveName(QString str)
{
    name_book=str;
    //ui->ChengeAuthor->setText(name_book);
    ui->book_name->setText(name_book);
    ui->book_name->resize(ui->book_name->sizeHint());
    model->setQuery("SELECT Author_Name FROM dbo.Authors_Books LEFT OUTER JOIN dbo.Authors ON dbo.Authors_Books.ID_Author=dbo.Authors.ID_Author LEFT OUTER JOIN dbo.Books ON dbo.Authors_Books.ID_Book=dbo.Books.ID_Book WHERE Book_Name=N'"+name_book+"' ");
    const int numRows = model->rowCount();
    QString strch="Автор неизвестен";
    if(numRows>0)
    {
        strch=model->data(model->index(0,0)).toString();
        for(int i(1);i<numRows;i++)
            strch=strch+", "+model->data(model->index(i,0)).toString();
     //ui->Authors->setText(model->data(model->index(i,0)).toString());
    }
   //ui->Authors->setText(model()->data(ui->columnView->model()->index(0,0)).toString());
    ui->Authors->setText(strch);
    model->setQuery("SELECT Annotation FROM dbo.Books WHERE Book_Name=N'"+name_book+"' ");
    ui->Annotation->setText(model->data(model->index(0,0)).toString());

    //estimat="Нет оценки";
    model->setQuery("SELECT Estimate FROM dbo.Estimates_Books LEFT OUTER JOIN dbo.Books ON dbo.Estimates_Books.ID_Book=dbo.Books.ID_Book LEFT OUTER JOIN dbo.Users on dbo.Estimates_Books.ID_User=dbo.Users.ID_User WHERE Book_Name=N'"+name_book+"' AND dbo.Users.Login_=SUSER_SNAME()");
    if(model->data(model->index(0,0)).toString()=="0")
        estimat="0(Нет оценки)";
    else if(model->data(model->index(0,0)).toString()!="")
    {estimat=model->data(model->index(0,0)).toString();}
    //ui->Estimate->setText(model->data(model->index(0,0)).toString());


    ui->EstimateLine->setText(estimat);

}

void Book::on_back_clicked()
{
    find_book *obj = new find_book();
    obj->show();
    this->close();
}

void Book::on_Chenge_Estimate_clicked()
{

    //if(estimat!="Нет оценки")

        Edit_Estimate *obj=new Edit_Estimate();


        obj->show();
        this->on_Chenge_Estimate_Send();
        obj->recieveBookName_Estimate(name_book,estimat);
        this->close();


}
 void Book:: on_Chenge_Estimate_Send()
 {
        emit sendBookName_Estimate(name_book,estimat,0); // вызываем сигнал, в котором передаём введённые данные
 }



void Book::on_back_main_menu_clicked()
{
    main_menu *obj = new main_menu();
    obj->show();
    this->close();
}

void Book:: on_Quotations_Send()
{
       emit sendName(name_book);
}

void Book::on_Quotations_clicked()
{
    Quotations *quote =new Quotations();
    quote->show();
    this->on_Quotations_Send();
    quote->recieveName(name_book);
    this->close();
}

void Book::on_Add_my_book_clicked()
{
    QSqlQueryModel *vs=new QSqlQueryModel();

    QSqlQuery* query =new QSqlQuery();
    QMessageBox* mes=new QMessageBox();

    vs->setQuery("SELECT dbo.Users.ID_User FROM dbo.Users WHERE dbo.Users.Login_=SUSER_SNAME()");
    QString id_us=vs->data(vs->index(0,0)).toString();

    vs->setQuery("SELECT dbo.Books.ID_Book FROM dbo.Books WHERE Book_Name=N'"+name_book+"'");
    QString id_book=vs->data(vs->index(0,0)).toString();

    vs->setQuery("SELECT dbo.Users_Books.ID_ FROM dbo.Users_Books WHERE dbo.Users_Books.ID_Book="+id_book+" AND dbo.Users_Books.ID_User="+id_us+"");
    if(vs->data(vs->index(0,0)).toString()!="")
    {
        mes->setText("Книга уже на вашей полке");
        mes->show();
    }
    else
    {
        query->prepare("INSERT INTO dbo.Users_Books(ID_Book,ID_User) VALUES (:ID_Book,:ID_User)");
        query->bindValue(":ID_Book",id_book);
        query->bindValue(":ID_User",id_us);

        if(query->exec())
        {
          mes->setText("Книга добавлена на вашу полку");
          mes->show();
        }
        else
        {
          mes->setText("Не удалось добавить книгу на вашу полку");
          mes->show();
        }
    }
}

void Book::on_pushButton_clicked()
{
    Reviews *review =new Reviews();
    review->show();
    this->on_Quotations_Send();
    review->recieveName(name_book);
    this->close();
}

void Book::on_Del_my_book_clicked()
{
    QSqlQueryModel *vs=new QSqlQueryModel();

    QSqlQuery* query =new QSqlQuery();
    QMessageBox* mes=new QMessageBox();

    vs->setQuery("SELECT dbo.Users.ID_User FROM dbo.Users WHERE dbo.Users.Login_=SUSER_SNAME()");
    QString id_us=vs->data(vs->index(0,0)).toString();

    vs->setQuery("SELECT dbo.Books.ID_Book FROM dbo.Books WHERE Book_Name=N'"+name_book+"'");
    QString id_book=vs->data(vs->index(0,0)).toString();

    vs->setQuery("SELECT dbo.Users_Books.ID_ FROM dbo.Users_Books WHERE dbo.Users_Books.ID_Book="+id_book+" AND dbo.Users_Books.ID_User="+id_us+"");
    if(vs->data(vs->index(0,0)).toString()=="")
    {
        mes->setText("Книги нет на вашей полке");
        mes->show();
    }
    else
    {
        query->prepare("DELETE dbo.Users_Books WHERE dbo.Users_Books.ID_Book="+id_book+" AND dbo.Users_Books.ID_User="+id_us+"");

        if(query->exec())
        {
          mes->setText("Книга удалена с вашей полки");
          mes->show();
        }
        else
        {
          mes->setText("Не удалось удалить книгу с вашей полки");
          mes->show();
        }
    }
}
