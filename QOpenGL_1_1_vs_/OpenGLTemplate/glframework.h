/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef OPENGLTEMPLATE_H
#define OPENGLTEMPLATE_H

#include "glstdafx.h"

#include <vector>
#include <cmath>

#include <QVector2D>
#include <QVector3D>
#include <QMatrix4x4>
#include <QQuaternion>

#include <QOpenGLFunctions_1_1>
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <QBasicTimer>

#include "trackballcamera.h"
#include "openmeshframework.h"

YGL_BEGIN_NAMESPACE

// https://doc-snapshots.qt.io/qt5-5.4/qopenglwidget.html
class GLFramework : public QOpenGLWidget, protected QOpenGLFunctions_1_1
{
    Q_OBJECT

public:
    explicit GLFramework(QWidget *parent = 0);
    ~GLFramework();
	bool LoadMesh(OMT::MyTriMesh * mesh, std::string filename);
//===============================
public:
	void SaveCurrentVertex();
	void SaveCurrentFace();
	//OMT::MyTriMesh temp;
	//OMT::MyTriMesh::VertexHandle vhandle[100];
	void selectVertex();
	void selectBorder();
	void sortBorder();
	void FindPointInMTriMesh(int index,OMT::VIter & v_it);
	void FindFaceInMTriMesh(int index, OMT::FIter & f_it);
	bool IsInTheBorder(int index);
private:
	OMT::VIter result;
	//OMT::MyTraits::Point result;
	std::vector<int> selectPoints;
	std::vector<int> border;
	std::vector<int> sortedBorder;
	std::vector<int> selectedFaces;
	int current = 0;
//===============================
private:
	QOpenGLTexture * floor;
	QOpenGLTexture * wall1;
	QOpenGLTexture * wall2;
	QOpenGLTexture * wall3;
	QOpenGLTexture * LoadGLTextures(const char * name);
	void drawScene();
	bool XOR(bool flag1, bool flag2);
private:
	GLdouble current_modelview_matrix[16],
		current_projection_matrix[16];
	GLint current_viewport_matrix[4];
	GLfloat gl_x, gl_y;
	GLdouble objX, objY, objZ;
	int PointedFaceIdx;

	void meshVertexRender(GLfloat x_coor, GLfloat y_coor);
	void findNearestVertex(GLfloat objx, GLfloat objy, GLfloat objz);
	void findNearestFace();
	float getDistance(GLfloat verx, GLfloat very, GLfloat verz);
	void drawSelectedVertex();
	void drawCurrentFace();
	void drawBorder();
	void drawStoredFace();
	bool isRecorded(int index, std::vector<int> & memory);
	//use iterator to select the point in the SelectPoint to Border
	//only if the point from set SelectPoint's onering vv iterator 
	//can get a point not belone to the set SelectPoint, will we put
	//it into the border set
protected:
    /* More event: https://doc-snapshots.qt.io/qt5-5.4/qwidget.html */
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent * event);

    /* OpenGL initialization */
    void initializeGL();

    /* Window resize event */
    void resizeGL(int w, int h);

    /*** Implementation of paint method, only when needed would be updated ***/
    /* Attention! Not all frames are painted, use "this->update()" to force update */
    void paintGL();

    /* Timer event */
    void timerEvent(QTimerEvent *e);

private:

    /* Apply camera settings to OpenGL */
    void applyCameraSetting(Camera &cam);

    void drawGrid(int size = 20);

    void drawLocator(float size = 3);
    
    /* Mesh rendering */
    void RenderSolid();

private:
    /* timerEvent control */
    QBasicTimer mTimer;
    
    /* Caching mouse positions */
    QVector2D mCacheRotPos;      // for camera rotation
    
public:
    bool mEnabledGrid;
    bool mEnabledLocator;
    
    TrackBallCamera mTrackBallCamera;
    
    OMT::MyTriMesh* mTriMesh;
};

YGL_END_NAMESPACE

#endif // OPENGLTEMPLATE_H
