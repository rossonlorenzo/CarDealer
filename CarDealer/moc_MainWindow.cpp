/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "view/MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View__MainWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_View__MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_View__MainWindow_t qt_meta_stringdata_View__MainWindow = {
    {
QT_MOC_LITERAL(0, 16), // "View::MainWindow"
QT_MOC_LITERAL(17, 10), // "newDataset"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 11), // "openDataset"
QT_MOC_LITERAL(41, 11), // "saveDataset"
QT_MOC_LITERAL(53, 13), // "toggleToolbar"
QT_MOC_LITERAL(67, 10), // "showStatus"
QT_MOC_LITERAL(78, 7), // "message"
QT_MOC_LITERAL(86, 6), // "deploy"
QT_MOC_LITERAL(93, 6), // "filter"
QT_MOC_LITERAL(100, 11), // "std::string"
QT_MOC_LITERAL(112, 4), // "type"
QT_MOC_LITERAL(117, 6), // "search"
QT_MOC_LITERAL(124, 5), // "query"
QT_MOC_LITERAL(130, 10), // "createItem"
QT_MOC_LITERAL(141, 8), // "showItem"
QT_MOC_LITERAL(150, 20), // "const products::Car*"
QT_MOC_LITERAL(171, 4), // "item"
QT_MOC_LITERAL(176, 8), // "editItem"
QT_MOC_LITERAL(185, 10), // "deleteItem"
QT_MOC_LITERAL(196, 5) // "close"

    },
    "View::MainWindow\0newDataset\0\0openDataset\0"
    "saveDataset\0toggleToolbar\0showStatus\0"
    "message\0deploy\0filter\0std::string\0"
    "type\0search\0query\0createItem\0showItem\0"
    "const products::Car*\0item\0editItem\0"
    "deleteItem\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View__MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x0a,    1 /* Public */,
       3,    0,   93,    2, 0x0a,    2 /* Public */,
       4,    0,   94,    2, 0x0a,    3 /* Public */,
       5,    0,   95,    2, 0x0a,    4 /* Public */,
       6,    1,   96,    2, 0x0a,    5 /* Public */,
       8,    0,   99,    2, 0x0a,    7 /* Public */,
       9,    1,  100,    2, 0x0a,    8 /* Public */,
      12,    1,  103,    2, 0x0a,   10 /* Public */,
      14,    0,  106,    2, 0x0a,   12 /* Public */,
      15,    1,  107,    2, 0x0a,   13 /* Public */,
      18,    1,  110,    2, 0x0a,   15 /* Public */,
      19,    1,  113,    2, 0x0a,   17 /* Public */,
      20,    0,  116,    2, 0x0a,   19 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::UInt,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,

       0        // eod
};

void View::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newDataset(); break;
        case 1: _t->openDataset(); break;
        case 2: _t->saveDataset(); break;
        case 3: _t->toggleToolbar(); break;
        case 4: _t->showStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->deploy(); break;
        case 6: _t->filter((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 7: _t->search((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 8: _t->createItem(); break;
        case 9: _t->showItem((*reinterpret_cast< std::add_pointer_t<const products::Car*>>(_a[1]))); break;
        case 10: _t->editItem((*reinterpret_cast< std::add_pointer_t<const products::Car*>>(_a[1]))); break;
        case 11: _t->deleteItem((*reinterpret_cast< std::add_pointer_t<const products::Car*>>(_a[1]))); break;
        case 12: _t->close(); break;
        default: ;
        }
    }
}

const QMetaObject View::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_View__MainWindow.offsetsAndSize,
    qt_meta_data_View__MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_View__MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const products::Car *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const products::Car *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const products::Car *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *View::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
