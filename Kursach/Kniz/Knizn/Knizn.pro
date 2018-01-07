#-------------------------------------------------
#
# Project created by QtCreator 2017-12-23T21:04:10
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Knizn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    main_menu.cpp \
    find_book.cpp \
    find_book_by_author.cpp \
    find_book_by_name.cpp \
    authors_books.cpp \
    book.cpp \
    edit_estimate.cpp \
    my_books.cpp \
    quotations.cpp \
    edit_quote.cpp \
    add_quote.cpp \
    my_quotations.cpp \
    reviews.cpp \
    edit_review.cpp \
    add_review.cpp \
    my_reviews.cpp \
    registration.cpp

HEADERS  += mainwindow.h \
    login.h \
    main_menu.h \
    find_book.h \
    find_book_by_author.h \
    find_book_by_name.h \
    authors_books.h \
    book.h \
    edit_estimate.h \
    my_books.h \
    quotations.h \
    edit_quote.h \
    add_quote.h \
    my_quotations.h \
    reviews.h \
    edit_review.h \
    add_review.h \
    my_reviews.h \
    registration.h

FORMS    += mainwindow.ui \
    login.ui \
    main_menu.ui \
    find_book.ui \
    find_book_by_author.ui \
    find_book_by_name.ui \
    book.ui \
    edit_estimate.ui \
    my_books.ui \
    quotations.ui \
    authors_books.ui \
    edit_quote.ui \
    add_quote.ui \
    my_quotations.ui \
    reviews.ui \
    edit_review.ui \
    add_review.ui \
    my_reviews.ui \
    registration.ui
