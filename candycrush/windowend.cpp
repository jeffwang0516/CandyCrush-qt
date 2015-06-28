#include "windowend.h"
#include "ui_windowend.h"

windowEnd::windowEnd(int stars, int points, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowEnd),star(stars),point(points)
{
    ui->setupUi(this);
    if(point>=4000)
        ui->label->setText("ACHIEVED");
    ui->label_2->setText("SCORE:"+QString::number(point));
    ui->label_3->setText(QString::number(star)+" STARS");
    QPushButton *btn = new QPushButton(this);
    btn->move(400,650);
    btn->setFixedSize(100,80);
    btn->setText("QUIT!!!!");
    connect(btn,SIGNAL(clicked()),this ,SLOT(onclick()));
}

windowEnd::~windowEnd()
{
    delete ui;
}


