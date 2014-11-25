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

    void setPos(osg::Vec3 pos);
    void setAngle(osg::Vec3 angle);
    void setScale(osg::Vec3 scale);

    osg::PositionAttitudeTransform* getRoot();
private:
    osg::PositionAttitudeTransform* mRoot;
    osg::Geode* mGeode;
    Mesh* mGeometry;

    osg::Vec3 mPos;
    osg::Vec3 mAngle;
    osg::Vec3 mScale;
};

#endif
