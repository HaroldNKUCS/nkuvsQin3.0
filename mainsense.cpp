#include "mainsense.h"
#include "ui_mainsense.h"
#include<QPainter>
#include<mypushbutton.h>
#include<QDebug>
#include<QTimer>
#include<QPixmap>
MainSense::MainSense(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSense)
{
    ui->setupUi(this);
    //配置主场景
    this->setWindowTitle("南开大学大战秦始皇");
    this->setFixedSize(500,788);
    this->setWindowIcon(QIcon(":/new/title.png"));
    //点击退出游戏
//    connect(ui->actionquit,&QAction::triggered,[=](){
//        this->close();
//    });
    choosescence=new chooselevelsence;
    //点击开始按钮
    MyPushButton*startbtn=new MyPushButton(":/new/MenuSceneStartButton.png");
    startbtn->setStyleSheet("QPushButton{border:0px;}  ");
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.7);
    startbtn->setParent(this);
    connect(choosescence,&chooselevelsence::choosescenceback,[=](){
        this->setGeometry(choosescence->geometry());
        choosescence->hide();
        this->show();
    });
    connect(startbtn,&MyPushButton::clicked,[=](){
        //延时进入选择

        startbtn->zoom1();
        startbtn->zoom2();
        //自身隐藏 关卡场景显示
        QTimer::singleShot(500,this,[=](){
            this->hide();
            //设置位置
            choosescence->setGeometry(this->geometry());
            choosescence->show();
        });


    });
}
 void MainSense::paintEvent(QPaintEvent *){
     QPainter painter(this);
     QPixmap pix;
     pix.load(":/new/MenuSceneBg.png");
     painter.drawPixmap(0,0,500,788,pix);

 }

MainSense::~MainSense()
{
    delete ui;
}
