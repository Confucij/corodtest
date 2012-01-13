#include "graph_widget.h"
#include <QtGui>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif


int sdfds=0;
//! [0]
Graph_widget::Graph_widget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
}

Graph_widget::~Graph_widget()
{
}




void Graph_widget::paintEvent(QPaintEvent *event){

emit drw();
}





QSize Graph_widget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize Graph_widget::sizeHint() const
//! [3] //! [4]
{
    return QSize(400, 400);
}

void Graph_widget::initializeGL()
{

}
//! [6]

//! [7]
void Graph_widget::paintGL()
{




}
//! [7]




//! [8]
void Graph_widget::resizeGL(int width, int height)
{

}
//! [8]

//! [9]
void Graph_widget::mousePressEvent(QMouseEvent *event)
{


//    event->button()==Qt::LeftButton? "LeftButton":
//    event->button()==Qt::RightButton?"RightButton":
//    event->button()==Qt::MidButton?  "MidButton":
//    event->button()==Qt::XButton1?   "XButton1":
//                                              "XButton2"

 //   }
    if (event->button()==Qt::RightButton ){
emit addPoint();
emit drw();}

    if (event->button()==Qt::LeftButton ){
        int x=event->x();
        int y=event->y();
        int i;
       StructXY xandy;
       xandy = emit looking(&x,&y);
      if (i==FLS) {}
      emit drw();
    }

}
void Graph_widget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {

    case Qt::Key_Delete:
        emit del();
        emit drw();
        break;
    case Qt::Key_S:
        emit save();
        break;
    case Qt::Key_O:
        emit open ();
        emit drw ();
    case Qt::Key_G:
        emit changegrid();
        emit drw ();

}}


//! [10]
    void Graph_widget::mouseReleaseEvent ( QMouseEvent * event ){


    if( event->button()==Qt::LeftButton ) {
  //  emit correct();
    //emit drw();
    }

    }
void Graph_widget::mouseMoveEvent(QMouseEvent *event) {
    this->setFocus();
    int x,y;
    x = event->x();
    y = event->y();
if (QApplication::mouseButtons()==Qt::LeftButton ){

emit change(x,y);
emit drw();
}



    emit setXY(x,y);

}
//! [10]
