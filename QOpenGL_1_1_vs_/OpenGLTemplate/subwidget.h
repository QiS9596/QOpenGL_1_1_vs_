#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QOpenGLWidget>
#include "glstdafx.h"
#include <QOpenGLFunctions_1_1>
#include <QOpenGLTexture>
#include <gl/GL.h>
#include <gl/GLU.h>


YGL_BEGIN_NAMESPACE
class subwidget : public QOpenGLWidget, protected QOpenGLFunctions_1_1
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = 0);
    ~subwidget();
    void initializeGL();
    void paintGL();
signals:

public slots:
};
YGL_END_NAMESPACE
#endif // SUBWIDGET_H
