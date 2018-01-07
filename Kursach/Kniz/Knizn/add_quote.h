#ifndef ADD_QUOTE_H
#define ADD_QUOTE_H


#include "quotations.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class Add_Quote;
}

class Add_Quote : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Quote(QWidget *parent = 0);
    ~Add_Quote();
    QString name_book;
    QMessageBox* mes;


public slots:
    void recieveName(QString str);
    void Name_Send();

private slots:
    void on_back_clicked();

    void on_Add_clicked();

private:
    Ui::Add_Quote *ui;
    QSqlQueryModel *model;

signals:
    void sendName(QString str);
};

#endif // ADD_QUOTE_H
