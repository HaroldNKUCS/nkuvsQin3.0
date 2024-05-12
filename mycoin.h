#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include<QPainter>

class mycoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit mycoin(QWidget *parent = nullptr);
  //参数代表是金币还是银币
    mycoin(QString img);
    //x坐标
    int posx;
    //y坐标
    int posy;
    //自身状态
    bool flag;
    //金币翻转
    void changeflag();
    QTimer*timer1;
    QTimer*timer2;
    int min=1;
    int max=9;
    //胜利之后点击无效的函数实现
    void mousePressEvent(QMouseEvent*e);

   bool iswin=false;

signals:

public slots:
};

#endif // MYCOIN_H
