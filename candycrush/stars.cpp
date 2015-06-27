#include "stars.h"

Stars::Stars()
{
    num=0;

}

Stars::~Stars()
{

}

int Stars::starsnumcheck(int a)
{
    if(a<=2500&&a>1000)
        num=1;
    if(a>2500&&a<=6000)
        num=2;
    if(a>6000)
        num=3;

}

int Stars::get()
{
    return num;
}

