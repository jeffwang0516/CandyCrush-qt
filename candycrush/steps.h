#ifndef STEPS_H
#define STEPS_H


class Steps
{
public:
    Steps(int);
    ~Steps();
    int operator-(int x);
    int get();
private:
    int steps;
};

#endif // STEPS_H
