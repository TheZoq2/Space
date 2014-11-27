#ifndef H__CAMERA
#define H_CAMERA

#include <osg/Camera>

class Camera
{
public:
    Camera(osg::Camera* camera);

    void setPosition(osg::Vec3 position);
    void setRotation(osg::Vec3(rotation));
private:
    void recalculateMatrix();

    osg::Camera* mCamera;

    osg::Vec3 mPosition;
    osg::Vec3 mRotation;

    osg::Matrixd mMatrix;
    osg::Matrixd mPositionMatrix;
    osg::Matrixd mRotationMatrix;
};

#endif
