/****************************************************************************
** Meta object code from reading C++ file 'CWeather.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CWeather.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CWeather.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CWeather_t {
    QByteArrayData data[17];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CWeather_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CWeather_t qt_meta_stringdata_CWeather = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CWeather"
QT_MOC_LITERAL(1, 9, 10), // "SlotRelied"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 36, 10), // "m_NewReply"
QT_MOC_LITERAL(5, 47, 8), // "InitView"
QT_MOC_LITERAL(6, 56, 11), // "InitConnect"
QT_MOC_LITERAL(7, 68, 17), // "SedWeatherRequest"
QT_MOC_LITERAL(8, 86, 11), // "strCityName"
QT_MOC_LITERAL(9, 98, 9), // "parseJson"
QT_MOC_LITERAL(10, 108, 11), // "QByteArray&"
QT_MOC_LITERAL(11, 120, 9), // "byteArray"
QT_MOC_LITERAL(12, 130, 8), // "UpdataUI"
QT_MOC_LITERAL(13, 139, 10), // "SlotSearch"
QT_MOC_LITERAL(14, 150, 20), // "PainterWeatcherCurve"
QT_MOC_LITERAL(15, 171, 7), // "QLabel*"
QT_MOC_LITERAL(16, 179, 10) // "pDrawLabel"

    },
    "CWeather\0SlotRelied\0\0QNetworkReply*\0"
    "m_NewReply\0InitView\0InitConnect\0"
    "SedWeatherRequest\0strCityName\0parseJson\0"
    "QByteArray&\0byteArray\0UpdataUI\0"
    "SlotSearch\0PainterWeatcherCurve\0QLabel*\0"
    "pDrawLabel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CWeather[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      12,    0,   65,    2, 0x08 /* Private */,
      13,    0,   66,    2, 0x08 /* Private */,
      14,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void CWeather::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CWeather *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SlotRelied((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->InitView(); break;
        case 2: _t->InitConnect(); break;
        case 3: _t->SedWeatherRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->parseJson((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->UpdataUI(); break;
        case 6: _t->SlotSearch(); break;
        case 7: _t->PainterWeatcherCurve((*reinterpret_cast< QLabel*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CWeather::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CWeather.data,
    qt_meta_data_CWeather,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CWeather::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CWeather::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CWeather.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CWeather::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
