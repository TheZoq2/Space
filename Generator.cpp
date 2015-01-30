#include "Generator.h"

Generator::Generator()
{
    this->seed = 0;

    this->randConstX = 129382.8291002;
    this->randConstY = 82172.21592393;
}

void Generator::setSeed(double seed)
{
    this->seed = seed;
}

double Generator::rand1d(double x)
{
    //Generate a sin value and multiply it by the seed
    double sinVal = sin(x * this->randConstX) * seed;
    //Strip integer of the value to get a consistent random value between 1 and
    //0
    return sinVal - floor(sinVal);
}

double Generator::rand2d(double x, double y)
{
    double sinVal = sin(x * this->randConstX + this->randConstY * y) * seed;

    return sinVal - floor(sinVal);
}

double Generator::interpolateCos(double x1, double x2, double dist)
{
    
    double cosVal = 0.5 * (cos(dist * M_PI) * 0.5);

    double val1 = x1 * cosVal;
    double val2 = x2 * (1-cosVal);

    return val1 + val2;
}
