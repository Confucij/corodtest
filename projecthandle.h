#ifndef PROJECTHANDLE_H
#define PROJECTHANDLE_H

#include <QObject>
#include <QPoint>
#include <QVector>
#include <QMap>
#include <QHash>
#include <QString>
#include <QFile>
#include <QColor>
#include <QMessageBox>
#include <QModelIndex>
#include <QtXml/qdom.h>
#include <QTextStream>

#include "type_and_const.h"
#include "lib_dialog.h"
#include "new_dlg.h"





class ProjectHandle : public QObject
{
    Q_OBJECT
public:
    explicit ProjectHandle(QObject *parent = 0);

signals:
    void imageLoad(int x, int z);
    void set_glwMap(Image* data);
    void addToLog(const QString & message);
    void addToList(const QString & message);
    void cleanGl();
    void cleanWindow();

public slots:
    void loadData();
    void changeCurrent(QModelIndex index);
//-------------------------------------------------------
    void newProject();
    void saveProject();
    int closeProject();
    void openProject();
//-------------------------------------------------------
    void openLib();
protected:
    void save_map(const char* filename);
    void clearProject();
    void calculate(PObject *obj); // PUT YOUR CODE HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//-----------------------------------------------------------------------
    QHash<QString,PObject> projObjects;
    Image *map;                     //текущая карта
    QImage *colorMap;               //текущее изображение
//-----------------------------------------------------------------------
    QString projName;
    QString projPath;
    QString libPath;                //путь к папке с файлами материалов
    QString version;

};

#endif // PROJECTHANDLE_H
