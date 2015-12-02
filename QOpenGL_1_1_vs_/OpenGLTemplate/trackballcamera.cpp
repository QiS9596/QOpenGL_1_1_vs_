#include "trackballcamera.h"

#include "QVector3D"
#include "QMatrix4x4"
#include "qmath.h"

YGL_USE_NAMESPACE

TrackBallCamera::TrackBallCamera()
    : enabled(true)
    , targetPosition(0,0,0)
    , angleH(70)
    , angleV(50)
    , maxAngleV(120)
    , minAngleV(20)
    , distance(10)
    , minDistance(0.1)
{
    update();
}

TrackBallCamera::~TrackBallCamera()
{

}

void TrackBallCamera::rotate(QVector2D delta)
{
    if ( !enabled ) return;
    angleV -= delta.y();
    angleH += delta.x();
    angleV = qMax( angleV, minAngleV );
    angleV = qMin( angleV, maxAngleV );
    update();
}

void TrackBallCamera::translate(QVector2D delta)
{
    transform.translate(delta.x(), delta.y(), 0);
    update();
}

void TrackBallCamera::zoom(qreal delta)
{
    if ( !enabled ) return;
    distance += delta * qAbs( distance );
    distance = qMax( distance, minDistance );
    update();
}

void TrackBallCamera::update()
{
    if ( !enabled ) return;

    QVector3D up(0,1,0);
    QVector3D newCameraPosition;
    qreal theta = qDegreesToRadians(angleV);
    qreal phi   = qDegreesToRadians(angleH);

    /* https://en.wikipedia.org/wiki/Spherical_coordinate_system */
    // Y <-> Z
    newCameraPosition.setX( distance * qSin(theta) * qCos(phi) );
    newCameraPosition.setZ( distance * qSin(theta) * qSin(phi) );
    newCameraPosition.setY( distance * qCos(theta) );
    newCameraPosition += targetPosition;

    transform.lookAt( newCameraPosition, targetPosition, up );
}

