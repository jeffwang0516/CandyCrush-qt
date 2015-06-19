#ifndef CANDY_H
#define CANDY_H

#include <QWidget>

class Candy : public QWidget
{
    Q_OBJECT
public:
    explicit Candy(QWidget *parent = 0);
    ~Candy();
    virtual int id()=0;

signals:

public slots:
};

#endif // CANDY_H
