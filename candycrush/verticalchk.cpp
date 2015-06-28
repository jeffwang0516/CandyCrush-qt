#include "verticalchk.h"

VerticalChk::VerticalChk()
{
for(int i=0;i<dimension;i++)
for(int j=0;j<dimension;j++){
 //   special[i][j]=0;
    board[i][j]=0;
}
}
VerticalChk::~VerticalChk()
{

}

void VerticalChk::countnear( int i, int j)
{
    record2=1;
    //Vertical
    //int newiL=0, newiR=0,rec2=1;

    int special[dimension][dimension]={0};
    newiL=i-1;
    while((board[newiL][j]==board[i][j]||board[newiL][j]==board[i][j]+4||board[newiL][j]==board[i][j]-4||board[newiL][j]==board[i][j]+8||board[newiL][j]==board[i][j]-8||board[newiL][j]==board[i][j]+12||board[newiL][j]==board[i][j]-12)&&bound(newiL,j)){
        if(board[newiL][j]!=board[i][j])
        (board[newiL][j]<board[i][j])?special[i][j]=board[i][j]:special[newiL][j]=board[newiL][j];
        newiL=newiL-1;
        record2++;
    }
    newiL++;
    newiR=i+1;
    while((board[newiR][j]==board[i][j]||board[newiR][j]==board[i][j]+4||board[newiR][j]==board[i][j]-4||board[newiR][j]==board[i][j]+8||board[newiR][j]==board[i][j]-8||board[newiR][j]==board[i][j]+12||board[newiR][j]==board[i][j]-12)&&bound(newiR,j)){
        if(board[newiR][j]!=board[i][j])
        (board[newiR][j]<board[i][j])?special[i][j]=board[i][j]:special[newiR][j]=board[newiR][j];
        //(board[newiR][j]!=board[i][j])?special[newiR][j]=board[newiR][j]:special[newiR][j]=0;
        newiR=newiR+1;
        record2++;
    }
    newiR--;
}

int VerticalChk::getrec()
{
    return record2;
}
void VerticalChk::setArray(int a, int b, int num)
{
    board[a][b]=num;
}

