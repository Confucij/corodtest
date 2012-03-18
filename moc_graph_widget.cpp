/****************************************************************************
** Meta object code from reading C++ file 'graph_widget.h'
**
** Created: Mon Feb 6 20:21:27 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graph_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Graph_widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      40,   36,   27,   13, 0x05,
      59,   36,   13,   13, 0x05,
      74,   13,   13,   13, 0x05,
      85,   13,   13,   13, 0x05,
      91,   36,   13,   13, 0x05,
     107,   13,   13,   13, 0x05,
     113,   13,   13,   13, 0x05,
     120,   13,   13,   13, 0x05,
     127,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Graph_widget[] = {
    "Graph_widget\0\0changegrid()\0StructXY\0"
    "x,y\0looking(int*,int*)\0setXY(int,int)\0"
    "addPoint()\0drw()\0change(int,int)\0del()\0"
    "save()\0open()\0correct()\0"
};

void Graph_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Graph_widget *_t = static_cast<Graph_widget *>(_o);
        switch (_id) {
        case 0: _t->changegrid(); break;
        case 1: { StructXY _r = _t->looking((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< StructXY*>(_a[0]) = _r; }  break;
        case 2: _t->setXY((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->addPoint(); break;
        case 4: _t->drw(); break;
        case 5: _t->change((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->del(); break;
        case 7: _t->save(); break;
        case 8: _t->open(); break;
        case 9: _t->correct(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Graph_widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Graph_widget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Graph_widget,
      qt_meta_data_Graph_widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Graph_widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Graph_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Graph_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Graph_widget))
        return static_cast<void*>(const_cast< Graph_widget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Graph_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Graph_widget::changegrid()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
StructXY Graph_widget::looking(int * _t1, int * _t2)
{
    StructXY _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void Graph_widget::setXY(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Graph_widget::addPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Graph_widget::drw()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Graph_widget::change(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Graph_widget::del()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Graph_widget::save()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Graph_widget::open()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Graph_widget::correct()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
