#ifndef CUT_WIDGET_H
#define CUT_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include "map.h"
#include "type_and_const.h"

namespace Ui {
class Cut_widget;
}

class Cut_widget : public QWidget
{
    Q_OBJECT
    
public:
    Cut_widget(PObject *obj, QWidget *parent = NULL);
    ~Cut_widget();
signals:
    void draw_cut_GL();
    void clear_cut_GL();
public slots:
    void draw_cut();
private:
    Ui::Cut_widget *ui;
    PObject *object;
};

#endif // CUT_WIDGET_H
