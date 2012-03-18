/****************************************************************************
** Meta object code from reading C++ file 'projecthandle.h'
**
** Created: Mon Feb 6 20:21:25 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "projecthandle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projecthandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProjectHandle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   15,   14,   14, 0x05,
      43,   38,   14,   14, 0x05,
      70,   62,   14,   14, 0x05,
      88,   62,   14,   14, 0x05,
     107,   14,   14,   14, 0x05,
     117,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     131,   14,   14,   14, 0x0a,
     142,   14,   14,   14, 0x0a,
     167,  161,   14,   14, 0x0a,
     194,   14,   14,   14, 0x0a,
     207,   14,   14,   14, 0x0a,
     221,   14,   14,   14, 0x0a,
     236,   14,   14,   14, 0x0a,
     250,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ProjectHandle[] = {
    "ProjectHandle\0\0x,z\0imageLoad(int,int)\0"
    "data\0set_glwMap(Image*)\0message\0"
    "addToLog(QString)\0addToList(QString)\0"
    "cleanGl()\0cleanWindow()\0loadData()\0"
    "loadData(PObject*)\0index\0"
    "changeCurrent(QModelIndex)\0newProject()\0"
    "saveProject()\0closeProject()\0openProject()\0"
    "openLib()\0"
};

void ProjectHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProjectHandle *_t = static_cast<ProjectHandle *>(_o);
        switch (_id) {
        case 0: _t->imageLoad((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->set_glwMap((*reinterpret_cast< Image*(*)>(_a[1]))); break;
        case 2: _t->addToLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->addToList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->cleanGl(); break;
        case 5: _t->cleanWindow(); break;
        case 6: _t->loadData(); break;
        case 7: _t->loadData((*reinterpret_cast< PObject*(*)>(_a[1]))); break;
        case 8: _t->changeCurrent((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->newProject(); break;
        case 10: _t->saveProject(); break;
        case 11: _t->closeProject(); break;
        case 12: _t->openProject(); break;
        case 13: _t->openLib(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ProjectHandle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProjectHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ProjectHandle,
      qt_meta_data_ProjectHandle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProjectHandle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProjectHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProjectHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectHandle))
        return static_cast<void*>(const_cast< ProjectHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int ProjectHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ProjectHandle::imageLoad(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProjectHandle::set_glwMap(Image * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProjectHandle::addToLog(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProjectHandle::addToList(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ProjectHandle::cleanGl()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ProjectHandle::cleanWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
