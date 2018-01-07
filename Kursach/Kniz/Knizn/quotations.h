#ifndef QUOTATIONS_H
#define QUOTATIONS_H

#include "book.h"
#include "edit_quote.h"
#include "add_quote.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class Quotations;
}

class Quotations : public QWidget
{
    Q_OBJECT

public:
    explicit Quotations(QWidget *parent = 0);
    ~Quotations();
    QString name_book;
    QString quote;
    QString user;
    QMessageBox* mes;

private:
    Ui::Quotations *ui;
     QSqlQueryModel *model;

public slots:
    void recieveName(QString str);
    void Name_Send();
    void Name_Quote_Send();
private slots:
    void on_Book_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_findQuote_clicked();

    void on_findUser_clicked();

    void on_My_Quote_clicked();

    void on_Chenge_Quote_clicked();

    void on_Add_clicked();

signals:
    void sendName(QString str);
    void sendName_Quote(QString str,QString str2);
};

#endif // QUOTATIONS_H
