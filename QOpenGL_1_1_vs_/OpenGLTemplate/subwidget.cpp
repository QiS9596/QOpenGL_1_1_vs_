#include "subwidget.h"

subwidget::subwidget(QWidget *parent) : QWidget(parent)
{

}

subwidget::~subwidget()
{

}

void subwidget::initializeGL(){
    initializeOpenGLFunctions();
}

void subwidget::paintGL(){}
