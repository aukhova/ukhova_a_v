#ifndef FIND_BOOK_BY_NAME_H
#define FIND_BOOK_BY_NAME_H

#include "find_book.h"
#include "book.h"
#include <QWidget>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>


namespace Ui {
class find_book_by_name;
}

class find_book_by_name : public QWidget
{
    Q_OBJECT

public:
    explicit find_book_by_name(QWidget *parent = 0);
    ~find_book_by_name();

    QString name_book;
    QMessageBox* mes;

private slots:
    void on_find_book_clicked();

    void on_columnView_clicked(const QModelIndex &index);

    void on_back_clicked();

    void on_show_book_clicked();

    void on_show_book_Send();

private:
    Ui::find_book_by_name *ui;
    QSqlQueryModel *model;

signals:
    void sendName(QString str);
};

#endif // FIND_BOOK_BY_NAME_H
