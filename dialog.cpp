#include "dialog.h"
#include "ui_dialog.h"

#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QWidget>
#include <QList>
#include <QStandardItemModel>
#include <QTextStream>
#include <QString>
#include <QVectorIterator>

Dialog::Dialog(QWidget *parent, QModelIndex *idx, QVector<Book> *books) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    i=(idx->row());
    b=books;

    Book x = books->at(i);
    ui->label_8->setText(x.GetName());
    ui->label_9->setText(x.GetAuthor());
    ui->label_14->setText(x.GetGenre());
    ui->label_10->setText(QString::number(x.GetRating()));
    ui->label_11->setText(QString::number(x.GetReviews()));
    ui->label_12->setText(x.GetPrice()+"$");
    ui->label_13->setText(x.GetYear());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_3_clicked()
{
    QVector<Book>::Iterator itr = b->begin()+i;
    b->erase(itr);
    close();
}
