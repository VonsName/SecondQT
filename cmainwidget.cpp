#include "cmainwidget.h"
#include "subwidget.h"
#include <QDebug>


CMainWidget::CMainWidget(QWidget *parent)
    : QWidget(parent)
{
    //设置父窗口
    b.setParent(this);
    b.setText(QString("close"));
    //移动位置
    b.move(200,50);

    //通过构造函数设置父窗口
    b1=new QPushButton(this);
    b1->setText(QString("测试按钮1"));

    //关闭信号
    /**
     * @brief connect
     *  &b :信号发出方
     *  &QPushButton::pressed：处理的信号类型
     *  this：信号接收者
     *  &CMainWidget::close：槽函数（信号处理函数）
     */
    connect(&b,&QPushButton::pressed,this,&CMainWidget::close);
    /**
     * @brief connect
     * 使用自定义的槽函数，标准的信号
     * 因为信号是没有返回值的，所以定义槽函数的时候也不能有返回值
     */
    connect(b1,&QPushButton::released,this,&CMainWidget::mySlot);

    /**
     * @brief connect
     * 使b按钮消失的槽函数
     */
    connect(b1,&QPushButton::released,&b,&QPushButton::hide);

    this->setWindowTitle("parent");
    b2.setParent(this);
    b2.setText("change to child");
    b2.move(50,50);

    //显示子窗口
    //sw.move(50,50);
    //sw.show();
    connect(&b2,&QPushButton::pressed,this,&CMainWidget::changeToChild);

    //定义不带参数函数指针 因为这里定义的信号的以重载的方式，否者会出现调用的二义性
    //void (SubWidget::*signal)()=&SubWidget::mySigNal;
    //处理子窗口的信号,不带参数
    //connect(&sw,signal,this,&CMainWidget::doChild);


    //定义带参数的函数指针
    //void(SubWidget::*sinnalData)(int,QString)=&SubWidget::mySigNal;
    //处理带有参数的信号
    //connect(&sw,sinnalData,this,&CMainWidget::doSlot);

    //QT4信号连接
    connect(&sw,SIGNAL(mySigNal()),this,SLOT(doChild()));

    connect(&sw,SIGNAL(mySigNal(int,QString)),this,SLOT(doSlot(int,QString)));


    //Lambda表达式
    QPushButton *b3=new QPushButton(this);
    b3->setText("Lambda表达式");
    b3->move(200,190);
    int a=100;int b=200;
    connect(b3,&QPushButton::pressed,
            /*
             * = 表示把外部的所有包括类的局部变量以值的方式都传递进来
             * this 以指针的方式传递进来
             * &    以引用的方式传递进来
             */
            [=]() mutable //mutable 使接收的参数变为可以修改的

                           //Lambda表示默认接收的参数是只读的，
    {
        qDebug()<<"test111"<<endl;
        qDebug()<<a<<b<<endl;
        a=b+20;
        qDebug()<<a;
    });

    qDebug()<<a<<endl;
    resize(400,300);
}

//自定义槽函数
void CMainWidget::mySlot(){
    b1->setText(QString("diy slot function"));
}

//自定义槽函数
void CMainWidget::changeToChild()
{
    sw.show();
    this->hide();
}

//处理子窗口的信号槽函数
void CMainWidget::doChild()
{
    sw.hide();
    this->show();
}

void CMainWidget::doSlot(int a, QString s)
{
        //相当于C++ 的cout
        qDebug()<<a<<s.toUtf8().data()<<endl;
}

CMainWidget::~CMainWidget()
{

}
