#ifndef CMAINWIDGET_H
#define CMAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"


class CMainWidget : public QWidget
{
    Q_OBJECT

public:
    CMainWidget(QWidget *parent = nullptr);
    ~CMainWidget();
    void  mySlot();
    void changeToChild();
    void doChild();
private:
    QPushButton b;
    QPushButton *b1;
    QPushButton b2;
    SubWidget sw;
};

#endif // CMAINWIDGET_H
