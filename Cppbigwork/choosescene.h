#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QWidget>
#include"syw.h"

namespace Ui {
class chooseScene;
}

class chooseScene : public QWidget
{
    Q_OBJECT

public:
    explicit chooseScene(QWidget *parent = nullptr);
    ~chooseScene();

    SYW *syw=NULL;

private slots:
    void on_jueyuan_btn_clicked();

private:
    Ui::chooseScene *ui;
};

#endif // CHOOSESCENE_H
