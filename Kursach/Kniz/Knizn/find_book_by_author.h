#ifndef FIND_BOOK_BY_AUTHOR_H
#define FIND_BOOK_BY_AUTHOR_H

#include "find_book.h"
#include "ui_find_book.h"
#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include "authors_books.h"

namespace Ui {
class find_book_by_author;
}

class find_book_by_author : public QWidget
{
    Q_OBJECT

public:
    explicit find_book_by_author(QWidget *parent = 0);
    ~find_book_by_author();

    QString name;
   // Authors_books *au_books;
    QMessageBox* mes;

private slots:
    void on_findAuthor_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_back_clicked();

     void on_show_books_Send();

     void on_show_books_clicked();

signals:
    void sendName(QString str);


private:
    Ui::find_book_by_author *ui;
    QSqlQueryModel *model;
};

#endif // FIND_BOOK_BY_AUTHOR_H
