#ifndef MY_BOOKS_H
#define MY_BOOKS_H

#include "find_book.h"
#include "book.h"
#include <QWidget>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>


namespace Ui {
class My_Books;
}

class My_Books : public QWidget
{
    Q_OBJECT

public:
    explicit My_Books(QWidget *parent = 0);
    ~My_Books();
    QString name_book;
    QMessageBox* mes;

private slots:
    void on_find_book_clicked();
    void on_columnView_clicked(const QModelIndex &index);
    void on_back_clicked();
    void on_show_book_clicked();
    void on_show_book_Send();

private:
    Ui::My_Books *ui;
     QSqlQueryModel *model;

signals:
    void sendName(QString str);
};

#endif // MY_BOOKS_H
