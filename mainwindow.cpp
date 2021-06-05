#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include "dialog.h"
#include "addingbook.h"

#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QWidget>
#include <QList>
#include <QStandardItemModel>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    csv = new QStandardItemModel(0, 1, parent);

    csv->setColumnCount(1);
    csv->setHorizontalHeaderLabels(QStringList() << "Name");

    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(csv);

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    About *ab = new About();
    ab->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString Name;
    QString Author;
    QString Genre;
    float Rating;
    int Reviews;
    QString Price;
    QString Year;

    QString fileName = QFileDialog::getOpenFileName(this,"Open File","*.txt");
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        file.readLine();
        int row = 0;


        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QList<QByteArray> lineAsVector = line.split(',');

            csv->insertRows(row, 1);
            csv->setData(csv->index(row, 0), QString(lineAsVector.at(0)));
            Name = QString(lineAsVector.at(0));
            Author = QString(lineAsVector.at(1));
            Genre = QString(lineAsVector.at(6));
            Rating = (lineAsVector.at(2)).toFloat();
            Reviews = (lineAsVector.at(3)).toInt();
            Price = QString(lineAsVector.at(4));
            Year = QString(lineAsVector.at(5));
            books.append(Book(Name,Author,Genre,Rating,Reviews,Price,Year));
            row++;
        }
        file.close();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QModelIndex idx = proxyModel->mapToSource(index);
    Dialog *d = new Dialog(this, &idx, &books);
    d->show();
}

void MainWindow::on_pushButton_clicked()
{
    AddingBook *a = new AddingBook(this, &books);
    a->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    if (books.length()>( ui->tableView->model()->rowCount()))
    {
        int i = 1;
        QString fileName = QFileDialog::getOpenFileName(this,"File in which to add book","*.txt");
        while(books.length() > ui->tableView->model()->rowCount())
        {
            Book x = books.at(books.length()-i);
            QFile file(fileName);
            file.open(QIODevice::ReadOnly);
            QByteArray f = file.readAll();
            file.close();
            f.append("\n");
            f.append((x.GetName()+","+x.GetAuthor()+","+QString::number(x.GetRating())+","+QString::number(x.GetReviews())+
                      ","+x.GetPrice()+","+x.GetYear()+","+x.GetGenre()).toUtf8());
            if (file.open(QIODevice::WriteOnly))
            {
                file.write(f);
            }
            file.close();
            csv->insertRows(ui->tableView->model()->rowCount()-1, 1);
            csv->setData(csv->index(ui->tableView->model()->rowCount()-1, 0), x.GetName());
            file.close();
            i++;
        }
    }
    else if(books.length()<(ui->tableView->model()->rowCount()))
    {
        int i = 1;
        QString fileName = QFileDialog::getOpenFileName(this,"File in which to add book","*.txt");
        while(books.length() > ui->tableView->model()->rowCount())
        {
            Book x = books.at(books.length()-i);
            QFile file(fileName);
            file.open(QIODevice::ReadOnly);
            QByteArray f = file.readAll();
            file.close();
            if (file.open(QIODevice::WriteOnly))
            {
                file.write(f);
            }
            file.close();
            csv->insertRows(ui->tableView->model()->rowCount()-1, 1);
            csv->setData(csv->index(ui->tableView->model()->rowCount()-1, 0), x.GetName());
            file.close();
            i++;
        }
    }
}
