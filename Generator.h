#ifndef H_GENERATOR
#define H_GENERATOR

#include <math.h>



//Helper class for generating consistent values

class Generator
{
public:
    Generator();

    void setSeed(double seed);

    double rand1d(double x);
    double rand2d(double x, double y);

    double interpolateCos(double x1, double x2, double dist);
private:
    double seed;

    float randConstX;
    float randConstY;


};

#endif
