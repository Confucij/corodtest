#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include "ui_window.h"
#include "map.h"

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
    void showmsg(const QString & message, int timeout = 0);
private:
   // GLWidget *glWidget;
};

#endif // WINDOW_H
