#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVector>
#include <QVectorIterator>

class Book
{
private:
    QString Name;
    QString Author;
    QString Genre;
    float Rating;
    int Reviews;
    QString Price;
    QString Year;

public:
    Book()
    {
        this->Name="";
        this->Author="";
        this->Genre="";
        this->Rating=0;
        this->Reviews=0;
        this->Price="";
        this->Year="";
    }
    Book(QString Name, QString Author,QString Genre, float Rating, int Reviews, QString Price, QString Year)
    {
        this->Name=Name;
        this->Author=Author;
        this->Genre=Genre;
        this->Rating=Rating;
        this->Reviews=Reviews;
        this->Price=Price;
        this->Year=Year;
    }
    void SetName(QString Name){this->Name=Name;}
    void SetAuthor(QString Author){this->Author=Author;}
    void SetGenre(QString Genre){this->Genre=Genre;}
    void SetRating(float Rating){this->Rating=Rating;}
    void SetReviews(int Reviews){this->Reviews=Reviews;}
    void SetPrice(QString Price){this->Price=Price;}
    void SetYear(QString Year){this->Year=Year;}

    QString GetName(){return this->Name;}
    QString GetAuthor(){return this->Author;}
    QString GetGenre(){return this->Genre;}
    float GetRating(){return this->Rating;}
    int GetReviews(){return this->Reviews;}
    QString GetPrice(){return this->Price;}
    QString GetYear(){return this->Year;}
};



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, QModelIndex *idx=0, QVector<Book> *books={});
    ~Dialog();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    int i;
    QVector<Book> *b;
};

#endif // DIALOG_H
