#include "syw.h"
#include "ui_syw.h"
#include<QIcon>
#include<QTime>
#include<QtGlobal>

SYW::SYW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SYW)
{
    ui->setupUi(this);
    setWindowTitle("圣遗物强化模拟器");
    QIcon winicon("D:\\QT_Project\\Cppbigwork\\02");
    setWindowIcon(winicon);

    QTime time=QTime::currentTime();
    qsrand(time.msec()*1000+time.second()*1000);
    kind=qrand()%5+4;

    guan=qrand()%100+1;

    QString n=QString::number(kind);
    QString str="D:\\QT_Project\\Cppbigwork\\0";
    str+=n;

    ui->label->setPixmap(QPixmap(str));

    QFont font1;
    font1.setFamily("华文新魏");
    font1.setPointSize(14);
    ui->mainAttribute->setFont(font1);

    QFont font2;
    font1.setFamily("华文新魏");
    font1.setPointSize(18);
    ui->name->setFont(font1);

    level=0;
    for(int i=0;i<10;i++)
        sumatt[i]=0;
    for(int i=0;i<40;i++)
        countatt[i]=0;

    int att[4];
    int flag[4];
    att[0]=qrand()%40+1;
    countatt[att[0]-1]++;
    flag[0]=checkKind(att[0]);

    flag[1]=flag[0];
    flag[2]=flag[0];
    flag[3]=flag[0];

    while(flag[1]==flag[0])
    {
       att[1]=qrand()%40+1;
       flag[1]=checkKind(att[1]);
    }
    countatt[att[1]-1]++;
    while(flag[2]==flag[0]||flag[2]==flag[1])
    {
       att[2]=qrand()%40+1;
       flag[2]=checkKind(att[2]);
    }
    countatt[att[2]-1]++;
    while(flag[3]==flag[0]||flag[3]==flag[1]||flag[3]==flag[2])
    {
       att[3]=qrand()%40+1;
       flag[3]=checkKind(att[3]);
    }
    countatt[att[3]-1]++;

    calsumatt(countatt);
    for(int i=0;i<10;i++)
    {
        if(sumatt[i]!=0)
        {
            a=i;
            break;
        }
    }
    for(int i=a+1;i<10;i++)
    {
        if(sumatt[i]!=0)
        {
            b=i;
            break;
        }
    }
    for(int i=b+1;i<10;i++)
    {
        if(sumatt[i]!=0)
        {
            c=i;
            break;
        }
    }
    for(int i=c+1;i<10;i++)
    {
        if(sumatt[i]!=0)
        {
            d=i;
            break;
        }
    }

    printatt();

    QTime time1=QTime::currentTime();
    qsrand(time1.msec()*1000+time1.second()*1000);
    this->isExist=qrand()%10+1;

    showname();
    showmainatt();


}
void SYW::showname()
{
    switch(kind)
    {
        case 4:{
        ui->name->setText(QString("明威之镡 +%1").arg(level));
        break;
    }
    case 5:{
        ui->name->setText(QString("华饰之兜 +%1").arg(level));
        break;
    }
    case 6:{
        ui->name->setText(QString("雷云之笼 +%1").arg(level));
        int M=qrand()%30+1;
        if(M<=8)
            ui->mainAttribute->setText("生命值 7.0%");
        else if(M<=16)
            ui->mainAttribute->setText("攻击力 7.0%");
        else if(M<=24)
            ui->mainAttribute->setText("防御力 8.7%");
        else if(M<=27)
            ui->mainAttribute->setText("元素精通 28");
        else
            ui->mainAttribute->setText("元素充能效率 7.8%");
        break;}
    case 7:{
        ui->name->setText(QString("切落之羽 +%1").arg(level));
        ui->mainAttribute->setText("攻击力 47");
        break;}
    case 8:{
        ui->name->setText(QString("绯花之壶 +%1").arg(level));
        int M=qrand()%100000+1;
        if(M<=17)
            ui->mainAttribute->setText("生命值 7.0%");
        else if(M<=34)
            ui->mainAttribute->setText("攻击力 7.0%");
        else if(M<=50)
            ui->mainAttribute->setText("防御力 8.7%");
        else if(M<=52)
            ui->mainAttribute->setText("元素精通 28");
        else if(M<=56)
            ui->mainAttribute->setText("火元素伤害加成 7.0%");
        else if(M<=60)
            ui->mainAttribute->setText("水元素伤害加成 7.0%");
        else if(M<=64)
            ui->mainAttribute->setText("雷元素伤害加成 7.0%");
        else if(M<=68)
            ui->mainAttribute->setText("冰元素伤害加成 7.0%");
        else if(M<=72)
            ui->mainAttribute->setText("岩元素伤害加成 7.0%");
        else if(M<=56)
            ui->mainAttribute->setText("草元素伤害加成 7.0%");
        else
            ui->mainAttribute->setText("风元素伤害加成 7.0%");
        break;}
    }
}

void SYW::showmainatt()
{
    if(kind==4)
    {
        ui->mainAttribute->setText(QString("生命值 %1").arg(int(717+812.6*level)));
    }
    else if(kind==5)
    {
        if(guan<=22)
            ui->mainAttribute->setText(QString("生命值 %1").arg(7.0+level*7.92,1)+"%");
        else if(guan<=44)
            ui->mainAttribute->setText(QString("攻击力 %1").arg(7.0+level*7.92,1)+"%");
        else if(guan<=66)
            ui->mainAttribute->setText(QString("防御力 %1").arg(7.0+level*9.92,1)+"%");
        else if(guan<=76)
            ui->mainAttribute->setText(QString("治疗加成 %1").arg(5.6+level*6.06,1)+"%");
        else if(guan<=86)
            ui->mainAttribute->setText(QString("暴击伤害 %1").arg(9.3+level*7.92,1)+"%";
        else if(guan<=96)
            ui->mainAttribute->setText("暴击率 4.7%");
        else
            ui->mainAttribute->setText("元素精通 28");
    }
}

void SYW::showAttribute1(int a)
 {
     switch(a)
     {
         case 0:ui->attribute1->setText(QString("攻击力 %1").arg(sumatt[0]));break;
         case 1:ui->attribute1->setText(QString("攻击力 %1").arg(sumatt[1])+"%");break;
         case 2:ui->attribute1->setText(QString("生命值 %1").arg(sumatt[2]));break;
         case 3:ui->attribute1->setText(QString("生命值 %1").arg(sumatt[3])+"%");break;
         case 4:ui->attribute1->setText(QString("防御力 %1").arg(sumatt[4]));break;
         case 5:ui->attribute1->setText(QString("防御力 %1").arg(sumatt[5])+"%");break;
         case 6:ui->attribute1->setText(QString("暴击伤害 %1").arg(sumatt[6])+"%");break;
         case 7:ui->attribute1->setText(QString("暴击率 %1").arg(sumatt[7])+"%");break;
         case 8:ui->attribute1->setText(QString("元素充能效率 %1").arg(sumatt[8])+"%");break;
         case 9:ui->attribute1->setText(QString("元素精通 %1").arg(sumatt[9]));break;
     }
 }
void SYW::showAttribute2(int a)
 {
     switch(a)
     {
         case 0:ui->attribute2->setText(QString("攻击力 %1").arg(sumatt[0]));break;
         case 1:ui->attribute2->setText(QString("攻击力 %1").arg(sumatt[1])+"%");break;
         case 2:ui->attribute2->setText(QString("生命值 %1").arg(sumatt[2]));break;
         case 3:ui->attribute2->setText(QString("生命值 %1").arg(sumatt[3])+"%");break;
         case 4:ui->attribute2->setText(QString("防御力 %1").arg(sumatt[4]));break;
         case 5:ui->attribute2->setText(QString("防御力 %1").arg(sumatt[5])+"%");break;
         case 6:ui->attribute2->setText(QString("暴击伤害 %1").arg(sumatt[6])+"%");break;
         case 7:ui->attribute2->setText(QString("暴击率 %1").arg(sumatt[7])+"%");break;
         case 8:ui->attribute2->setText(QString("元素充能效率 %1").arg(sumatt[8])+"%");break;
         case 9:ui->attribute2->setText(QString("元素精通 %1").arg(sumatt[9]));break;
     }
 }
void SYW::showAttribute3(int a)
{
     switch(a)
     {
         case 0:ui->attribute3->setText(QString("攻击力 %1").arg(sumatt[0]));break;
         case 1:ui->attribute3->setText(QString("攻击力 %1").arg(sumatt[1])+"%");break;
         case 2:ui->attribute3->setText(QString("生命值 %1").arg(sumatt[2]));break;
         case 3:ui->attribute3->setText(QString("生命值 %1").arg(sumatt[3])+"%");break;
         case 4:ui->attribute3->setText(QString("防御力 %1").arg(sumatt[4]));break;
         case 5:ui->attribute3->setText(QString("防御力 %1").arg(sumatt[5])+"%");break;
         case 6:ui->attribute3->setText(QString("暴击伤害 %1").arg(sumatt[6])+"%");break;
         case 7:ui->attribute3->setText(QString("暴击率 %1").arg(sumatt[7])+"%");break;
         case 8:ui->attribute3->setText(QString("元素充能效率 %1").arg(sumatt[8])+"%");break;
         case 9:ui->attribute3->setText(QString("元素精通 %1").arg(sumatt[9]));break;
     }
 }

void SYW::showAttribute4(int a)
{
    if(isExist<=8)
        return;
     switch(a)
     {
         case 0:ui->attribute4->setText(QString("攻击力 %1").arg(sumatt[0]));break;
         case 1:ui->attribute4->setText(QString("攻击力 %1").arg(sumatt[1])+"%");break;
         case 2:ui->attribute4->setText(QString("生命值 %1").arg(sumatt[2]));break;
         case 3:ui->attribute4->setText(QString("生命值 %1").arg(sumatt[3])+"%");break;
         case 4:ui->attribute4->setText(QString("防御力 %1").arg(sumatt[4]));break;
         case 5:ui->attribute4->setText(QString("防御力 %1").arg(sumatt[5])+"%");break;
         case 6:ui->attribute4->setText(QString("暴击伤害 %1").arg(sumatt[6])+"%");break;
         case 7:ui->attribute4->setText(QString("暴击率 %1").arg(sumatt[7])+"%");break;
         case 8:ui->attribute4->setText(QString("元素充能效率 %1").arg(sumatt[8])+"%");break;
         case 9:ui->attribute4->setText(QString("元素精通 %1").arg(sumatt[9]));break;
     }
 }
int SYW::checkKind(int a)
{
    if(a<=4)
        return 1;
    if(a<=8)
        return 2;
    if(a<=12)
        return 3;
    if(a<=16)
        return 4;
    if(a<=20)
        return 5;
    if(a<=24)
        return 6;
    if(a<=28)
        return 7;
    if(a<=32)
        return 9;
    if(a<=36)
        return 10;
    if(a<=40)
        return 11;
}

void SYW::calsumatt(int *arr)
{
    sumatt[0]=arr[0]*14+arr[1]*16+arr[2]*18+arr[3]*19;
    sumatt[1]=arr[4]*4.1+arr[5]*4.7+arr[6]*5.3+arr[7]*5.8;
    sumatt[2]=arr[8]*209+arr[9]*239+arr[10]*269+arr[11]*299;
    sumatt[3]=arr[12]*4.1+arr[13]*4.7+arr[14]*5.3+arr[15]*5.8;
    sumatt[4]=arr[16]*16+arr[17]*19+arr[18]*21+arr[19]*23;
    sumatt[5]=arr[20]*5.1+arr[21]*5.8+arr[22]*6.6+arr[23]*7.3;
    sumatt[6]=arr[24]*5.4+arr[25]*6.2+arr[26]*7.0+arr[27]*7.8;
    sumatt[7]=arr[28]*2.7+arr[29]*3.1+arr[30]*3.5+arr[31]*3.9;
    sumatt[8]=arr[32]*4.5+arr[33]*5.2+arr[34]*5.8+arr[35]*6.5;
    sumatt[9]=arr[36]*16+arr[37]*19+arr[38]*21+arr[39]*23;
}
SYW::~SYW()
{
    delete ui;
}

void SYW::printatt()
{

    //随机舍去一词条
    if(isExist<=8)
    {
        int m=qrand()%4+1;
    switch(m)
    {
        case 1:
        {
        showAttribute1(a);
        showAttribute2(b);
        showAttribute3(c);
        showAttribute4(d);
        break;
        }
        case 2:
        {
            showAttribute1(a);
            showAttribute2(b);
            showAttribute3(d);
            showAttribute4(c);
            break;
        }
        case 3:
        {
            showAttribute1(a);
            showAttribute2(c);
            showAttribute3(d);
            showAttribute4(b);
            break;
        }
        default:
        {
        showAttribute1(b);
        showAttribute2(c);
        showAttribute3(d);
        showAttribute4(a);
        break;
        }
     }
    }
    else
    {
        showAttribute1(a);
        showAttribute2(b);
        showAttribute3(c);
        showAttribute4(d);
    }
}


void SYW::on_againBtn_clicked()
{

    if(syw!=NULL)
    {
        delete syw;
        syw=NULL;
    }
    syw= new SYW;
    syw->show();
    this->hide();
}

void SYW::on_fourBtn_clicked()
{

    if(level<=16)
    {
        if(isExist<=8)
        {
            isExist=9;
            printatt();
        }
    else{

        int m=qrand()%16+1;
        if(m<=4)
            countatt[m+a*4]++;
        else if(m<=8)
            countatt[m%4+b*4]++;
        else if(m<=12)
            countatt[m%4+c*4]++;
        else
            countatt[m%4+d*4]++;
        calsumatt(countatt);
        printatt();
    }
         level+=4;
         showname();

    }


}

void SYW::on_twentyBtn_clicked()
{
    on_fourBtn_clicked();
    on_fourBtn_clicked();
    on_fourBtn_clicked();
    on_fourBtn_clicked();
    on_fourBtn_clicked();
}
