#include "window.h"


Window::Window(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    connect(xSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setXRotation(int)));
    connect(glWidget, SIGNAL(xRotationChanged(int)), xSlider, SLOT(setValue(int)));
    connect(ySlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setYRotation(int)));
    connect(glWidget, SIGNAL(yRotationChanged(int)), ySlider, SLOT(setValue(int)));
    connect(zSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setZRotation(int)));
    connect(glWidget, SIGNAL(zRotationChanged(int)), zSlider, SLOT(setValue(int)));
 //   connect(this, SIGNAL(showmsg(QString,int)), statusbar, SLOT(showMessage(QString,int)));
    connect(action_OpenProj, SIGNAL(triggered()), glWidget, SLOT(openImage()));

}

Window::~Window()
{

}
