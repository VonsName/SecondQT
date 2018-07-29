#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("child");
    b.setParent(this);
    b.setText("change to parent");
    //向父窗口发送信号
    connect(&b,&QPushButton::clicked,this,&SubWidget::changeToParent);

    resize(400,300);
}

void SubWidget::changeToParent()
{
    emit mySigNal();
    //发送带参数的信号
    emit mySigNal(100,QString("data slot"));
}
