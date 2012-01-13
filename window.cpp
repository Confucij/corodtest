#include "window.h"
#include <QFile>

Window::Window(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    project = new ProjectHandle;

    connect(xSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setXPosition(int)));
    connect(glWidget, SIGNAL(xPositionChanged(int)), xSlider, SLOT(setValue(int)));
    connect(ySlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setYPosition(int)));
    connect(glWidget, SIGNAL(yPositionChanged(int)), ySlider, SLOT(setValue(int)));
    connect(zSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setZPosition(int)));
    connect(glWidget, SIGNAL(zPositionChanged(int)), zSlider, SLOT(setValue(int)));
    connect(zoomSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setScale(int)));
    connect(glWidget, SIGNAL(scaleChanged(int)), zoomSlider, SLOT(setValue(int)));
    connect(angleSlider,SIGNAL(valueChanged(int)),glWidget,SLOT(setAngle(int)));

    //menu block
    connect(action_Import, SIGNAL(triggered()), project, SLOT(loadData()));
    connect(action_NewProj, SIGNAL(triggered()), project, SLOT(newProject()));
    connect(action_Close,SIGNAL(triggered()),project,SLOT(closeProject()));
    connect(action_Exit, SIGNAL(triggered()), this, SLOT(close()));
    connect(action_OpenProj,SIGNAL(triggered()),project,SLOT(openProject()));
    connect(action_Lib,SIGNAL(triggered()),project,SLOT(openLib()));
    connect(action_SaveProj,SIGNAL(triggered()),project,SLOT(saveProject()));

    connect(project,SIGNAL(imageLoad(int,int)),this,SLOT(setImageData(int,int)));
    connect(project,SIGNAL(set_glwMap(Image*)),glWidget,SLOT(setImage(Image*)));
    connect(project,SIGNAL(addToLog(QString)),this,SLOT(addlistlog(QString)));
    connect(project,SIGNAL(cleanGl()),glWidget,SLOT(clean()));
    connect(project,SIGNAL(cleanWindow()),this,SLOT(clean()));
    connect(project,SIGNAL(addToList(QString)),this,SLOT(additemsList(QString)));


    connect(itemsList,SIGNAL(doubleClicked(QModelIndex)),project,SLOT(changeCurrent(QModelIndex)));
}

Window::~Window()
{

}

void Window::clean(){
    listLog->clear();
    itemsList->clear();
    setImageData(10,10);
  return ;

}



void Window::addlistlog(QString msg){
    listLog->addItem(msg);
}


void Window::setImageData(int x,int z){

    zSlider->setMaximum((2*z));
    zSlider->setMinimum(-z / 10);

    xSlider->setMaximum(x / 2);
    xSlider->setMinimum(-x / 2);

    ySlider->setMaximum(z / 2);
    ySlider->setMinimum(-z / 2);

    zSlider->setValue(2*z);
}

void Window::additemsList(QString msg)
{
    itemsList->addItem(msg);
}
