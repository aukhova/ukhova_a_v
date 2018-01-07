#ifndef MY_REVIEWS_H
#define MY_REVIEWS_H

#include "book.h"
#include "edit_review.h"
#include "main_menu.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class My_Reviews;
}

class My_Reviews : public QWidget
{
    Q_OBJECT

public:
    explicit My_Reviews(QWidget *parent = 0);
    ~My_Reviews();
    QString name_book;
    QString review;
    QMessageBox* mes;

private:
    Ui::My_Reviews *ui;
    QSqlQueryModel *model;

public slots:
    void Name_Send();
    void Name_Review_Send();

private slots:
    void on_Book_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_findReview_clicked();

    void on_Chenge_Review_clicked();

    void on_back_main_menu_clicked();

signals:
    void sendName(QString str);
    void sendName_Review(QString str,QString str2,int w);
};

#endif // MY_REVIEWS_H
