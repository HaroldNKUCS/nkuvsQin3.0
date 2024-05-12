#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}
MyPushButton::MyPushButton(QString normalImg,QString pressImg){
    this->normalImgpath=normalImg;
    this->pressImgpath=pressImg;
    //加载开始按钮
    QPixmap pix;
    bool ret=pix.load(normalImgpath);
    if(!ret){
        QString str=QString("图片加载失败 %1").arg(normalImg);
        qDebug()<<str;
                  return;

    }
    else{
        //设置图片大小
        this->setFixedSize(pix.width(),pix.height());
        //设置图片样式
        this->setStyleSheet("QPushButton{border:0px;}  ");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
}
void MyPushButton:: zoom1(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue((QRect(this->x(),this->y(),this->width(),this->height())));
    //结束位置
    animation->setEndValue((QRect(this->x(),this->y()+10,this->width(),this->height())));

    //设置弹起效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}
void MyPushButton:: zoom2(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    //起始位置
    animation->setStartValue((QRect(this->x(),this->y()+10,this->width(),this->height())));
    //结束位置
    animation->setEndValue((QRect(this->x(),this->y(),this->width(),this->height())));

    //设置弹起效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}
void MyPushButton::mousePressEvent(QMouseEvent *e){
if(this->pressImgpath!=""){
    QPixmap pix;
    bool ret=pix.load(this->pressImgpath);
    if(!ret){
        QString str=QString("图片加载失败 %1").arg(pressImgpath);
        qDebug()<<str;
                  return;

    }
    else{
        //设置图片大小
        this->setFixedSize(pix.width(),pix.height());
        //设置图片样式
        this->setStyleSheet("QPushButton{border:0px;}  ");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
}
    //点击相应时间派给父类
    QPushButton::mousePressEvent(e);

}

void MyPushButton::mouseReleaseEvent(QMouseEvent*e){
    if(this->pressImgpath!=""){
        QPixmap pix;
        bool ret=pix.load(this->normalImgpath);
        if(!ret){
            QString str=QString("图片加载失败 %1").arg(normalImgpath);
            qDebug()<<str;
                      return;

        }
        else{
            //设置图片大小
            this->setFixedSize(pix.width(),pix.height());
            //设置图片样式
            this->setStyleSheet("QPushButton{border:0px;}  ");
            //设置图标
            this->setIcon(pix);
            //设置图标大小
            this->setIconSize(QSize(pix.width(),pix.height()));

        }
    }
        //点击相应时间派给父类
        QPushButton::mouseReleaseEvent(e);

}

