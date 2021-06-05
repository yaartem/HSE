#include "about.h"
#include "ui_about.h"

#include <QWidget>
#include <QLabel>

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    render = new RenderArea(ui->widget);

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(render->sizePolicy().hasHeightForWidth());
        render->setSizePolicy(sizePolicy);
        QHBoxLayout* horLayout = new QHBoxLayout(ui->widget); //(centralwidget);
        horLayout -> addWidget(render);
}

About::~About()
{
    delete ui;
}
