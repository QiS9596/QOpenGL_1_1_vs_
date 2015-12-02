#ifndef CAMERA_H
#define CAMERA_H

#include "glstdafx.h"

#include "transform.h"

YGL_BEGIN_NAMESPACE

class Camera
{
public:
    Camera();
    ~Camera();

public:
    Transform transform;

public:
    void setPerspective( float fieldOfView, float aspectRatio, float nearPlane, float farPlane );
    void setOrthogonal( float left, float right, float botton, float top, float nearPlane, float farPlane );
    const QMatrix4x4 &getProjectViewMatrix() const;
    const QMatrix4x4 &getProjectMatrix() const;
    const QMatrix4x4 &getViewMatrix() const;

private:
    QMatrix4x4 m_projectMatrix;
};

YGL_END_NAMESPACE

#endif // CAMERA_H
