﻿#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void changeToParent();
    /**
     *
     *  声明自定义的信号
     * 信号就是函数的声明，只需声明，不需要定义
     * 使用 emit mySigNal()
     */
signals:
    void mySigNal();
public slots:

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
