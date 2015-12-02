#include "camera.h"

YGL_USE_NAMESPACE

Camera::Camera()
{
    m_projectMatrix.setToIdentity();
}

Camera::~Camera()
{

}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
{
    m_projectMatrix.setToIdentity();
    m_projectMatrix.perspective( fieldOfView, aspectRatio, nearPlane, farPlane );
}

void Camera::setOrthogonal(float left, float right, float botton, float top, float nearPlane, float farPlane)
{
    m_projectMatrix.setToIdentity();
    m_projectMatrix.ortho( left, right, botton, top, nearPlane, farPlane );
}

const QMatrix4x4 &Camera::getProjectViewMatrix() const
{
    return m_projectMatrix * transform.getWorldToObjectMatrix();
}

const QMatrix4x4 &Camera::getProjectMatrix() const
{
    return m_projectMatrix;
}

const QMatrix4x4 &Camera::getViewMatrix() const
{
    return transform.getWorldToObjectMatrix();
}
