#ifndef VERTICALCHK_H
#define VERTICALCHK_H
#include "clearblock.h"

class VerticalChk:public clearblock
{
public:
    VerticalChk();
    ~VerticalChk();
     virtual void countnear( int i, int j);
    int getrec();
    void setArray(int a, int b, int num);
private:
    int board[dimension][dimension];
    int record2;
};

#endif // VERTICALCHK_H
