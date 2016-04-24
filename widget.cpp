
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    int xpos=10;
    int ypos=10;
    for(int i=0;i<6;i++)
    {
        if(i<=2)
        {
            slider[i]=new QSlider(Qt::Vertical,this);
            slider[i]->setGeometry(xpos,20,30,80);

            slider[i]->setRange(0,100);
            slider[i]->setValue(50);

            lbl[i]=new QLabel(QString("%1").arg(slider[i]->value()),this);
            lbl[i]->setGeometry(xpos+10,100,30,40);
            xpos+=30;
        }
        else if(i>=3)
        {
            slider[i]=new QSlider(Qt::Horizontal,this);
            slider[i]->setGeometry(130,ypos,80,30);

            slider[i]->setRange(0,100);
            slider[i]->setValue(50);
            ypos+=30;
        }
    }
    connect(slider[0],SIGNAL(valueChanged(int)),this,SLOT(valueChanged1(int)));
    connect(slider[1],SIGNAL(valueChanged(int)),this,SLOT(valueChanged2(int)));
    connect(slider[2],SIGNAL(valueChanged(int)),this,SLOT(valueChanged3(int)));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::valueChanged1(int value)
{
    lbl[0]->setText(QString("%1").arg(value));
}
void Widget::valueChanged2(int value)
{
    lbl[1]->setText(QString("%1").arg(value));
}
void Widget::valueChanged3(int value)
{
    lbl[2]->setText(QString("%1").arg(value));
}

