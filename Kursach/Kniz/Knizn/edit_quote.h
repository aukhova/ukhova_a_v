#ifndef EDIT_QUOTE_H
#define EDIT_QUOTE_H

#include "quotations.h"
#include "my_quotations.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class Edit_Quote;
}

class Edit_Quote : public QWidget
{
    Q_OBJECT

public:
    explicit Edit_Quote(QWidget *parent = 0);
    ~Edit_Quote();
    QString name_book;
    QString quote;
    QMessageBox* mes;
    int where;

public slots:
    void recieveName(QString str,QString str2,int w);
    void Name_Send();

private:
    Ui::Edit_Quote *ui;
    QSqlQueryModel *model;

signals:
    void sendName(QString str);
private slots:
    void on_back_clicked();
    void on_chenge_clicked();
    void on_del_clicked();
};

#endif // EDIT_QUOTE_H
