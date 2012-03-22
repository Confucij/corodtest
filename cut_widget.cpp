#include "cut_widget.h"
#include "ui_cut_widget.h"

Cut_widget::Cut_widget(PObject *obj, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Cut_widget)
{
ui->setupUi(this);
object=obj;
cut=NULL;
image=NULL;
draw_cut();
emit draw_cut_GL(1,ui->pos_Box->value());
}

Cut_widget::~Cut_widget()
{
    emit clear_cut_GL();
    delete ui;
}

void Cut_widget::draw_cut()
{

    if(cut!=NULL){
        delete cut;
    }
    if(image!=NULL){
        delete image;
    }
    int i;
if(this->object->height==0){
    this->object->height=1;
}
if(this->object->width==0){
    this->object->width=1;
}

    if(ui->x_rButton->isChecked()){
        image = new QPixmap(object->map->sizeY,500);
        ui->pos_Box->setMaximum(object->width);
        cut = new QPolygon(this->object->map->sizeY);
        cut->append(QPoint(0,500));
      /*  int x = ( this->object->map->sizeX /  this->object->width  ) * ui->pos_Box->value();
        for(i=1; i < this->object->map->sizeY; i++){
           QPoint p;
            p.setY(image->height()-Map::get_point(this->object->map,x,i-1));
            p.setX(i);
            cut->append(p);
      }*/
    }else{
        image = new QPixmap(object->map->sizeX,500);
        ui->pos_Box->setMaximum(object->height);
        cut = new QPolygon(this->object->map->sizeX);
       cut->append(QPoint(0,500));
        int x = ( this->object->map->sizeY / this->object->height) * ui->pos_Box->value();
            for(i=1; i < this->object->map->sizeX; i++){
                QPoint p;
                p.setY(image->height()-Map::get_point(this->object->map,x,i-1));
                p.setX(i);
                cut->append(p);

            }

        }
 //           cut->append(QPoint(image->width(),image->height()));

cut->append(QPoint(25,450));
cut->append(QPoint(50,400));
cut->append(QPoint(100,300));
cut->append(QPoint(200,250));
cut->append(QPoint(300,0));
        QPainter painter;
        QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    painter.begin(image);
    painter.setPen(pen);
    painter.fillRect(0,0,image->width(),image->height(),QBrush(Qt::white));
    painter.setBrush(QBrush(Qt::gray));
    painter.drawConvexPolygon(*cut);
    painter.end();
    ui->display_Label->setPixmap(image->scaled(ui->display_Label->size(),Qt::KeepAspectRatio));
 //   if(ui->x_rButton->isChecked()){
 //       emit draw_cut_GL(1,ui->pos_Box->value());
 //   }else{
 //       emit draw_cut_GL(0,ui->pos_Box->value());
 //   }


}
