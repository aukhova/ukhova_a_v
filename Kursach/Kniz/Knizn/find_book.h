#ifndef FIND_BOOK_H
#define FIND_BOOK_H

#include <QWidget>
#include "main_menu.h"
#include "ui_main_menu.h"
#include "find_book_by_author.h"
#include "ui_find_book_by_author.h"
#include "find_book_by_name.h"
#include "ui_find_book_by_name.h"


namespace Ui {
class find_book;
}

class find_book : public QWidget
{
    Q_OBJECT

public:
    explicit find_book(QWidget *parent = 0);
    ~find_book();

private slots:
    void on_back_clicked();

    void on_find_book_by_authors_clicked();

    void on_find_book_by_names_clicked();

private:
    Ui::find_book *ui;
};

#endif // FIND_BOOK_H
