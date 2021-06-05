#ifndef DELETINGBOOK_H
#define DELETINGBOOK_H

#include <QDialog>

namespace Ui {
class DeletingBook;
}

class DeletingBook : public QDialog
{
    Q_OBJECT

public:
    explicit DeletingBook(QWidget *parent = nullptr);
    ~DeletingBook();

private:
    Ui::DeletingBook *ui;
};

#endif // DELETINGBOOK_H
