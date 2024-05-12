#include "chooselevelsense.h"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QPainter>
#include<mypushbutton.h>
#include<QTimer>
#include<QLabel>
chooselevelsence::chooselevelsence(QWidget *parent) : QMainWindow(parent)
{
    QMenuBar*bar=menuBar();
    QMenu * startMenu=bar->addMenu("开始");
    QAction *quitaction=startMenu->addAction("退出");
    connect(quitaction,QAction::triggered,[=](){
        this->close();
    });
//窗口大小
    this->setWindowTitle(" 选择关卡");
    this->setFixedSize(500,788);
    this->setWindowIcon(QIcon(":/new/Coin0001.png"));
    //返回按钮
    MyPushButton*backbtn=new MyPushButton(":/new/BackButton.png",":/new/BackButtonSelected.png");
backbtn->setParent(this);
backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
connect(backbtn,&MyPushButton::clicked,[=](){
    //延时相应

    QTimer::singleShot(450,this,[=](){

emit this->choosescenceback();
    });
});
playscence1=NULL;
for(int i=0;i<20;i++){
    MyPushButton*menubtn=new MyPushButton(":/new/LevelIcon.png");
    menubtn->setParent(this);
    menubtn->move(60+(i%4)*110,150+(i/4)*110);
//创建具体关卡号
    connect(menubtn,&MyPushButton::clicked,[=](){
playscence1=new playscence(i+1);
this->hide();
playscence1->setGeometry(this->geometry());
        this->playscence1->show();
//接受来自下一个场景的返回
connect(this->playscence1,&playscence::choosescenceback1,[=](){
    this->setGeometry(this->playscence1->geometry());
    delete this->playscence1;
    this->playscence1=NULL;
    this->show();
});

    });
    QLabel*label=new QLabel;
    label->setParent(this);
    label->setFixedSize(menubtn->width(),menubtn->height());
   label->setText(QString::number(i+1));
   label->move(60+(i%4)*110,150+(i/4)*110);
   label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
label->setAttribute(Qt::WA_TransparentForMouseEvents);
}

}
void chooselevelsence::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/OtherSceneBg.png");
    painter.drawPixmap(0,0,500,788,pix);

}
