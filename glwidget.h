
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glu.h>
#include "map.h"
#include "type_and_const.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void setXPosition(int angle);
    void setYPosition(int angle);
    void setZPosition(int angle);
    void setScale(int zoom);
    void setAngle(int a);
    void setImage(Image* data);
    void clean();
    void draw(int direction, int pos);

signals:
    void xPositionChanged(int angle);
    void yPositionChanged(int angle);
    void zPositionChanged(int angle);
    void scaleChanged(int scale);


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

protected:
    int xRot;
    int yRot;
    int zRot;

    int scale;

    int xPos;
    int yPos;
    int zPos;

    int angle;

    QPoint lastPos;
    Map *map;
    bool init_flag;

};


#endif
