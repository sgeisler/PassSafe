/****************************************************************************
** Meta object code from reading C++ file 'AccountList.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/AccountList.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccountList.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AccountList[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

 // methods: signature, parameters, type, tag, flags
      30,   25,   12,   12, 0x02,
      61,   59,   51,   12, 0x02,
      83,   59,   79,   12, 0x02,
      99,   59,   79,   12, 0x02,
     114,   12,   79,   12, 0x02,
     137,  124,   51,   12, 0x02,
     164,   59,   51,   12, 0x02,
     199,  183,   12,   12, 0x02,
     245,  227,   12,   12, 0x02,
     278,   59,   12,   12, 0x02,
     303,  299,   12,   12, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_AccountList[] = {
    "AccountList\0\0clearClip()\0pass\0"
    "setPassword(QString)\0QString\0i\0"
    "getAccountAt(int)\0int\0getStartAt(int)\0"
    "getStopAt(int)\0getSize()\0i,start,stop\0"
    "getPasswordAt(int,int,int)\0"
    "getPasswordAt(int)\0name,start,stop\0"
    "addAccount(QString,int,int)\0"
    "i,name,start,stop\0editAccount(int,QString,int,int)\0"
    "removeAccountAt(int)\0str\0"
    "copyToClipboard(QString)\0"
};

void AccountList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AccountList *_t = static_cast<AccountList *>(_o);
        switch (_id) {
        case 0: _t->clearClip(); break;
        case 1: _t->setPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: { QString _r = _t->getAccountAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->getStartAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->getStopAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->getSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->getPasswordAt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->getPasswordAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->addAccount((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->editAccount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->removeAccountAt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->copyToClipboard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AccountList::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AccountList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AccountList,
      qt_meta_data_AccountList, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AccountList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AccountList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AccountList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountList))
        return static_cast<void*>(const_cast< AccountList*>(this));
    return QObject::qt_metacast(_clname);
}

int AccountList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
