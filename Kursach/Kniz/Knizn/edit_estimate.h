#ifndef EDIT_ESTIMATE_H
#define EDIT_ESTIMATE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include "book.h"

namespace Ui {
class Edit_Estimate;
}

class Edit_Estimate : public QWidget
{
    Q_OBJECT

public:
    explicit Edit_Estimate(QWidget *parent = 0);
    ~Edit_Estimate();
    QString name_book;
    QString estimat;

public slots:
    void recieveBookName_Estimate(QString str,QString est);

private slots:
    void on_Edit_clicked();
     void Name_Send();;

private:
    Ui::Edit_Estimate *ui;
    QSqlQueryModel *model;
signals:
    void sendName(QString str);
};

#endif // EDIT_ESTIMATE_H
