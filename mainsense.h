#ifndef MAINSENSE_H
#define MAINSENSE_H

#include <QMainWindow>
#include<chooselevelsense.h>
namespace Ui {
class MainSense;
}

class MainSense : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSense(QWidget *parent = 0);
    ~MainSense();
    //绘制背景
    void paintEvent(QPaintEvent *);
    //维护选择关卡
    chooselevelsence *choosescence;

private:
    Ui::MainSense *ui;
};

#endif // MAINSENSE_H
