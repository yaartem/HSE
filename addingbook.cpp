#include "addingbook.h"
#include "ui_addingbook.h"

#include <iostream>
#include <QString>
#include <QTextStream>

AddingBook::AddingBook(QWidget *parent, QVector<Book> *books) :
    QDialog(parent),
    ui(new Ui::AddingBook)
{
    ui->setupUi(this);
    b=books;
}

AddingBook::~AddingBook()
{
    delete ui;
}

void AddingBook::on_pushButton_clicked()
{
    QString l=ui->lineEdit->text()+","+ui->lineEdit_2->text()+","+ui->lineEdit_3->text()+","+
            ui->lineEdit_4->text()+","+ui->lineEdit_5->text()+","+ui->lineEdit_6->text()+","+ui->lineEdit_7->text();
    b->append(Book(l, ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(),
                   (ui->lineEdit_4->text()).toFloat(), (ui->lineEdit_5->text()).toInt(), ui->lineEdit_6->text(), ui->lineEdit_7->text()));
    close();
}
