#include "deletingbook.h"
#include "ui_deletingbook.h"

DeletingBook::DeletingBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeletingBook)
{
    ui->setupUi(this);
}

DeletingBook::~DeletingBook()
{
    delete ui;
}
