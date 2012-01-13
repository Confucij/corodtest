#include "func.h"


func::func()
{
  size= 10;
  count=0;

  p = new StructXY[size];
  //memcpy(p,p,10);
           //   if(!p) {??}
    MinX=0;
    MinY=0;
    MaxX=0;
    MaxY=0;
    X=0;
    Y=0;
    inicialize=0;
    curPoint=0;
    grid.x=0.2;
    grid.y=0.2;

}



  func ::~func() {
           // if(p) delete[] (p);
        }

void func::free(){
if(p) delete[] (p);
func();

}

  bool func::getinicialize(){
    bool ok=false;
    char init;
    init=inicialize  & 0b11110000;
      if (init==-16) {
          ok=true;}
        return ok;
    }

  void func::operator-(int i) {

      int j;
      if (getCurPoint(&j)) {
        if (i==j) {blockCurPoint();}
      }
      if (count==0 || i>count) {return;}
      StructXY *p1;
      p1=p;
      if (i==0) {
          p=&p[i+1];}
      else {
          for (j=i;j<count-1;j++){
            p[j]=p[j+1];}
           }
      count--;
  }

void  func::operator+(StructXY XandY){
if (size==count) {
 StructXY *p1 = new StructXY[size+5];
 memcpy(p1,p,size*sizeof(StructXY));
  size+=5;
  delete p;
  p=p1;
}

register int i=0;
while ((p[i].x<XandY.x) && (i<count))
 {i++;}
register int j;

for (j=count;j>i;j-- ){
    p[j]=p[j-1];
}
count++;
p[i]=XandY;
}


StructXY func::operator[](int i) {
    if(i < count)
        return p[i];
}


StructXY func::getP(const int i) {
    return p[i];
}

int func::setWidth(int w){
    width=w;
    return 0;
}

int func::setHeight(int h){
    height=h;
    return 0;
}

int func::getHeight (){
    return height;
}

int func::getWidth () {
    return width;
}

float func::getMaxX(){
    return MaxX;
}

float func::getMinX(){
    return MinX;
}

float func::getMaxY(){
    return MaxY;
}

float func::getMinY(){
    return MinY;
    }

int func::setMaxX(float x){
    MaxX=x;
    inicialize= inicialize| 0b10000000;
    return 0;
    }

int func::setMinX(float x){
    MinX=x;
    inicialize= inicialize| 0b01000000;
    return 0;
    }

int func::setMaxY(float y){
    MaxY=y;
    inicialize= inicialize| 0b00100000;
    return 0;
    }

int func::setMinY(float y){
    MinY=y;
    inicialize= inicialize| 0b00010000;
    return 0;
}

float func::getCurrentX(){
    return X;
}

int func::setCurrentY(float y){
    Y=y;
    return 0;
}

int func::setCurrentX(float x){
    X=x;
    return 0;
}


int func::getCount (){
    return count;
}

bool func::getCurPoint(int *i){
    bool ok=false;
    char init;
    init=inicialize  & 0b0001000;
      if (init==8) {
          ok=true;}
      *i=curPoint;
        return ok;
    }


void func::blockCurPoint(){
  inicialize=inicialize & 0b11110111;
}

void func::setCurPoint(int i){

    curPoint=i;
  inicialize=inicialize | 0b00001000;

     return;

}

void func::enableCurPoint(){


  inicialize=inicialize | 0b00001000;

     return;

}

bool func::getGrid(StructXY *grd){
    bool ok=false;
    char init;
    init=inicialize  & 0b00000100;
      if (init==4) {
          ok=true;}
      *grd=grid;
        return ok;
    }

 void  func::operator=(StructXY XandY) {

     p[curPoint].x=XandY.x;
     p[curPoint].y=XandY.y;

 }

bool func::getXY(){
    bool ok=false;
    char init;
    init=inicialize  & 0b0000010;
      if (init==2) {
          ok=true;}
        return ok;
}

void func::setXY(const bool ok) {
    if (ok) {
    inicialize=inicialize | 0b00000010;
        } else {inicialize=inicialize & 0b11111101;}


}


void func::blockGrid(){
  inicialize=inicialize & 0b11111011;
}

void func::enableGrid(){
  inicialize=inicialize | 0b00000100;
}

void func::setGrid(StructXY grd){
    grid=grd;
  inicialize=inicialize | 0b00000100;
     return;
}

void func::getPath(QString *pth){
   *pth=path;
}

void func::setPath(QString pth){
path=pth;
}
