#ifndef FUNC_H
#define FUNC_H
#include <QString>
#include <QtCore/QCoreApplication>

struct StructXY {
float x;
float y;
        };


struct StructColor {
float x;
float y;
        };


class func
{
public:
    func();
    ~func();
   // void  func::operator [] (const int i);
    void operator+(StructXY XandY);
    void operator=(StructXY XandY);
    StructXY getP(const int i) ;
    float getMaxX();
    float getMinX();
    float getMaxY();
    float getMinY();
    void free();
    int setMaxX(float x);
    int setMinX(float x);
    int setMaxY(float y);
    int setMinY(float y);
    float getCurrentX();
    float getCurrentY();
    int setCurrentY(float y);
    int setCurrentX(float X);
    int setWidth(int w);
    int setHeight(int h);
    int getHeight ();
    int getWidth ();
    int getCount();
    StructXY operator[] (int i);
    bool getinicialize();
    void operator-(int i);
    bool getCurPoint(int *i);
    void setCurPoint(int i);
    void blockCurPoint();
    bool getGrid(StructXY *grd);
    void setGrid(StructXY grd);
    void blockGrid();
    void enableGrid();
    bool getXY();
    void setXY(const bool ok);
    void enableCurPoint();
    void getPath(QString *pth);
    void setPath(QString pth);


   private:
        char inicialize;
        /*
    MaxX,MinX,MaxY,MinY,Point,Grid,XY
          */

        float MinX;
        float MinY;
        float MaxX;
        float MaxY;
        float setX;
        float X;
        float Y;
        int height;
        int width;
        long size;               //размер массива
        int count;              //количество элементов в массиве
        StructXY *p; //begin of massiv
        StructXY grid;
        int curPoint;
        QString path;
};

#endif // FUNC_H
