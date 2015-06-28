#include "horizontalchk.h"
#include<QDebug>
HorizontalChk::HorizontalChk()
{
    for(int i=0;i<dimension;i++)
        for(int j=0;j<dimension;j++){
            special[i][j]=0;
            board[i][j]=0;
        }


}

HorizontalChk::~HorizontalChk()
{

}

void HorizontalChk::countnear(int i, int j)
{

    record2=1;
    //Horizontal

    newjL=j-1;
    while((board[i][newjL]==board[i][j]||board[i][newjL]==board[i][j]+4||board[i][newjL]==board[i][j]-4||board[i][newjL]==board[i][j]+8||board[i][newjL]==board[i][j]-8||board[i][newjL]==board[i][j]+12||board[i][newjL]==board[i][j]-12)&&bound(i,newjL)){
        if(board[i][newjL]!=board[i][j])
        (board[i][newjL]>board[i][j])?special[i][newjL]=board[i][newjL]:special[i][j]=board[i][j];
        newjL=newjL-1;
        record2++;
    }
    newjL++;
    newjR=j+1;
    while((board[i][newjR]==board[i][j]||board[i][newjR]==board[i][j]+4||board[i][newjR]==board[i][j]-4||board[i][newjR]==board[i][j]+8||board[i][newjR]==board[i][j]-8||board[i][newjR]==board[i][j]+12||board[i][newjR]==board[i][j]-12)&&bound(j,newjR)){
        if(board[i][newjR]!=board[i][j])
        (board[i][newjR]<board[i][j])?special[i][j]=board[i][j]:special[i][newjR]=board[i][newjR];
      //  (board[i][newjR]>board[i][j])?special[i][newjR]=board[i][newjR]:special[i][newjR]=0;
        newjR=newjR+1;
        record2++;
    }
    newjR--;

}

int HorizontalChk::getrec()
{
    return record2;

}

void HorizontalChk::setArray(int a, int b, int num)
{
    board[a][b]=num;
}
int HorizontalChk::getSpecial(int a, int b)
{
    return special[a][b];
}

