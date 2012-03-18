#include "map.h"
#include <iostream>
#include <stdio.h>
#include "window.h"
#include <time.h>
Map::Map()
{
    map = NULL;
    precision=8;
}

unsigned char Map::get_point(Image *data,unsigned int x,unsigned int y){
    //sizeY - строки
    //y - строки
    return data->data[(y*data->sizeY)+x];
}

Map::~Map(){

}

bool Map::Init(){

    if(map==NULL || map->data==NULL){
        return false;
    }


    list=glGenLists(1);

    glNewList(list,GL_COMPILE_AND_EXECUTE);


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,0,0.3);

    glVertex3f(0,-1,0);
    glVertex3f(map->sizeX,-1,0);
    glVertex3f(map->sizeX,-1,map->sizeY);
    glVertex3f(0,-1,map->sizeY);
    glEnd();


    unsigned char y=0;


    for(unsigned int x=0;x<map->sizeX-precision;x+=precision)
        for(unsigned int z=0;z<map->sizeY-precision;z+=precision){

            glBegin(GL_TRIANGLE_FAN);
            y=get_point(map,x,z);
            setVertexColor(y);
            glVertex3f(x,y,z);

            y=get_point(map,x+precision,z);
            setVertexColor(y);
            glVertex3f(x+precision,y,z);

            y=get_point(map,x+precision,z+precision);
            setVertexColor(y);
            glVertex3f(x+precision,y,z+precision);

            y=get_point(map,x,z+precision);
            setVertexColor(y);
            glVertex3f(x,y,z+precision);

            glEnd();

        }
    glEndList();
    return true;
}

void Map::paint(){
    glCallList(list);
    return;
}

void Map::setMap(Image *data){
    map=data;
}

Image* Map::getMap(){
    return map;
}

void Map::setVertexColor(unsigned char h){
    float k=h/255.0;
    glColor3f(0,k,00);
    return;
}

void Map::clean(){
    map=NULL;
    glNewList(1,GL_COMPILE_AND_EXECUTE);
    glClear(GL_COLOR_BUFFER_BIT);
    glEndList();
    // glDeleteLists(1,1);
}
