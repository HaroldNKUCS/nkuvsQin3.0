#include "playsence.h"
#include<QDebug>
#include<QMenu>
#include<QMenuBar>
#include<QPainter>
#include<mypushbutton.h>
#include<QTimer>
#include<QLabel>
#include<mycoin.h>
#include<dataconfig.h>
#include<QPropertyAnimation>
//playscence::playscence(QWidget *parent) : QMainWindow(parent)
//{

//}
playscence::playscence(int levelindex){
    //记录具体选择哪一关
    this->levelindex=levelindex;
    qDebug()<<"您选择的是"<<levelindex<<"关";
    //游戏场景搭建
    //配置主场景
    this->setWindowTitle("游戏");
    this->setFixedSize(500,788);
    this->setWindowIcon(QIcon(":/new/Coin0001.png"));
    //点击退出游戏
    //创建 开始 结束按钮
    QMenuBar*bar=this->menuBar();
    this->setMenuBar(bar);
    QMenu * startMenu=bar->addMenu("开始");
     QAction*quitaction=startMenu->addAction("退出");
    connect(quitaction,&QAction::triggered,[=](){
        this->close();
    });
    //返回按钮
    MyPushButton*backbtn=new MyPushButton(":/new/BackButton.png",":/new/BackButtonSelected.png");
backbtn->setParent(this);
backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
connect(backbtn,&MyPushButton::clicked,[=](){
    //延时相应

    QTimer::singleShot(500,this,[=](){

emit this->choosescenceback1();
    });
});
dataConfig config;
//胜利动画
QLabel* winLabel = new QLabel;
QPixmap tmppix;
tmppix.load(":/new/LevelCompletedDialogBg.png");
winLabel->setGeometry(0,0,tmppix.width(),tmppix.height());
winLabel->setPixmap(tmppix);
winLabel->setParent(this);
winLabel->move((this->width()-tmppix.width())*0.5,-tmppix.height());





//导入关卡数据
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
    this->gameArray[i][j]=config.mData[this->levelindex][i][j];
}
    }
//设置金币背景
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        QPixmap pix;
        pix.load(":/new/BoardNode.png");
        QLabel *lb=new QLabel;
        lb->setGeometry(0,0,pix.width(),pix.height());
        lb->setPixmap(pix);
        lb->setParent(this);
        lb->move(80+i*100,200+j*100);
        //导入金币文件
        QString str;
        if(this->gameArray[i][j]==1){
            str=":/new/Coin0001.png";
        }
        else{
            str=":/new/Coin0009.png";
        }
        mycoin*coin=new mycoin(str);
        coin->setParent(this);
        coin->move(75+i*100,190+j*100);
        //给金币的属性赋值
coin->posx=i;
coin->posy=j;
coin->flag=gameArray[i][j];
coinbtn[i][j]=coin;

//点击按钮的信号
connect(coin,&mycoin::clicked,[=](){
    coin->changeflag();
    this->gameArray[i][j]=this->gameArray[i][j]==1?0:1;
    //延时翻转周围硬币
    QTimer::singleShot(300,this,[=](){
        if(coin->posx+1<=3){
            coinbtn[coin->posx+1][coin->posy]->changeflag();
            this->gameArray[coin->posx+1][coin->posy]=this->gameArray[coin->posx+1][coin->posy]==1?0:1;
        }
        if(coin->posx-1>=0){
            coinbtn[coin->posx-1][coin->posy]->changeflag();
            this->gameArray[coin->posx-1][coin->posy]=this->gameArray[coin->posx-1][coin->posy]==1?0:1;
        }
        if(coin->posy-1>=0){
            coinbtn[coin->posx][coin->posy-1]->changeflag();
            this->gameArray[coin->posx][coin->posy-1]=this->gameArray[coin->posx][coin->posy-1]==1?0:1;
        }
        if(coin->posy+1<=3){
            coinbtn[coin->posx][coin->posy+1]->changeflag();
            this->gameArray[coin->posx][coin->posy+1]=this->gameArray[coin->posx][coin->posy+1]==1?0:1;
        }
        //胜利检测
        iswin=true;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) {
                if(coinbtn[i][j]->flag==false){
                    iswin=false;
               break;
         }
        }
        }
        if(iswin){
            for(int i=0;i<4;i++){
                        for(int j=0;j<4;j++) {
                          coinbtn[i][j]->iswin=true;
                        }
                        }
                //胜利动画
                QPropertyAnimation*animation=new QPropertyAnimation(winLabel,"geometry");
                animation->setDuration(1000);
                animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                animation->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                animation->setEasingCurve(QEasingCurve::OutBounce);
                animation->start(QAbstractAnimation::DeleteWhenStopped);
        }


    });
});

    }
}


}



//绘制背景
void playscence::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/playback.png");
    painter.drawPixmap(0,0,500,788,pix);

}
