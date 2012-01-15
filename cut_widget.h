#ifndef CUT_WIDGET_H
#define CUT_WIDGET_H

#include <QWidget>
#include "type_and_const.h"

namespace Ui {
class Cut_widget;
}

class Cut_widget : public QWidget
{
    Q_OBJECT
    
public:
    Cut_widget(PObject *obj, QWidget *parent = 0);
    ~Cut_widget();
    
private:
    Ui::Cut_widget *ui;
    PObject object;
};

#endif // CUT_WIDGET_H
