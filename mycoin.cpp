#include "mycoin.h"
#include<QTimer>
#include<QDebug>
#include<QLabel>
#include<QPainter>
#include<QPixmap>
#include<QImage>
//mycoin::mycoin(QWidget *parent) : QPushButton(parent)
//{

//}
mycoin::mycoin(QString imgPath){
    QPixmap pix;
    pix.load(imgPath);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}  ");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
    //定时器创建
    timer1=new QTimer(this);
    timer2=new QTimer(this);
    //在定时器结束时进行图片翻转
    //金色->银色
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/new/Coin000%1").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}  ");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min>this->max){
            this->min=1;
            timer1->stop();
        }
    });
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/new/Coin000%1").arg(this->max--);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}  ");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->max<this->min){
            this->max=9;
            timer2->stop();
        }
    });

}
//硬币翻转
void mycoin::changeflag(){
    //金币状态更换
    if(this->flag){
        //启动定时器
        timer1->start(30);
        this->flag=false;
    }
    else{
        timer2->start(30);
        this->flag=true;
    }
}
void mycoin::mousePressEvent(QMouseEvent*e){
    if(this->iswin){
        return;
    }
    else{
        QPushButton::mousePressEvent(e);
    }
}
//鼠标跟随




