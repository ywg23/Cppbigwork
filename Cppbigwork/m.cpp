#include "m.h"
#include "ui_m.h"
#include "mark.h"

m::m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::m)
{
    ui->setupUi(this);
    ui->label->setPixmap()
}

m::~m()
{
    delete ui;
}
