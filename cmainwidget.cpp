#include "cmainwidget.h"
#include "subwidget.h"


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

    //处理子窗口的信号
    connect(&sw,&SubWidget::mySigNal,this,&CMainWidget::doChild);

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

CMainWidget::~CMainWidget()
{

}
