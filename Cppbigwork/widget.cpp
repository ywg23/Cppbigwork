#include "widget.h"
#include "ui_widget.h"
#include<QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("圣遗物强化模拟器");
    QIcon winicon("D:\\QT_Project\\Cppbigwork\\02");
    setWindowIcon(winicon);

    QPixmap pix("D:\\QT_Project\\Cppbigwork\\20240501102753");
    ui->label->setPixmap(pix);

    QIcon iconbtn("D:\\QT_Project\\Cppbigwork\\01");
    ui->startButton->setIcon(iconbtn);
    cs=new chooseScene;
}

Widget::~Widget()
{
    delete ui;

}


void Widget::on_startButton_clicked()
{
        this->hide();
        cs->show();
}
