#ifndef GLWIDGET_H
#define GLWIDGET_H
#include "lib_dialog.h"
#include <QGLWidget>




class Graph_widget : public QGLWidget
{
    Q_OBJECT

public:
    Graph_widget(QWidget *parent = 0);
    ~Graph_widget();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
signals:
    void changegrid();
    StructXY looking(int *x,int *y);
    void setXY(int x,int y);
    void addPoint();
    void drw ();
    void change(int x,int y);
    void del();
    void save();
    void open();
    void correct();
protected:
    void initializeGL();// ���������� ��� ������������� openGL �������������
    void paintGL();
    void resizeGL(int width, int height);
    void mouseReleaseEvent ( QMouseEvent * event );
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);// ��� ���������� ��� ������ ������� repaint()
    void resizeGL(); // ���������� ��� ��������� �������� ���� (��� ��������) �������������
//ololo
private:
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
    QColor qtGreen;
    QColor qtPurple;
};


#endif // GLWIDGET_H



