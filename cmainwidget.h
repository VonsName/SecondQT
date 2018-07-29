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
public slots:
    void  mySlot();
    void changeToChild();
    void doChild();
    void doSlot(int,QString);
private:
    QPushButton b;
    QPushButton *b1;
    QPushButton b2;
    SubWidget sw;
};

#endif // CMAINWIDGET_H
