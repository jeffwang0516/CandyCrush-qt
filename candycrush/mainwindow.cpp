#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    points=new Point;
    steps=new Steps(45);
    starcnt= new Stars;
    QWidget *centralWidget = new QWidget;

    int count=1;
   // QPushButton *button[dimension][dimension];
    QGridLayout *controlsLayout = new QGridLayout;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
           if(count<=dimension*dimension)
           {
                    button[i][j] = new QPushButton("");
                    button[i][j]->setFixedSize(90,90);
                    //button[i][j]->setFlat(1);
                    //button[i][j]->setStyleSheet("border-radius: 10px;");
                    //button[i][j]->move(40*j, 40*i);
                    //button[i][j]->show();
                    controlsLayout->addWidget(button[i][j], i, j);
                    count++;
           }
         }
    }
    score = new QLabel;
    score->setText("SCORE:\n"+QString::number(points->get()));
    score->setStyleSheet("font: 20pt\"MV Boli\";color: rgb(255, 8, 32)");
    controlsLayout->addWidget(score,8,0);
    //show steps left
    stepsR = new QLabel;
    stepsR->setText("STEP:\n"+QString::number(steps->get()));
    stepsR->setStyleSheet("font: 20pt\"MV Boli\";color: blue");
    controlsLayout->addWidget(stepsR,8,1);
    //Show num of stars
    star = new QLabel;
    star->setText(QString::number(starcnt->get())+"\nSTARS");
    star->setStyleSheet("font: 20pt\"MV Boli\";color: dark ");
    controlsLayout->addWidget(star,8,2);
    //Quit during game Btn
    QPushButton *quitBtn = new QPushButton("QUIT!");
    quitBtn->setFixedSize(60,60);
    controlsLayout->addWidget(quitBtn, 8, 7);
    connect(quitBtn, SIGNAL(clicked()),this, SLOT(handleEndGame()));

    QLabel *goal = new QLabel;
    goal->setText("GOAL:\n4000\npoints");
    goal->setStyleSheet("font: 20pt\"MV Boli\";color: green");
    controlsLayout->addWidget(goal,8,4);

    controlsLayout->setHorizontalSpacing(0);
    controlsLayout->setVerticalSpacing(0);
    centralWidget->setLayout(controlsLayout);
    setCentralWidget(centralWidget);
    pix[1].load(":/1.png");
    pix[2].load(":/2.png");
    pix[3].load(":/3.png");
    pix[4].load(":/4.png");
    pix[5].load(":/1-1.png");
    pix[6].load(":/2-1.png");
    pix[7].load(":/3-1.png");
    pix[8].load(":/4-1.png");
    pix[9].load(":/1-2.png");
    pix[10].load(":/2-2.png");
    pix[11].load(":/3-2.png");
    pix[12].load(":/4-2.png");
    pix[13].load(":/1bomb.png");
    pix[14].load(":/2bomb.png");
    pix[15].load(":/3bomb.png");
    pix[16].load(":/4bomb.png");
    pix[17].load(":/star.png");

    //Connect signals send from buttons
    QSize size1(80,80);
    signalMapper = new QSignalMapper(this);
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            button[i][j]->setIcon(pix[(board[i][j])]);
            button[i][j]->setIconSize(size1);
            //button[i][j]->setStyleSheet("border-radius: 20px;");

            connect(button[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(button[i][j], 8*i+j);

        }
    }
    connect(signalMapper, SIGNAL(mapped(int)),this, SIGNAL(clicked(int)));
    connect(this, SIGNAL(clicked(int)), this, SLOT(exchange(int)));

}

MainWindow::~MainWindow()
{
    emit quit(starcnt->get(), points->get());
    delete ui;
    delete points;
    delete steps;
    delete starcnt;
}

void MainWindow::init()
{
    int boardinit[dimension][dimension]={{1, 3, 4, 3, 4, 2, 1, 4},
                                         {3, 1, 3, 1, 1, 3, 1, 1},
                                         {4, 1, 2, 1, 3, 2, 2, 3},
                                         {2, 3, 1, 2, 4, 1, 4, 1},
                                         {1, 2, 4, 3, 1, 2, 3, 2},
                                         {2, 1, 3, 1, 4, 1, 4, 1},
                                         {4, 2, 4, 2, 3, 2, 1, 3},
                                         {1, 3, 3, 2, 1, 3, 1, 2}};
    for(int i=0;i<dimension;++i){
        for(int j=0;j<dimension;j++){
            board[i][j]=0;
            board[i][j]=boardinit[i][j];
        }
    }
    cnt=1;

}
//refresh the positions change
void MainWindow::refresh()
{
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            button[i][j]->setIcon(pix[(board[i][j])]);
        }
    }

    score->setText("SCORE:\n"+QString::number(points->get()));
    stepsR->setText("STEP:\n"+QString::number(steps->get()));
    starcnt->starsnumcheck(points->get());
    star->setText(QString::number(starcnt->get())+"\nSTARS");
}
//MAIN Elimination process func
bool MainWindow::elimTest(int i, int j)
{
    bool moved=true;
    clearblock *clearcheck = new HorizontalChk;
    for(int u=0;u<dimension;u++){
        for(int v=0;v<dimension;v++){
            static_cast<HorizontalChk*>(clearcheck)->setArray(u,v,board[u][v]);
        }
    }

    //Horizontal
    int newjL=0, newjR=0, rec=1, special[dimension][dimension]={0};
    newjL=j-1;
    while((board[i][newjL]==board[i][j]||board[i][newjL]==board[i][j]+4||board[i][newjL]==board[i][j]-4||board[i][newjL]==board[i][j]+8||board[i][newjL]==board[i][j]-8||board[i][newjL]==board[i][j]+12||board[i][newjL]==board[i][j]-12)&&bound(i,newjL)){
        if(board[i][newjL]!=board[i][j])
        (board[i][newjL]>board[i][j])?special[i][newjL]=board[i][newjL]:special[i][j]=board[i][j];
        newjL=newjL-1;

    }
    newjL++;

    newjR=j+1;
    while((board[i][newjR]==board[i][j]||board[i][newjR]==board[i][j]+4||board[i][newjR]==board[i][j]-4||board[i][newjR]==board[i][j]+8||board[i][newjR]==board[i][j]-8||board[i][newjR]==board[i][j]+12||board[i][newjR]==board[i][j]-12)&&bound(j,newjR)){
        if(board[i][newjR]!=board[i][j])
          (board[i][newjR]<board[i][j])?special[i][j]=board[i][j]:special[i][newjR]=board[i][newjR];
          newjR=newjR+1;

    }
    newjR--;

    //for(int u=0;u<dimension;u++)
      //  for(int v=0;v<dimension;v++)
            //qDebug()<<"this"<<special[u][v]<<" "<<static_cast<HorizontalChk*>(clearcheck)->getSpecial(u,v)<<" ";
            //special[u][v]=static_cast<HorizontalChk*>(clearcheck)->getSpecial(u,v);
    //newjL=static_cast<HorizontalChk*>(clearcheck)->getnewjL();
   //qDebug()<<"this"<<newjL<<" "<<static_cast<HorizontalChk*>(clearcheck)->getnewjL()<<" ";

    clearcheck->countnear(i,j);
    rec=static_cast<HorizontalChk*>(clearcheck)->getrec();
    delete clearcheck;

    //Vertical
    clearblock *clearcheck2 = new VerticalChk;
    for(int u=0;u<dimension;u++){
        for(int v=0;v<dimension;v++){
            static_cast<VerticalChk*>(clearcheck2)->setArray(u,v,board[u][v]);
        }
    }

    int newiL=0, newiR=0,rec2=1;
    newiL=i-1;
    while((board[newiL][j]==board[i][j]||board[newiL][j]==board[i][j]+4||board[newiL][j]==board[i][j]-4||board[newiL][j]==board[i][j]+8||board[newiL][j]==board[i][j]-8||board[newiL][j]==board[i][j]+12||board[newiL][j]==board[i][j]-12)&&bound(newiL,j)){
        if(board[newiL][j]!=board[i][j])
        (board[newiL][j]<board[i][j])?special[i][j]=board[i][j]:special[newiL][j]=board[newiL][j];
        newiL=newiL-1;

    }
    newiL++;
    newiR=i+1;
    while((board[newiR][j]==board[i][j]||board[newiR][j]==board[i][j]+4||board[newiR][j]==board[i][j]-4||board[newiR][j]==board[i][j]+8||board[newiR][j]==board[i][j]-8||board[newiR][j]==board[i][j]+12||board[newiR][j]==board[i][j]-12)&&bound(newiR,j)){
        if(board[newiR][j]!=board[i][j])
           (board[newiR][j]<board[i][j])?special[i][j]=board[i][j]:special[newiR][j]=board[newiR][j];

        newiR=newiR+1;

    }
    newiR--;


    clearcheck2->countnear(i,j);
    rec2=static_cast<VerticalChk*>(clearcheck2)->getrec();
    delete clearcheck2;



    if(rec+rec2>=6&&((rec==3&&rec2==3)||(rec==4&&rec2==3)||(rec==3&&rec2==4)))//
    {

            //for bomb
            switch(rec+rec2){
            case 6:case 7:
                for(int jj=newjL;jj<=newjR;++jj){
                    if(jj!=j)//
                      board[i][jj]=0;
                  // for(int s=i;s>=0;s--){
                     // if(s==0){board[s][jj]=0; break;}
                     // board[s][jj]=board[s-1][jj];
                  // }
                }
                for(int ii=newiL;ii<=newiR;++ii){
                  if(ii!=i)
                      board[ii][j]=0;
                   //for(int jj=ii;jj>=0;jj--){
                 //       if(jj==0){board[jj][j]=0; break;}
                  //      board[jj][j]=board[jj-1][j];
                  // }
                }
                board[i][j]+=12;
                qDebug()<<board[i][j]<<rec<<" "<<rec2<<"\n"<<i<<" "<<j;
                blankdrop();//qDebug()<<board[i][j]<<rec<<" "<<rec2<<"\n"<<i<<" "<<j;
                break;
            /*case 7:
                for(int ii=newiL;ii<newiR;++ii){
                   board[ii][j]=0;
                   for(int jj=ii;jj>=0;jj--){
                        if(jj==0){board[jj][j]=0; break;}
                        board[jj][j]=board[jj-1][j];
                   }
                }
                for(int jj=newjL;jj<=newjR;++jj){
                    if(jj==j){board[newiR][j]+=12;continue;}
                   board[i][jj]=0;
                   for(int s=i;s>=0;s--){
                      if(s==0){board[s][jj]=0; break;}
                      board[s][jj]=board[s-1][jj];
                   }
                }

                break;*/


             default:
                moved=false;
                break;
             }

    }else
    {
    int spe=0;
    switch(rec){

    case 3:
        int jj;

        for(jj=newjL;jj<=newjR;++jj){
             if(special[i][jj]!=0)spe=1;

        }
        if(spe>0){
        for(jj=newjL;jj<=newjR;++jj){

            if(special[i][jj]!=0){

                switch(special[i][jj]){
                case 5:case 6:case 7:case 8:
                    for(int a=0;a<dimension;a++)
                        board[i][a]=0;
                    blankdrop();
                    /*for(int h=0;h<dimension;h++){
                        for(int g=i;g>=0;g--){
                            if(g==0){board[g][h]=0;continue;}
                            board[g][h]=board[g-1][h];
                        }
                    }*/
                    break;
                case 9:case 10:case 11:case 12:
                    for(int a=0;a<dimension;a++)
                        board[a][jj]=0;
                    for(int h=newjL;h<=newjR;++h){

                    board[i][h]=0;/*
                    for(int s=i;s>=0;s--){
                        if(s==0){board[s][h]=0; break;}
                        board[s][h]=board[s-1][h];
                    }*/
                    }
                    blankdrop();
                    break;
                case 13:case 14:case 15:case 16:
                    for(int a=i-1;a<=i+1;a++)
                        for(int b=jj-1;b<=jj+1;b++)
                            if(bound(a,b))
                               board[a][b]=0;
                    /*for(int b=jj-1;b<=jj+1;b++){
                        for(int a=i-1;a>=0;a--){
                            if(a==0)board[0][b]=0;
                            else
                                board[a][b]=board[a-1][b];
                        }
                    }*/
                    blankdrop();
                     break;


                default:
                    moved=false;
                    break;
                }

            }
        }
        }else{

            for(jj=newjL;jj<=newjR;++jj){

            board[i][jj]=0;
            /*
            for(int s=i;s>=0;s--){
                if(s==0)board[s][jj]=0;
                else
                board[s][jj]=board[s-1][jj];
            }*/blankdrop();
            }

        }
        break;
    case 4:
        qDebug()<<"inn4";
        board[i][j]+=8;

        for(int jj=newjL;jj<=newjR;++jj){
             if(special[i][jj]!=0)spe=1;
        }
        if(spe>0){
        for(int jj=newjL;jj<=newjR;++jj){

            if(special[i][jj]!=0){
                switch(special[i][jj]){
                case 5:case 6:case 7:case 8:
                    for(int a=0;a<dimension;a++){
                        if(a!=j)
                           board[i][a]=0;

                    }
                    /*
                    for(int h=0;h<dimension;h++){
                        if(h!=j)board[i][h]=0;
                        else continue;
                        for(int g=i;g>=0;g--){
                            if(g==0){board[g][h]=0;break;}
                            board[g][h]=board[g-1][h];


                        }
                    }*/
                    blankdrop();
                    break;
                case 9:case 10:case 11:case 12:
                    for(int a=0;a<dimension;a++)
                        if(a!=i)
                           board[a][jj]=0;
                    for(jj=newjL;jj<=newjR;++jj){
                        if(jj!=j)
                            board[i][jj]=0;
                        /*
                    for(int s=i;s>=0;s--){
                        if(s==0){board[s][jj]=0; break;}
                        board[s][jj]=board[s-1][jj];
                    }*/
                    }
                    blankdrop();
                    break;
                default:
                    moved=false;
                    break;
                }

            }
        }
        }else{

        for(int jj=newjL;jj<=newjR;++jj){
            if(jj!=j)board[i][jj]=0;
            /*else continue;
            //jj==j?re=i-1:re=i;
            for(int s=i;s>=0;s--){
                if(s==0){board[s][jj]=0; break;}
                board[s][jj]=board[s-1][jj];
            }*/
        }
        blankdrop();
        }
        break;

    case 5:
        //qDebug()<<"fuck"<<rec<<" "<<rec2;
        for(int ii=newjL;ii<=newjR;++ii)
            board[i][ii]=0;
        board[i][j]=17;
        /*
        for(int jj=newjL;jj<=newjR;++jj){
            if(jj!=j)board[i][jj]=0;
            else continue;
            for(int s=i;s>=0;s--){
                if(s==0){board[s][jj]=0;}else{
                board[s][jj]=board[s-1][jj];}
            }
        }*/
        blankdrop();
       // board[i][j]+=8;
        break;

    default:

        moved= false;
        break;
    }


    switch(rec2){
    spe=0;

    case 3:


        for(int ii=newiL;ii<=newiR;++ii){
             if(special[ii][j]!=0)spe=1;
        }
        if(spe>0)
        {
            for(int ii=newiL;ii<=newiR;++ii){

                if(special[ii][j]!=0){
                    switch(special[ii][j]){
                    case 5:case 6:case 7:case 8:
                        for(int a=0;a<dimension;a++)
                            board[ii][a]=0;
                        /*
                        for(int h=0;h<dimension;h++){
                            for(int g=i;g>=0;g--){
                                if(g==0){board[g][h]=0;continue;}
                                board[g][h]=board[g-1][h];

                            }
                        }*/
                        for(int iii=newiL;iii<=newiR;++iii){
                            board[iii][j]=0;
                            /*for(int jj=iii;jj>=0;jj--){
                                  if(jj==0){board[jj][j]=0; break;}
                                  board[jj][j]=board[jj-1][j];
                            }*/
                        }
                        blankdrop();
                        break;
                    case 9:case 10:case 11:case 12:
                        for(int a=0;a<dimension;a++)
                            board[a][j]=0;
                        break;
                    case 13:case 14:case 15:case 16:
                        for(int a=ii-1;a<=ii+1;a++)
                            for(int b=j-1;b<=j+1;b++)
                                if(bound(a,b))
                                   board[a][b]=0;
                        for(int iii=newiL;iii<=newiR;++iii){
                            board[iii][j]=0;
                        }
                        blankdrop();
                        /*
                        for(int b=j-1;b<=j+1;b++){
                            for(int a=ii-1;a>=0;a--){
                                if(a==0)board[0][b]=0;
                                else
                                    board[a][b]=board[a-1][b];
                            }
                        }*/


                         break;

                    default:
                        moved=false;
                        break;
                    }

                }
            }
        }else
        {
        for(int ii=newiL;ii<=newiR;++ii){
            board[ii][j]=0;
            /*for(int jj=ii;jj>=0;jj--){
                  if(jj==0)board[jj][j]=0;
                  else
                  board[jj][j]=board[jj-1][j];
            }*/
        }
        blankdrop();
        }
        break;
    case 4:

        for(int ii=newiL;ii<=newiR;++ii){
            if(ii!=i)
                board[ii][j]=0;
            /*
            for(int jj=ii;jj>=0;jj--){
                  if(jj==0){board[jj][j]=0; break;}
                  board[jj][j]=board[jj-1][j];
            }*/
        }

        board[i][j]+=4;
        blankdrop();
        break;

   case 5:

        for(int ii=newiL;ii<=newiR;++ii)
            board[ii][j]=0;
        board[i][j]=17;
        blankdrop();
        break;
    case 6:case 7:case 8:
        for(int ii=newiL;ii<=newiR;++ii)
            board[ii][j]=0;
        blankdrop();
        break;

    default:

        moved= false;
        break;
    }

    }
    return moved;

}
//Check if out of bounds
bool MainWindow::bound(int i,int j)
{
    if(i>=0&&j>=0&&i<8&&j<8)
        return true;
    else
        return false;
}

void MainWindow::fillBlank()
{
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            if(board[i][j]==0){
                //candy_ptr=genCandy();

                board[i][j]=rand()%4+1;
            }
        }
    }


}

void MainWindow::exchange(int a)
{
    bool ifMove=false;
    if(cnt<=2){
        recPress[cnt] = a;
        qDebug()<<"HELLO"<<recPress[cnt];
        cnt++;
    }
    if(cnt==3&&(recPress[1]-recPress[2]==8||recPress[1]-recPress[2]==-8||recPress[1]-recPress[2]==1||recPress[1]-recPress[2]==-1)){

        int row1=recPress[1]/dimension, col1=recPress[1]%dimension, row2=recPress[2]/dimension, col2=recPress[2]%dimension;


        bool check;
        int last[dimension][dimension]={0};

        for(int i=0;i<dimension;i++)
          for(int j=0;j<dimension;j++)
              last[i][j]=board[i][j];
        if(board[row1][col1]==17||board[row2][col2]==17){
            int a=board[row1][col1],b=board[row2][col2];
            if (a>b){
                for(int i=0;i<dimension;i++)
                    for(int j=0;j<dimension;j++){
                        if(board[i][j]%4==b%4)
                            board[i][j]=0;
                    }
                board[row1][col1]=0;
            }else if(a<b){
                for(int i=0;i<dimension;i++)
                    for(int j=0;j<dimension;j++){
                        if(board[i][j]%4==a%4)
                            board[i][j]=0;
                    }
                board[row2][col2]=0;
            }
            blankdrop();
            do
            {

            for(int i=0;i<dimension;i++){
                for(int j=0;j<dimension;j++){
                    last[i][j]=board[i][j];
                }
            }
            check=true;
            for(int i=dimension-1;i>=0;i--){
                for(int j=0;j<dimension;j++){

                    elimTest(i,j);
                    fillBlank();
                }
            }

            for(int i=0;i<dimension;i++){
                for(int j=0;j<dimension;j++){
                    if(last[i][j]!=board[i][j]){
                        //qDebug()<<"check CHECK!";
                        check=false;}
                }
            }
            }while(check==false);
            fillBlank();
        }
        for(int i=0;i<dimension;i++)
          for(int j=0;j<dimension;j++)
              last[i][j]=board[i][j];

        int temp=board[row1][col1];
        board[row1][col1]=board[row2][col2];
        board[row2][col2]=temp;
        if(recPress[1]<recPress[2]){
            ifMove=elimTest(row1,col1);
            fillBlank();
           ifMove=elimTest(row2,col2);
            fillBlank();

        }else{
            ifMove=elimTest(row2,col2);
            fillBlank();
            ifMove=elimTest(row1,col1);
            fillBlank();
        }

//fillBlank();
        ifMove=false;
        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                if(last[i][j]!=board[i][j]&&!((i==row1&&j==col1)||(i==row2&&j==col2))){//
                    //qDebug()<<"notMOVE CHECK!";
                    ifMove=true;
                    points->changePoint(15);
                }
            }
        }
       if(ifMove)
           *steps-1;
       if(steps->get()<=0)
           handleEndGame();
       if(!ifMove){
          // qDebug()<<"notMOVE!";
           int temp2=board[row1][col1];
           board[row1][col1]=board[row2][col2];
           board[row2][col2]=temp2;
       }
       //run until no possible eliminations
        do
        {

        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                last[i][j]=board[i][j];
            }
        }
        check=true;
        for(int i=dimension-1;i>=0;i--){
            for(int j=0;j<dimension;j++){

                elimTest(i,j);
                fillBlank();
            }
        }

        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                if(last[i][j]!=board[i][j]){
                    //qDebug()<<"check CHECK!";
                    check=false;}
            }
        }
        }while(check==false);
       // for(int i=0;i<dimension;i++)
            //for(int j=0;j<dimension;j++)
              //  elimTest(i,j);


        refresh();

    }
    if(cnt==3)
        cnt=1;



}
void MainWindow::blankdrop()
{
    int temp;
    for(int j=0;j<dimension;j++){
        for(int i=dimension-2;i>=0;i--){
            if(board[i][j]!=0){
                for(int ii=dimension-1;ii>i;ii--){
                    if(board[ii][j]==0){
                        temp=board[ii][j];
                        board[ii][j]=board[i][j];
                        board[i][j]=temp;
                    }




                }
            }
        }
    }
}

//ENDGAME FUNCTION
void MainWindow::handleEndGame()
{

    end = new windowEnd(starcnt->get(), points->get());

    connect(end,SIGNAL(endSig()),this,SLOT(close()));
    setCentralWidget(end);
    end->show();
    emit quit(starcnt->get(), points->get());
    end->exec();
    //this->close();
}


