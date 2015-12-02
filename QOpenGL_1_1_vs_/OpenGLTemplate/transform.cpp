#include "transform.h"

YGL_USE_NAMESPACE

Transform::Transform()
{
    m_objectToWorldMatrix.setToIdentity();
    m_worldToObjectMatrix.setToIdentity();
}

Transform::~Transform()
{

}

void Transform::translate(const QVector3D &offset)
{
    m_objectToWorldMatrix.translate(  offset );
    m_worldToObjectMatrix.translate( -offset );
}

void Transform::translate(float x, float y, float z)
{
    m_objectToWorldMatrix.translate( x, y, z);
    m_worldToObjectMatrix.translate(-x,-y,-z);
}

void Transform::scale(float x, float y, float z)
{
    m_objectToWorldMatrix.scale( x, y, z);
    m_worldToObjectMatrix.scale(-x,-y,-z);
}

void Transform::rotate(float angle, const QVector3D &axis)
{
    m_objectToWorldMatrix.rotate( angle, axis);
    m_worldToObjectMatrix.rotate(-angle, axis);
}

void Transform::setPosition(const QVector3D &pos)
{
    m_objectToWorldMatrix.setColumn(3, QVector4D( pos, 1));
    m_worldToObjectMatrix.setColumn(3, QVector4D(-pos, 1));
    m_objectToWorldMatrix.optimize();
    m_worldToObjectMatrix.optimize();
}

void Transform::lookAt(const QVector3D &eye, const QVector3D &target, const QVector3D &up)
{
    m_worldToObjectMatrix.setToIdentity();
    m_worldToObjectMatrix.lookAt(eye, target, up);
    m_objectToWorldMatrix = m_worldToObjectMatrix.inverted();
}

const QMatrix4x4 &Transform::getObjectToWorldMatrix() const
{
    return m_objectToWorldMatrix;
}

const QMatrix4x4 &Transform::getWorldToObjectMatrix() const
{
    return m_worldToObjectMatrix;
}

QVector3D Transform::getPosition() const
{
    return m_objectToWorldMatrix.column(3).toVector3D();
}

