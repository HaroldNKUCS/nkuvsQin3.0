#ifndef PLAYSCENCE_H
#define PLAYSCENCE_H

#include <QMainWindow>
#include<mycoin.h>
class playscence : public QMainWindow
{
    Q_OBJECT
public:
//    explicit playscence(QWidget *parent = nullptr);
    playscence(int levelindex);
    //具体选择关卡号
int levelindex;
void paintEvent(QPaintEvent *);

//当前关卡的数据
int gameArray[4][4];
//金币数组
mycoin*coinbtn[4][4];
bool iswin=true;
signals:
void choosescenceback1();
public slots:
};

#endif // PLAYSCENCE_H
