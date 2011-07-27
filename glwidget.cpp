
#include <QtGui>
#include <QtOpenGL>
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
    xRot = 0;
    yRot = 0;
    zRot = 0;

}

GLWidget::~GLWidget()
{

}

void GLWidget::openImage(){
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open image"), ".",tr("Image files (*.bmp)"));

    if (!fileName.isEmpty()){
        QByteArray name=fileName.toAscii();
        map->ImageLoad(name.constData(),BLUE);
}

}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(500, 500);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 5;
    while (angle > 360 * 5)
        angle -= 360 * 5;
}

//! [5]
void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}
//! [5]

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

//! [6]
void GLWidget::initializeGL()
{
    map=new Map;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glClearDepth(1.0);

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    map->paint(0,0,0,0);
}

void GLWidget::resizeGL(int width, int height)
{

}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    /*changes git test*/
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot +  2* dx);
        setYRotation(yRot +  2* dy);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot +  2* dx);
        setZRotation(zRot +  2* dy);
    }
    lastPos = event->pos();
}

