#ifndef AUTHORS_BOOKS_H
#define AUTHORS_BOOKS_H

#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QMessageBox>
#include "find_book_by_author.h"
#include "book.h"

namespace Ui {
class Authors_books;
}

class Authors_books : public QWidget
{
    Q_OBJECT

public:
    explicit Authors_books(QWidget *parent = 0);
    ~Authors_books();
    QString name;
    QString name_book;
    QMessageBox* mes;

private:
    Ui::Authors_books *ui;
    QSqlQueryModel *model;
public slots:
    void recieveName(QString str);
    void on_columnView_clicked(const QModelIndex &index);

private slots:
    void on_back_clicked();
    void on_show_book_clicked();
    void on_show_book_Send();
signals:
    void sendName(QString str);
};

#endif // AUTHORS_BOOKS_H
