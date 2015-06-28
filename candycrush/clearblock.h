#ifndef CLEARBLOCK_H
#define CLEARBLOCK_H


class clearblock
{
public:
    clearblock();
    virtual ~clearblock();
    virtual void countnear(int,int)=0;

    bool bound(int i, int j);
    int getnewjL();
    int getnewjR();
    int getnewiL();
    int getnewiR();
    int getrec();
    int record;
    int newiL,newiR;//for newiL newiR
    int newjL,newjR;//for newjL newjR
    static const int dimension = 8;


private:

};

#endif // CLEARBLOCK_H
