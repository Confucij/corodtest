#ifndef MAP_H
#define MAP_H

#define RED 0
#define GREEN 1
#define BLUE 2
#define ALL 3

typedef struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    unsigned char *data;
} Image;

/*
Тип материала и прочие условия
*/
typedef struct {

} mat_Type;

class Map
{
public:
    Map();
    ~Map();

    void paint(unsigned int xTopL,unsigned int zTopL,unsigned int xBotomR,unsigned int zBotomR);

    /*
    Загружает изображение и разделяет выделяет нужные цветовые каналы
    Результат загружает в переменную map
    */
    char ImageLoad(const char* filename,unsigned char c_mode);
    char save_map(const char* filename);
    //-------------------------------------------------------------------------
    void setMap(Image* data);
    //-------------------------------------------------------------------------
    char calculate_map(mat_Type opt);
private:
    void setVertexColor(unsigned char h); //вычисляет цвет вершины в зависимости от высоты
private:
    Image *map; //хранит полученную карту высот
    unsigned int precision; //шаг с которым будем двигатся по карте высот

};

#endif // MAP_H
