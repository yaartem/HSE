#ifndef ADDINGBOOK_H
#define ADDINGBOOK_H

#include <QDialog>
#include <QFile>
#include <QString>
#include "dialog.h"

namespace Ui {
class AddingBook;
}

class AddingBook : public QDialog
{
    Q_OBJECT

public:
    explicit AddingBook(QWidget *parent = nullptr, QVector<Book> *books={});
    ~AddingBook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddingBook *ui;
    QVector<Book> *b;
};

#endif // ADDINGBOOK_H
