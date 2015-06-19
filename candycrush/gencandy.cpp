#include<iostream>
#include<cstdlib>
#include "gencandy.h"
#include<ctime>
#define num_candy 4
#define candy1 0
#define candy2 1
#define candy3 2
#define candy4 3

Candy * genCandy()
{
    int type;
    Candy *pt;
    srand(time(NULL));
    type=rand()%num_candy;
    switch(type){
    case candy1:
        pt = new Candy_1;
        break;
    case candy2:
        pt = new Candy_2;
        break;
    case candy3:
        pt = new Candy_3;
        break;
    case candy4:
        pt = new Candy_4;
        break;
    }
    return pt;
}
