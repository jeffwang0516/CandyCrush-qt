#ifndef WINDOWEND_H
#define WINDOWEND_H

#include <QDialog>
#include <QPushButton>
namespace Ui {
class windowEnd;
}

class windowEnd : public QDialog
{
    Q_OBJECT

public:
    explicit windowEnd(int stars,int points,QWidget *parent = 0);
    ~windowEnd();
signals:
    void endSig();
private slots:


    void onclick(){emit endSig();}

private:
    Ui::windowEnd *ui;
    int star;
    int point;
};

#endif // WINDOWEND_H
