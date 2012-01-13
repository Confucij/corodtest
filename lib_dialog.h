#ifndef LIB_DIALOG_H
#define LIB_DIALOG_H
#include <func.h>
#include <QDialog>

#define SEARCHING 1
#define SETTING 0
#define FLS 216613626

namespace Ui {
    class Lib_dialog;
}

class Lib_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Lib_dialog(QWidget *parent = 0);
    Lib_dialog (const QString lib_path = 0);
    ~Lib_dialog();
public slots:
    void changegrid();
    void save();
    void open();
    void draw ();
    void change(int x,int y);
    void setXY(int x, int y);
    StructXY looking(int *x,int *y);
    void addPoint();
    void setMaxX();
    void setX();
    void setY();
    void correct();
    void setgridX();
    void setgridY();
    void setMinX();
    void setMaxY();
    void setMinY();
    void del();
    void changelist();
private:
    func fx;
    Ui::Lib_dialog *ui;

};

#endif // LIB_DIALOG_H
