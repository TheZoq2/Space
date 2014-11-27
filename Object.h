#ifndef H_OBJECT
#define H_OBJECT

#include <osg/Geode>
#include <osg/Vec3>
#include <osg/Geometry>
#include <osg/PositionAttitudeTransform>

#include "Mesh.h"

class Object
{
public:
    Object(Mesh* geometry);

    void setPosition(osg::Vec3 pos);
    void setScale(osg::Vec3 scale);
    void setRotation(float rotationX, float rotationY, float rotationZ);
    void setRotation(osg::Vec3 rotation);

    osg::PositionAttitudeTransform* getRoot();
private:
    osg::PositionAttitudeTransform* mRoot;
    osg::Geode* mGeode;
    Mesh* mGeometry;

    osg::Vec3 mPos;
    osg::Vec3 mScale;
    osg::Vec3 mRotation;
    osg::Quat mQuat;
};

#endif
