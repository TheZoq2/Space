#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator(double seed)
{
    this->generator.setSeed(seed);

}

double TerrainGenerator::getTerrainHeight(double x, double z)
{
    return getPointHeight(x, z, 16);
}


/////////////////////////////////////////////////////////////////
//                  Private methods
/////////////////////////////////////////////////////////////////

double TerrainGenerator::getPointHeight(double x, double z, double detailLevel)
{
    //TODO Possible optimisation: Store previously generated height values to avoid doing
    //the rand2d calculation often

    //Find the closest points on the specified detail level
    double x1 = floor(x) * detailLevel;
    double x2 = ceil(x) * detailLevel;

    double z1 = floor(z) * detailLevel;
    double z2 = ceil(z) * detailLevel;

    //Generating the height of the four points
    double heightx1z1 = generator.rand2d(x1, z1);
    double heightx1z2 = generator.rand2d(x1, z2);
    double heightx2z1 = generator.rand2d(x2, z1);
    double heightx2z2 = generator.rand2d(x2, z2);

    //Calculating the height of the terrain on the x-x and z-z axis
    double xDist = (x * detailLevel - x1) / detailLevel;
    double zDist = (z * detailLevel - z1) / detailLevel;

    double xxHeight1 = generator.interpolateCos(heightx1z1, heightx1z2, xDist);
    double xxHeight2 = generator.interpolateCos(heightx2z1, heightx1z2, xDist);
    double zzHeight1 = generator.interpolateCos(heightx1z1, heightx2z1, zDist);
    double zzHeight2 = generator.interpolateCos(heightx1z2, heightx2z2, zDist);

    //Calculating the influence from each point
    double xHeight = xxHeight1 * xDist + xxHeight2 * (1-xDist);
    double zHeight = zzHeight1 * zDist + zzHeight2 * (1-zDist);

    return xHeight * 0.5 + zHeight * 0.5;
}

