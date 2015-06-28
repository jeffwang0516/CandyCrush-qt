#include "clearblock.h"

clearblock::clearblock()
{
   // record=1;
    newiL=0;
    newiR=0;
    newjL=0;
    newjR=0;
}

clearblock::~clearblock()
{

}


bool clearblock::bound(int i,int j)
{
    if(i>=0&&j>=0&&i<8&&j<8)
        return true;
    else
        return false;
}
int clearblock::getnewjL()
{
    return newjL;

}
int clearblock::getnewjR()
{
    return newjR;

}
int clearblock::getnewiL()
{
    return newiL;
}
int clearblock::getnewiR()
{
    return newiR;
}

int clearblock::getrec()
{
    return record;
}
