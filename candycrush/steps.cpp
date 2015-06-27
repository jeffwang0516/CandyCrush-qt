#include "steps.h"

Steps::Steps(int a)
{
    steps=a;

}

Steps::~Steps()
{

}

int Steps::operator-(int x)
{
    steps-=x;

}

int Steps::get()
{
    return steps;
}

