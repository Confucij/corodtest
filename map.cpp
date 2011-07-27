#include "map.h"
#include <QtOpenGL>
#include <c++/4.6.0/iostream>
#include <stdio.h>
#include "window.h"
Map::Map()
{
 map = NULL;
 precision=10;
}

unsigned char get_point(Image *data,unsigned int x,unsigned int y){
    //sizeY - строки
    //y - строки
    return data->data[(y*data->sizeY)+x];
}

Map::~Map(){

}

void Map::paint(unsigned int xTopL,unsigned int zTopL,unsigned int xBotomR,unsigned int zBotomR){


    if(map==NULL || map->data==NULL){
        return;
    }

    if(zBotomR==0 || xBotomR==0 ){
      zBotomR=map->sizeY;
      xBotomR=map->sizeX;
    }
    if((xTopL>xBotomR)||(zTopL>zBotomR)){
        xTopL=0;
        zTopL=0;
    }



    glBegin(GL_QUADS);


for(unsigned long int z = zTopL; z < zBotomR-precision; z += precision )
    for(unsigned long int x = xTopL; x < xBotomR-precision; x += precision )    
        {
            //z - строки
          char y = get_point(map,x,z);
          setVertexColor(y);
          glVertex3i(x, y, z);

          // Получаем (X, Y, Z) координаты верхней левой вершины
//          y = (reinterpret_cast<unsigned char [100][100]>(map->data))[x,z+precision];
          y = get_point(map,x,z+precision);
          setVertexColor(y);
          glVertex3i(x, y, z);

          // Получаем (X, Y, Z) координаты верхней правой вершины
          y = get_point(map,x+precision,z+precision);
          setVertexColor(y);
          glVertex3i(x, y, z);

          // Получаем (X, Y, Z) координаты нижней правой вершины
          y = get_point(map,x+precision,z);
          setVertexColor(y);
          glVertex3i(x, y, z);
        }
    glEnd();
    return;
}

 char Map::ImageLoad(const char* filename,unsigned char c_mode){

    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned char planes;          // number of planes in image (must be 1)
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // used to convert bgr to rgb color.
    Image *image=new Image;

    if ((file = fopen(filename, "rb"))==NULL)
    {
      //emit Window::showmsg("10",0);  //printf("File Not Found : %s\n",filename);
        return 1;
    }

    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    // read the width
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
      // printf("Error reading width from %s.\n", filename);
        return 1;
    }
    //printf("Width of %s: %lu\n", filename, image->sizeX);

    // read the height
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
    //    printf("Error reading height from %s.\n", filename);
         return 1;
    }
   // printf("Height of %s: %lu\n", filename, image->sizeY);

    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    if(c_mode==ALL){
    size = image->sizeX * image->sizeY* 3;
    }else{
    size = image->sizeX * image->sizeY;
    }
    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
     //   printf("Error reading planes from %s.\n", filename);
         return 1;
    }
    if (planes != 1) {
       // printf("Planes from %s is not 1: %u\n", filename, planes);
         return 1;
    }
    // read the bpp
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
      //  printf("Error reading bpp from %s.\n", filename);
         return 1;
    }
    if (bpp != 24) {
      //  printf("Bpp from %s is not 24: %u\n", filename, bpp);
         return 1;
    }


    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);


    // read the data.
    image->data = new unsigned char [size];
    if (image->data == NULL) {
     //   printf("Error allocating memory for color-corrected image data");
         return 1;
    }
    memset((void*)image->data,10,size);

    fclose(file);

    file = fopen(filename, "rb");
    fseek(file,54,SEEK_CUR);

    if(c_mode==ALL){
    if (fread(image->data, size, 1, file) != 1) {
       // printf("Error reading image data from %s.\n", filename);
         return 1;
    }
        for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }


    }else{
        switch(c_mode) {
            case RED:{
                for(unsigned int i=0;i<size;i++){
                    fseek(file, 2, SEEK_CUR);
                    fread((void*)(image->data+i),1,1,file);
                }
                break;
            }
            case GREEN:{
                fseek(file, 1, SEEK_CUR);
                for(unsigned int i=0;i<size;i++){
                    fseek(file, 2, SEEK_CUR);
                    fread((void*)(image->data+i),1,1,file);
                }
                break;
            }
                case BLUE:{
                for(unsigned int i=0;i<size;i++){
                    fread((void*)(image->data+i),1,1,file);
                    fseek(file, 2, SEEK_CUR);
                }
                break;
        }
            default:return 1;

    }
}
    fclose(file);
    map=image;
    return 0;

}

 char Map::save_map(const char* filename){
     FILE *f=fopen(filename,"wb");
     fwrite((void*)map->data,map->sizeX*map->sizeY,1,f);
     fclose(f);
     return 0;
}

 char Map::calculate_map(mat_Type opt){
    return 0;
 }


 void Map::setMap(Image *data){
     if(map!=NULL){
         if(map->data!=NULL){
             free(map->data);
         }
     }
     map=data;
 }


 void Map::setVertexColor(unsigned char h){
     if(h<85){
         glColor3b(0,80+(0.6*h),00);
         return;
     }
     if(h>=85 && h<170){
        glColor3b(h,255,00);
        return;
     }
     if(h>=170){
         glColor3b(255,255-h,00);
         return;
     }
 }
