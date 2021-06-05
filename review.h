#ifndef REVIEW_H
#define REVIEW_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class Review;
}

class Review : public QDialog
{
    Q_OBJECT

public:
    explicit Review(QWidget *parent = nullptr, int idx=0, QVector<Book> *books={});
    ~Review();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Review *ui;
    int i;
    QVector<Book> *b;
};

#endif // REVIEW_H
