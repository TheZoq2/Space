#include "Object.h"

Object::Object(Mesh* geometry)
{
    this->mGeometry = geometry;

    this->mPos.set(0, 0, 0);
    this->mScale.set(1, 1, 1);

    mGeode = new osg::Geode();
    mRoot = new osg::PositionAttitudeTransform();

    osg::Geometry* osgGeometry = geometry->getOsgGeometry();
    mGeode->addDrawable(osgGeometry);
    mRoot->addChild(mGeode);
    //mRoot->addDrawable(osgGeometry);
}

void Object::setPosition(osg::Vec3 pos)
{
    this->mPos = pos;

    mRoot->setPosition(pos);
}
void Object::setScale(osg::Vec3 scale)
{
    this->mScale = scale;

    mRoot->setScale(scale);
}
void Object::setRotation(float rotationX, float rotationY, float rotationZ)
{
    setRotation(osg::Vec3(rotationX, rotationY, rotationZ));
}
void Object::setRotation(osg::Vec3 rotation)
{
    this->mRotation = rotation;

    mQuat.makeRotate(
            rotation.x(), osg::Vec3(1, 0, 0),
            rotation.y(), osg::Vec3(0, 1, 0),
            rotation.z(), osg::Vec3(0, 0, 1)
        );

    mRoot->setAttitude(mQuat);
}

osg::PositionAttitudeTransform* Object::getRoot()
{
    return this->mRoot;
}
