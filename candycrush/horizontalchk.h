#ifndef HORIZONTALCHK_H
#define HORIZONTALCHK_H
#include "clearblock.h"

class HorizontalChk:public clearblock
{

public:
    HorizontalChk();
    ~HorizontalChk();
     void countnear(int,int);
    int getrec();
    void setArray(int a, int b,int num);
    int getSpecial(int a, int b);
private:
    int board[dimension][dimension];
    int special[dimension][dimension];
    int record2;
};

#endif // HORIZONTALCHK_H
