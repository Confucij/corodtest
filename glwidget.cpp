
#include <QtGui>
#include <QtOpenGL>
#include <GL/glu.h>
#include <QString>
#include <QByteArray>

#include <math.h>

#include "glwidget.h"
#include "map.h"

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

//! [0]
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot    = 1;
    yRot    = 1;
    zRot    = 1;
    scale   = 1;
    angle   = 1;
    init_flag=false;
    map = new Map;
}

GLWidget::~GLWidget()
{
    delete map;

}

void GLWidget::setImage(Image* data){
    map->setMap(data);
    init_flag=false;
    xRot=0;
    yRot=0;
    zRot=0;

    xPos=0;
    yPos=0;
    zPos=0;

    updateGL();    //

}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(500, 500);
}


void  GLWidget::setScale(int zoom)
{
    scale=zoom;
    emit scaleChanged(zoom);
    updateGL();
}

void GLWidget::setXPosition(int angle)
{
    if (angle != xPos) {
        xPos = angle;
        emit xPositionChanged(angle);
        updateGL();
    }
}

void GLWidget::setYPosition(int angle)
{
    if (angle != yPos) {
        yPos = angle;
        emit yPositionChanged(angle);
        updateGL();
    }
}

void GLWidget::setZPosition(int angle)
{
    if (angle != zPos) {
        zPos = angle;
        emit zPositionChanged(angle);
        updateGL();
    }
}

void GLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.3f, 0.3f, 0.3f, 0.3f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void GLWidget::setAngle(int a){
    angle=a;
    updateGL();
}

void coord (float *x,float *y, float xc, float yc, float angle, float r)

{   *x = r*cos(angle) + xc;
    *y = r*sin(angle) + yc;
    return;
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-xPos,-yPos,-zPos);
    if(!init_flag){
        init_flag=map->Init();
    } else {
        float  xp= map->getMap()->sizeX / 2;
        float  zp=map->getMap()->sizeY / 2;
        float x,z;
        coord(&x,&z,xp,zp,scale/57.3,(xp/4.0));
        gluLookAt(x, 255, z,xp,angle,zp,  0, 1, 0);
        map->paint();
    }
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);		// Reset The Current Viewport And Perspective Transformation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,4000.0f);
    glMatrixMode(GL_MODELVIEW);
}


void GLWidget::clean(){
    map->clean();
    init_flag=false;
    xRot=0;
    yRot=0;
    zRot=0;

    xPos=0;
    yPos=0;
    zPos=0;

    updateGL();    //

}


