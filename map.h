#ifndef MAP_H
#define MAP_H

#include <QtOpenGL>
#include "type_and_const.h"



/*
Тип материала и прочие условия
*/


class Map
{
public:
    Map();
    ~Map();

    void paint();
    void setVertexColor(unsigned char h); //вычисляет цвет вершины в зависимости от высоты
    bool Init();
    void clean();
    static  unsigned char get_point(Image *data,unsigned int x,unsigned int y);
    //-------------------------------------------------------------------------
    void setMap(Image* data);
    Image* getMap();
    //-------------------------------------------------------------------------
private:
    Image *map; //хранит полученную карту высот
    unsigned int precision; //шаг с которым будем двигатся по карте высот
    int Zoom;								// Коэффициент увиличения
    GLint list;
};

#endif // MAP_H
