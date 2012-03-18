/****************************************************************************
** Meta object code from reading C++ file 'lib_dialog.h'
**
** Created: Mon Feb 6 20:21:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lib_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lib_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Lib_dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,
      50,   46,   11,   11, 0x0a,
      66,   46,   11,   11, 0x0a,
      90,   46,   81,   11, 0x0a,
     109,   11,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,
     130,   11,   11,   11, 0x0a,
     137,   11,   11,   11, 0x0a,
     144,   11,   11,   11, 0x0a,
     154,   11,   11,   11, 0x0a,
     165,   11,   11,   11, 0x0a,
     176,   11,   11,   11, 0x0a,
     186,   11,   11,   11, 0x0a,
     196,   11,   11,   11, 0x0a,
     206,   11,   11,   11, 0x0a,
     212,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Lib_dialog[] = {
    "Lib_dialog\0\0changegrid()\0save()\0open()\0"
    "draw()\0x,y\0change(int,int)\0setXY(int,int)\0"
    "StructXY\0looking(int*,int*)\0addPoint()\0"
    "setMaxX()\0setX()\0setY()\0correct()\0"
    "setgridX()\0setgridY()\0setMinX()\0"
    "setMaxY()\0setMinY()\0del()\0changelist()\0"
};

void Lib_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Lib_dialog *_t = static_cast<Lib_dialog *>(_o);
        switch (_id) {
        case 0: _t->changegrid(); break;
        case 1: _t->save(); break;
        case 2: _t->open(); break;
        case 3: _t->draw(); break;
        case 4: _t->change((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setXY((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: { StructXY _r = _t->looking((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< StructXY*>(_a[0]) = _r; }  break;
        case 7: _t->addPoint(); break;
        case 8: _t->setMaxX(); break;
        case 9: _t->setX(); break;
        case 10: _t->setY(); break;
        case 11: _t->correct(); break;
        case 12: _t->setgridX(); break;
        case 13: _t->setgridY(); break;
        case 14: _t->setMinX(); break;
        case 15: _t->setMaxY(); break;
        case 16: _t->setMinY(); break;
        case 17: _t->del(); break;
        case 18: _t->changelist(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Lib_dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Lib_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Lib_dialog,
      qt_meta_data_Lib_dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Lib_dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Lib_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Lib_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Lib_dialog))
        return static_cast<void*>(const_cast< Lib_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Lib_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
