#include "Object.h"

Object::Object(Mesh* geometry)
{
    this->mGeometry = geometry;

    this->mPos.set(0, 0, 0);
    this->mAngle.set(0, 0, 0);
    this->mScale.set(1, 1, 1);

    mGeode = new osg::Geode();
    mRoot = new osg::PositionAttitudeTransform();

    osg::Geometry* osgGeometry = geometry->getOsgGeometry();
    mGeode->addDrawable(osgGeometry);
    mRoot->addChild(mGeode);
    //mRoot->addDrawable(osgGeometry);
}

void Object::setPos(osg::Vec3 pos)
{
    this->mPos = pos;
}
void Object::setScale(osg::Vec3 scale)
{
    this->mScale = scale;
}
void Object::setAngle(osg::Vec3 angle)
{
    this->mAngle = angle;
}

osg::PositionAttitudeTransform* Object::getRoot()
{
    return this->mRoot;
}
