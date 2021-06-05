#include "review.h"
#include "ui_review.h"
#include "dialog.h"

Review::Review(QWidget *parent,  int idx, QVector<Book> *books) :
    QDialog(parent),
    ui(new Ui::Review)
{
    ui->setupUi(this);

    i=idx;
    b=books;
    Book x = b->at(i);

    ui->textEdit->setText(x.GetPersonalReview());
    ui->lineEdit->setText(QString::number(x.GetPersonalRating()));
}

Review::~Review()
{
    delete ui;
}

void Review::on_pushButton_clicked()
{
   Book x = b->at(i);
   x.SetPersonalReview(ui->textEdit->toPlainText());
   x.SetPersonalRating((ui->lineEdit->text()).toInt());
   x.SetRating((x.GetRating()*x.GetReviews()+x.GetPersonalRating())/(x.GetReviews()+1));
   x.SetReviews(x.GetReviews()+1);
   b->append(x);
   b->swapItemsAt(i, b->length()-1);
   b->resize(b->size()-1);
   close();
}
