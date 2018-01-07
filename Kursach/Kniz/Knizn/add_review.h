#ifndef ADD_REVIEW_H
#define ADD_REVIEW_H

#include "reviews.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class Add_Review;
}

class Add_Review : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Review(QWidget *parent = 0);
    ~Add_Review();
    QString name_book;
    QMessageBox* mes;

public slots:
    void recieveName(QString str);
    void Name_Send();

private slots:
    void on_back_clicked();

    void on_Add_clicked();

private:
    Ui::Add_Review *ui;
    QSqlQueryModel *model;

signals:
    void sendName(QString str);
};

#endif // ADD_REVIEW_H
