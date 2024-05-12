#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);
    //正常与按下后显示的图片
    MyPushButton(QString normalImg,QString pressImg="");
QString normalImgpath;
QString pressImgpath;
//向下
void zoom1();
//向上
void zoom2();
//实现返回键
void mousePressEvent(QMouseEvent *e);
void mouseReleaseEvent(QMouseEvent*e);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
