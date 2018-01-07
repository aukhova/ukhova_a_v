#ifndef BOOK_H
#define BOOK_H

#include "find_book_by_name.h"
#include "find_book.h"
#include "main_menu.h"
#include "edit_estimate.h"
#include "quotations.h"
#include "reviews.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class Book;
}

class Book : public QWidget
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = 0);
    ~Book();
    QString name_book;
    QString estimat;
    //Edit_Estimate *obj;

private:
    Ui::Book *ui;
    QSqlQueryModel *model;
    //QSqlQuery query;

public slots:
    void recieveName(QString str);


private slots:
    void on_back_clicked();
    void on_Chenge_Estimate_clicked();
    void on_Chenge_Estimate_Send();
    //void refresh_Estimate();

    void on_back_main_menu_clicked();

    void on_Quotations_clicked();
    void on_Quotations_Send();

    void on_Add_my_book_clicked();

    void on_pushButton_clicked();

    void on_Del_my_book_clicked();

signals:
    void sendBookName_Estimate(QString str,QString est,int w);
    void sendName(QString str);
};

#endif // BOOK_H
