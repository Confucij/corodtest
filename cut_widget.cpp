#include "cut_widget.h"
#include "ui_cut_widget.h"

Cut_widget::Cut_widget(PObject *obj, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cut_widget)
{
ui->setupUi(this);
object=obj;
}

Cut_widget::~Cut_widget()
{
    emit clear_cut_GL();
    delete ui;
}

void Cut_widget::draw_cut()
{
    QPoint *cut;
    int i;
    if(ui->x_rButton->isChecked()){
        cut = new QPoint[this->object->map->sizeY];
        int x = (this->object->map->sizeX / this->object->width) * ui->pos_sBox->value();
        for(i=0; i < this->object->map->sizeY; i++){
            cut[i].setY(Map::get_point(this->object->map,x,i));
            cut[i].setX(i);
        }
    }else{
        cut = new QPoint[this->object->map->sizeX];
        int x = (this->object->map->sizeY / this->object->height) * ui->pos_sBox->value();
        for(i=0; i < this->object->map->sizeX; i++){
            cut[i].setY(Map::get_point(this->object->map,x,i));
            cut[i].setX(i);
        }

    }
    QPixmap image;
    QPainter painter;
    painter.setBrush(Qt::BDiagPattern);
    painter.begin(&image);
    painter.drawPolygon(cut,i);

    painter.end();
    ui->display_Label->setPixmap(image);
}
