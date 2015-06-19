#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();

    for(int i=0;i<dimension;++i){
        for(int j=0;j<dimension;++j){
            candy_ptr=genCandy();
            board[i][j]=candy_ptr->id();
            qDebug()<<board[i][j]<<" ";
            delete candy_ptr;
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    board.resize(dimension);
    for (int i = 0; i < dimension; ++i)
        board[i].resize(dimension);
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            board[i][j] = 0;
}

