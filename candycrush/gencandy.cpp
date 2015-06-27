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
    type=rand()%200;
    if((type>=0&&type<=25)||(type>=126&&type<=150))
        pt = new Candy_1;
    if((type>=26&&type<=50)||(type>=101&&type<=125))
        pt = new Candy_2;
    if((type>=51&&type<=75)||(type>=151&&type<=175))
        pt = new Candy_3;
    if((type>=76&&type<=100)||(type>=176&&type<=199))
        pt = new Candy_4;
    /*
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
    }*/
    return pt;
}
