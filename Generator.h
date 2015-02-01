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
    
    //Cosine interpolation. 
    //Dist is probably the distance from x1 to the point 0 <= dist <= 1
    double interpolateCos(double x1, double x2, double dist);
private:
    double seed;

    float randConstX;
    float randConstY;


};

#endif
