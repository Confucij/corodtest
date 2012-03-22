#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QVector>
#include "glwidget.h"
#include "ui_window.h"
#include "map.h"
#include "new_dlg.h"
#include "projecthandle.h"
#include "type_and_const.h"
#include "cut_widget.h"

namespace Ui {
    class Window;
}

class Window : public QMainWindow, public Ui::Window
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();
signals:

public slots:
    void setImageData(int x,int z);
    void addlistlog(QString);
    void additemsList(QString);
    void clean();


private slots:
    void on_action_cut_triggered();

private:
    ProjectHandle *project;
   // GLWidget *glWidget;
};

#endif // WINDOW_H
