#include "Camera.h"

Camera::Camera(osg::Camera* camera)
{
    this->mCamera = camera;
}

void Camera::setPosition(osg::Vec3 position)
{
    this->mPosition = position;

    mPositionMatrix.makeTranslate(position);
}
void Camera::setRotation(osg::Vec3 rotation)
{
    this->mRotation = rotation;

    mRotationMatrix.makeRotate(
            rotation.x(), osg::Vec3(1, 0, 0),
            rotation.y(), osg::Vec3(0, 1, 0),
            rotation.z(), osg::Vec3(0, 0, 1)
        );

    recalculateMatrix();
}

void Camera::recalculateMatrix()
{
    mMatrix = mPositionMatrix * mRotationMatrix;
    mCamera->setViewMatrix(mMatrix);
}

