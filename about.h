#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include "renderarea.h"

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;
    RenderArea* render;
};

#endif // ABOUT_H
