#include "lib_dialog.h"
#include "ui_lib_dialog.h"
#include "func.h"
#include <QtOpenGL>
#include <QPainterPath>
#include <QColorDialog>
#include <QFile>
#include <stdio.h>
#include <QCoreApplication>
#include <math.h>


Lib_dialog::Lib_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lib_dialog)
{
    ui->setupUi(this);


}

Lib_dialog::~Lib_dialog()
{
    delete ui;
}



Lib_dialog::Lib_dialog(const QString lib_path) :
    QDialog(NULL),
    ui(new Ui::Lib_dialog)
{
    ui->setupUi(this);
    fx.setPath(lib_path);


    QMenuBar *menuBar = new QMenuBar(this);
    QAction *action_save= new QAction("save",this);
    QAction *action_change= new QAction("change",this);
    QAction *action_load= new QAction("load",this);

    menuBar->insertAction(NULL,action_save);
    menuBar->insertAction(NULL,action_change);
    menuBar->insertAction(NULL,action_load);



    connect(action_save,SIGNAL( triggered()) ,this,SLOT(save()));
    connect(action_load,SIGNAL( triggered()),this,SLOT(open()));
    connect(action_change,SIGNAL( triggered()),this,SLOT(changelist()));


    connect(ui->widget, SIGNAL(looking(int*,int*)), this, SLOT(looking(int*,int*)));
    connect(ui->widget, SIGNAL(setXY(int,int)), this, SLOT(setXY(int,int)));
    connect(ui->widget, SIGNAL(addPoint()), this, SLOT(addPoint()));
    connect(ui->MaxX,SIGNAL(textChanged ()),this,SLOT(setMaxX()));
    connect(ui->MinX,SIGNAL(textChanged ()),this,SLOT(setMinX()));
    connect(ui->MinY,SIGNAL(textChanged ()),this,SLOT(setMinY()));
    connect(ui->MaxY,SIGNAL(textChanged ()),this,SLOT(setMaxY()));
    connect(ui->LX,SIGNAL(textChanged ()),this,SLOT(setX()));
    connect(ui->LY,SIGNAL(textChanged ()),this,SLOT(setY()));
    connect(ui->gridX,SIGNAL(textChanged ()),this,SLOT(setgridX()));
    connect(ui->gridY,SIGNAL(textChanged ()),this,SLOT(setgridY()));
    connect(ui->widget,SIGNAL(drw ()),this,SLOT( draw ()));
    connect(ui->widget,SIGNAL(del ()),this,SLOT( del ()));
    connect(ui->widget,SIGNAL(correct ()),this,SLOT( correct ()));
    connect(ui->widget,SIGNAL(save ()),this,SLOT( save ()));
    connect(ui->widget,SIGNAL(open ()),this,SLOT( open ()));
    connect(ui->widget,SIGNAL(changegrid()),this,SLOT( changegrid()));
    connect(ui->widget,SIGNAL(change(int,int)),this,SLOT(change(int,int)));

    //-------------------------------------------------------------------------------------------
    // в lib_path я передам адрес библиотеки(папки с файлами). Сохрани его сам кудато)))        //
    //--------------------------------------------------------------------------------------------
}



//}


void Lib_dialog::changelist(){



}


void Lib_dialog::setgridX(){
    StructXY grid;
    fx.getGrid(&grid);
    QString str=ui->gridX->toPlainText () ;
    bool ok;
    float x= str.toFloat(&ok);
    if ( ok) {
        grid.x=x;
        fx.setGrid(grid);
        draw();
    } else {
        char st1r[20];
        x=grid.x;
        sprintf(st1r,"%f",x);
        ui->gridX->setText(st1r);
    }
}

void Lib_dialog::setgridY(){
    StructXY grid;
    fx.getGrid(&grid);
    QString str=ui->gridY->toPlainText () ;
    bool ok;
    float y= str.toFloat(&ok);
    if ( ok) {
        grid.y=y;
        fx.setGrid(grid);
        draw();
    } else {
        char st1r[20];
        y=grid.y;
        sprintf(st1r,"%f",y);
        ui->gridY->setText(st1r);
    }

}


void Lib_dialog::setX() {
    int i;
    if (  !(QApplication::mouseButtons()==Qt::LeftButton ) && fx.getCurPoint(&i) ) {
        QString str=ui->LX->toPlainText () ;
        bool ok;
        float x= str.toFloat(&ok);
        int i;
        if ( fx.getCurPoint(&i)&& ok ) {
            StructXY xay;
            xay=fx[i];
            xay.x=x;
            //        fx-i;
            //        fx.enableCurPoint();
            //        fx+xay;

            fx=xay;
            draw();
        } else {
            char st1r[20];
            x=fx[i].x;
            sprintf(st1r,"%f",x);
            ui->LX->setText(st1r);
        }
    }
}

void Lib_dialog::setY() {
    int i;
    if (  !(QApplication::mouseButtons()==Qt::LeftButton ) && fx.getCurPoint(&i) ) {
        QString str=ui->LY->toPlainText () ;
        bool ok;
        float y= str.toFloat(&ok);
        int i;
        if ( fx.getCurPoint(&i)&& ok ) {
            StructXY xay;
            xay=fx[i];
            xay.y=y;
            fx=xay;
            draw();
        } else {
            char st1r[20];
            y=fx[i].y;
            sprintf(st1r,"%f",y);
            ui->LY->setText(st1r);
        }
    }
}





void Lib_dialog::changegrid() {
    StructXY grid;
    if (fx.getGrid(&grid))
    {fx.blockGrid();} else {
        bool ok=fx.getinicialize();
        if (ok) {fx.enableGrid();}}
}


void Lib_dialog::open(){


    QString Name = QFileDialog::getOpenFileName(NULL,tr("Open function"), ".",tr("Project files (*.txt)"));
    if (Name.isEmpty()){
        return;
    }
    QFile * file = new QFile (Name);
    if (!file->open(QIODevice::ReadOnly)) {
        return;

    }

    { /*fseek ( file ,0 , SEEK_END );*/
        size_t size;
        size_t count;
        int i=0;
        char *ptr;
        ptr = new char [10];
        size=10;
        count=1;
        int lastseek=0;
        bool ok=true;
        StructXY lol;
        fx.free();
        bool ok1=false;
        while (!file->atEnd()) {
            ok=!ok;
            file->read(ptr,size);
            // fread (ptr,  size,  count,file);
            float sx=atof(ptr);
            if (ok) {
                lol.y=sx;
                fx+lol;
            } else {lol.x=sx;}

            i=0;
            while( !((ptr[i] ==' ') || (ptr[i]=='\n')) )
            {i++;
                if (ptr[i]=='_') break;
            }
            if (ok1) {file->close(); draw();}
            if (ptr[i]=='\n') {i++;}
            if (ptr[i]=='_') break;
            lastseek=lastseek+i+1;
            file->seek(lastseek);
        }


        file->close();}
    return;
}

void Lib_dialog::save(){
    FILE * file;

    QString Name = QFileDialog::getOpenFileName(NULL,tr("Open function"), ".",tr("Project files (*.txt)"));
    file= fopen("file.txt","w");
    if (file == NULL) {

        perror ("Error opening file");
        return;}
    else
    {   for (int i=0; i<fx.getCount();i++) {
            fprintf(file,"%f %f\n",fx[i].x,fx[i].y);
        }
        fprintf(file,"%s","_____________________");
        fclose (file);
    }
    return ;



}


void Lib_dialog::del() {
    int i;
    if (fx.getCurPoint(&i)) {
        fx-i;
    }
}


void Lib_dialog::correct() {
    int i;
    if (
            fx.getCurPoint(&i)){
        StructXY xy=fx[i];
        fx-i;
        fx+xy;}
}



void Lib_dialog::change(int x,int y) {
    int i;

    if (fx.getCurPoint(&i)) {
        StructXY xy;
        QRect geom;
        geom=ui->widget->geometry();
        int hght=geom.height();
        int wdth=geom.width();
        float mx=fx.getMaxX()-fx.getMinX();
        xy.x=mx/wdth*x+fx.getMinX();
        float my=fx.getMaxY()-fx.getMinY();
        xy.y=my/hght*(hght-y)+fx.getMinY();
        fx=xy;

    }


}

StructXY Lib_dialog::looking(int *x,int *y) {
    StructXY XY;
    XY.x=0;
    XY.y=0;
    QRect geom;
    geom=ui->widget->geometry();
    int hght=geom.height();
    int wdth=geom.width();
    float minx=fx.getMinX();
    float miny=fx.getMinY();
    float maxx=fx.getMaxX();
    float maxy=fx.getMaxY();
    float wd=maxx-minx;
    float hd=maxy-miny;
    float n;
    int i;
    bool ok=false;
    if (fx.getCurPoint(&i)) {
        StructXY xy=fx[i];
        fx-i;
        fx+xy;

        ok =true;}

    int cnt=fx.getCount();
    i=0;
    while (i<cnt) {
        n=(fx[i].x-minx)/wd;
        int x1=n*wdth;
        n=(fx[i].y-miny)/hd;
        int y1=hght-n*hght;
        if ((*x>x1-4) && (*x<x1+4) &&(*y>y1-4) && (*y<y1+4)) {
            XY.x=fx[i].x;
            XY.y=fx[i].y;
            *x=x1;
            *y=y1;
            fx.setCurPoint(i);
            setXY(*x,*y);
            return XY;}
        i++;
    }

    fx.blockCurPoint();
}




void Lib_dialog::setMaxX()
{

    QString str=ui->MaxX->toPlainText () ;
    bool ok;
    float x= str.toFloat(&ok);
    if ( ok) {
        fx.setMaxX(x);
        draw();
    } else {
        char st1r[20];
        x=fx.getMaxX();
        sprintf(st1r,"%f",x);
        ui->MaxX->setText(st1r);
    }
}


void Lib_dialog::setMinX()
{

    QString str=ui->MinX->toPlainText () ;
    bool ok;
    float x= str.toFloat(&ok);
    if ( ok) {
        fx.setMinX(x);
        draw();
    } else {
        char st1r[20];
        x=fx.getMinX();
        sprintf(st1r,"%f",x);
        ui->MinX->setText(st1r);
    }
}

void Lib_dialog::setMaxY()
{

    QString str=ui->MaxY->toPlainText () ;
    bool ok;
    float x= str.toFloat(&ok);
    if ( ok) {
        fx.setMaxY(x);
        draw();
    } else {
        char st1r[20];
        x=fx.getMaxY();
        sprintf(st1r,"%f",x);
        ui->MaxY->setText(st1r);
    }
}

void Lib_dialog::setMinY()
{

    QString str=ui->MinY->toPlainText () ;
    bool ok;
    float x= str.toFloat(&ok);
    if ( ok) {
        fx.setMinY(x);
        draw();
    } else {
        char st1r[20];
        x=fx.getMinY();
        sprintf(st1r,"%f",x);
        ui->MinY->setText(st1r);
    }
}


void Lib_dialog::draw (){



    QPainter  painter;
    painter.begin(ui->widget);
    if (fx.getCount()==0 && fx.getinicialize()) {painter.end(); return;}
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setStyle(Qt::SolidLine); //��� ����� �� �����������
    pen.setWidth(1);//������� �����
    pen.setBrush(Qt::green); //����
    pen.setCapStyle(Qt::RoundCap); //������������ � �����
    pen.setJoinStyle(Qt::RoundJoin); //������ ����
    painter.setPen(pen);
    //QColor	currentColor ();
    QRect geom;
    geom=ui->widget->geometry();
    int hght=geom.height();
    int wdth=geom.width();
    float minx=fx.getMinX();
    float miny=fx.getMinY();
    float maxx=fx.getMaxX();
    float maxy=fx.getMaxY();
    float wd=maxx-minx;
    float hd=maxy-miny;

    StructXY grid;
    if (fx.getGrid(&grid)) {
        float dfs=round(minx/grid.x)*grid.x;
        do {
            float n=(dfs-minx)/wd;
            int x1=n*wdth;
            QLine ln (x1,0,x1,hght);
            dfs+=grid.x;
            painter.drawLine (ln);}
        while (dfs<maxx+grid.x);

        dfs=round(miny/grid.y)*grid.y;
        do {
            float n=(dfs-miny)/hd;
            int y1=n*hght;
            QLine ln (0,y1,wdth,y1);
            dfs+=grid.y;
            painter.drawLine (ln);}
        while (dfs<maxy+grid.y);


    }
    pen.setBrush(Qt::black);
    painter.setPen(pen);
    float n=(fx[0].x-minx)/wd;
    int x1=n*wdth;
    n=(fx[0].y-miny)/hd;
    int y1=hght-n*hght;
    int i;
    {
        QPainterPath path;

        path.addEllipse(x1-4,y1-4,8,8);
        painter.fillPath(path, Qt::red);

        int x2,y2;
        int i;
        for (i=1; i<fx.getCount(); i++){
            n=(fx[i].x-minx)/wd;
            x1=n*wdth;
            n=(fx[i-1].x-minx)/wd;
            x2=n*wdth;
            n=(fx[i].y-miny)/hd;
            y1=hght-n*hght;
            n=(fx[i-1].y-miny)/hd;
            y2=hght-n*hght;
            path.addEllipse(x1-4,y1-4,8,8);
            painter.fillPath(path, Qt::red);
            QLine ln ( x1,y1,x2,y2);
            painter.drawLine (ln);


        }}

    QPainterPath path;
    if (fx.getCurPoint(&i)) {
        n=(fx[i].x-minx)/wd;
        int x=n*wdth;
        n=(fx[i].y-miny)/hd;
        int y=hght-n*hght;

        path.addEllipse(x-5,y-5,10,10);
        painter.fillPath(path, Qt::blue);
    }
    painter.end();
}


void Lib_dialog::addPoint() {
    int i;
    if ( !(fx.getinicialize()) || ( fx.getCurPoint(&i) )) return ;


    StructXY pnt;
    QString str=ui->LX->toPlainText();
    bool ok=true;
    QMessageBox msgBox;
    msgBox.setText("Values is not float type");


    pnt.x=str.toFloat(&ok);
    if (ok==false) {
        msgBox.exec();
        return ;

    }
    str=ui->LY->toPlainText();
    pnt.y=str.toFloat(&ok);

    if (ok==false) {
        msgBox.exec();
        return ;

    }
    fx+pnt;
    return ;
}



void Lib_dialog::setXY(int x,int y)
{
    char str[20];
    QRect geom;
    int hght;

    if (fx.getCurPoint(&hght)) {
        if (!(QApplication::mouseButtons()==Qt::LeftButton ))
        {
            sprintf(str,"%f",fx[hght].x);
            ui->LX->setText(str);
            for (int i=0; i<20;i++) {
                str[i]='\0';}
            sprintf(str,"%f",fx[hght].y);
            ui->LY->setText(str);
            return;}
    }

    geom=ui->widget->geometry();
    hght=geom.height();
    int wdth=geom.width();
    float mx=fx.getMaxX()-fx.getMinX();
    float nx=mx/wdth*x+fx.getMinX();
    float my=fx.getMaxY()-fx.getMinY();
    float ny=my/hght*(hght-y)+fx.getMinY();
    sprintf(str,"%f",nx);
    ui->LX->setText(str);
    // Optimaze
    for (int i=0; i<20;i++) {
        str[i]='\0';}
    sprintf(str,"%f",ny);
    ui->LY->setText(str);
}
