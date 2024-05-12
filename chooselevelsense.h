#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QMainWindow>
#include<playsence.h>

class chooselevelsence : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooselevelsence(QWidget *parent = nullptr);
void paintEvent(QPaintEvent *event);
playscence*playscence1;

signals:
//抛出自定义信号
void choosescenceback();

public slots:
};

#endif // CHOOSELEVELSENCE_H
