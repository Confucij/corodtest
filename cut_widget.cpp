#include "cut_widget.h"
#include "ui_cut_widget.h"

Cut_widget::Cut_widget(PObject *obj, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cut_widget)
{
ui->setupUi(this);
}

Cut_widget::~Cut_widget()
{
    delete ui;
}

void Cut_widget::draw_cut()
{

}
