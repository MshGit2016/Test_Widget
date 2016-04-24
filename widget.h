#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSizeGrip>
#include <QVBoxLayout>
#include <QTextEdit>

namespace Ui {
class Widget;
}

class SubWindow : public QWidget
{
    Q_OBJECT
public:

    SubWindow(QWidget *parent = 0):QWidget(parent,Qt::SubWindow)
    {
        QSizeGrip *sizegrip=new QSizeGrip(this);
        sizegrip->setFixedSize(sizegrip->sizeHint());

        this->setLayout(new QVBoxLayout);
        this->layout()->setMargin(0);
        layout()->addWidget(new QTextEdit);
        sizegrip->setWindowFlags(Qt::WindowStaysOnTopHint);
        sizegrip->raise();
    }

    QSize sizeHint() const
    {
        return QSize(200,100);
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
