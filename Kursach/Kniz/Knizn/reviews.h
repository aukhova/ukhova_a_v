#ifndef REVIEWS_H
#define REVIEWS_H

#include "book.h"
#include "edit_review.h"
#include "add_review.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class Reviews;
}

class Reviews : public QWidget
{
    Q_OBJECT

public:
    explicit Reviews(QWidget *parent = 0);
    ~Reviews();
    QString name_book;
    QString review;
    QString user;
    QMessageBox* mes;

private:
    Ui::Reviews *ui;
    QSqlQueryModel *model;

public slots:
    void recieveName(QString str);
    void Name_Send();
    void Name_Review_Send();
private slots:
    void on_Book_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_findReview_clicked();

    void on_findUser_clicked();

    //void on_Add_clicked();

    void on_My_Reviews_clicked();

    void on_Chenge_Review_clicked();

    void on_Add_clicked();

signals:
    void sendName(QString str);
    void sendName_Review(QString str,QString str2);
};

#endif // REVIEWS_H
