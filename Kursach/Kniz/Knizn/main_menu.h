#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>
#include <find_book.h>
#include <ui_find_book.h>
#include "my_books.h"
#include "my_reviews.h"


namespace Ui {
class main_menu;
}

class main_menu : public QWidget
{
    Q_OBJECT

public:
    explicit main_menu(QWidget *parent = 0);
    ~main_menu();


private slots:
    void on_findBook_clicked();

    void on_my_bookss_clicked();

    void on_My_quotations_clicked();

    void on_My_reviews_clicked();

private:
    Ui::main_menu *ui;
};

#endif // MAIN_MENU_H
