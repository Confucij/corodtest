/****************************************************************************
** Meta object code from reading C++ file 'new_dlg.h'
**
** Created: Mon Feb 6 20:21:23 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "new_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_New_dlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_New_dlg[] = {
    "New_dlg\0\0on_add_Button_clicked()\0"
};

void New_dlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        New_dlg *_t = static_cast<New_dlg *>(_o);
        switch (_id) {
        case 0: _t->on_add_Button_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData New_dlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject New_dlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_New_dlg,
      qt_meta_data_New_dlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &New_dlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *New_dlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *New_dlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_New_dlg))
        return static_cast<void*>(const_cast< New_dlg*>(this));
    if (!strcmp(_clname, "Ui::Newp_dlg"))
        return static_cast< Ui::Newp_dlg*>(const_cast< New_dlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int New_dlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
