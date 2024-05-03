#ifndef SYW_H
#define SYW_H

#include <QWidget>

namespace Ui {
class SYW;
}

class SYW : public QWidget
{
    Q_OBJECT

public:
    explicit SYW(QWidget *parent = nullptr);
    ~SYW();

    int kind=0;
    int sha,guan,bei;
    int isExist;
    int level;
    int a,b,c,d;
    SYW *syw=NULL;

    double sumatt[10];
    int countatt[40];
    int mainrand[3];

    int checkKind(int a);
    void showAttribute1(int a1);
    void showAttribute2(int a2);
    void showAttribute3(int a3);
    void showAttribute4(int a4);

    void printatt();
    void showname();
    void showmainatt();

    void calsumatt(int *arr);

private slots:
    void on_againBtn_clicked();

    void on_fourBtn_clicked();

    void on_twentyBtn_clicked();

private:
    Ui::SYW *ui;
};

#endif // SYW_H
