#include "choosescene.h"
#include "ui_choosescene.h"
#include<QIcon>

chooseScene::chooseScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseScene)
{
    ui->setupUi(this);
    setWindowTitle("圣遗物强化模拟器");
    QIcon winicon("D:\\QT_Project\\Cppbigwork\\02");
    setWindowIcon(winicon);


    ui->jueyuan_btn->setIcon(QIcon("D:\\QT_Project\\Cppbigwork\\04"));

    syw =new SYW;

}

chooseScene::~chooseScene()
{
    delete ui;
}

void chooseScene::on_jueyuan_btn_clicked()
{

    syw->show();
    this->hide();
}
