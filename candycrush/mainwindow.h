#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QGridLayout>
#include<QVector>
#include<QString>
#include<QSize>
#include<QSignalMapper>
#include "gencandy.h"
#include "point.h"
#include "steps.h"
#include "stars.h"
#include "windowend.h"
#include "clearblock.h"
#include "horizontalchk.h"
#include "verticalchk.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
    void refresh();
    bool elimTest(int i, int j);
    bool bound(int i, int j);
    void fillBlank();
    void blankdrop();
signals:
    void quit(int star, int score);
    void clicked(const int &text);
public slots:

private slots:
     void handleEndGame();
     void exchange(int);


private:
    static const int dimension = 8;
    Ui::MainWindow *ui;
    int board[dimension][dimension];
    QPushButton *button[dimension][dimension];
    QPixmap pix[20];
   // QVector<QVector<int> > board;
    Candy *candy_ptr;
    int recPress[3];
    QSignalMapper *signalMapper;
    int cnt;
    Point *points;
    Steps *steps;
    Stars *starcnt;
    QLabel *score;
    QLabel *stepsR;
    QLabel *star;
    windowEnd *end;

};

#endif // MAINWINDOW_H
