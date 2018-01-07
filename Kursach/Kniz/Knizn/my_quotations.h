#ifndef MY_QUOTATIONS_H
#define MY_QUOTATIONS_H

#include "book.h"
#include "edit_quote.h"
#include "main_menu.h"
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class My_Quotations;
}

class My_Quotations : public QWidget
{
    Q_OBJECT

public:
    explicit My_Quotations(QWidget *parent = 0);
    ~My_Quotations();
    QString name_book;
    QString quote;
    QMessageBox* mes;

private:
    Ui::My_Quotations *ui;
    QSqlQueryModel *model;

public slots:
    void Name_Send();
    void Name_Quote_Send();

private slots:
    void on_Book_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_findQuote_clicked();

    void on_Chenge_Quote_clicked();

    void on_back_main_menu_clicked();

signals:
    void sendName(QString str);
    void sendName_Quote(QString str,QString str2,int w);
};

#endif // MY_QUOTATIONS_H
