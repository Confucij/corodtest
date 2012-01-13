#ifndef TYPE_AND_CONST_H
#define TYPE_AND_CONST_H
#include <QString>


typedef struct Image {
    unsigned int sizeX;
    unsigned int sizeY;
    unsigned char *data;
} Image;

typedef struct PObject
{
    Image *map;         //обработанная карта высот
    QString path;       //полный путь к исходному файлу

    QString material;   //

    float   width;      //размеры в микрометрах
    float   height;
}PObject;

//------------------------
#define RED 0
#define GREEN 1
#define BLUE 2
#define ALL 3
//------------------------


//------------------------
#define BMP 1
#define JPEG 2
#define PNG 3
//------------------------


#endif // TYPE_AND_CONST_H
