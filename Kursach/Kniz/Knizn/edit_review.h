#ifndef EDIT_REVIEW_H
#define EDIT_REVIEW_H

#include "reviews.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class Edit_Review;
}

class Edit_Review : public QWidget
{
    Q_OBJECT

public:
    explicit Edit_Review(QWidget *parent = 0);
    ~Edit_Review();
    QString name_book;
    QString review;
    QMessageBox* mes;
    int where;

public slots:
    void recieveName(QString str,QString str2,int w);
    void Name_Send();

private:
    Ui::Edit_Review *ui;
    QSqlQueryModel *model;

signals:
    void sendName(QString str);
private slots:
    void on_back_clicked();
    void on_chenge_clicked();
    void on_del_clicked();
};

#endif // EDIT_REVIEW_H
