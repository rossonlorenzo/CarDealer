/****************************************************************************
** Meta object code from reading C++ file 'resultwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "view/resultwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resultwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View__ResultsWidget_t {
    const uint offsetsAndSize[30];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_View__ResultsWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_View__ResultsWidget_t qt_meta_stringdata_View__ResultsWidget = {
    {
QT_MOC_LITERAL(0, 19), // "View::ResultsWidget"
QT_MOC_LITERAL(20, 14), // "refreshResults"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 8), // "showItem"
QT_MOC_LITERAL(45, 20), // "const products::Car*"
QT_MOC_LITERAL(66, 4), // "item"
QT_MOC_LITERAL(71, 8), // "editItem"
QT_MOC_LITERAL(80, 10), // "deleteItem"
QT_MOC_LITERAL(91, 7), // "showAll"
QT_MOC_LITERAL(99, 37), // "products::List<const products..."
QT_MOC_LITERAL(137, 5), // "items"
QT_MOC_LITERAL(143, 11), // "std::string"
QT_MOC_LITERAL(155, 4), // "type"
QT_MOC_LITERAL(160, 11), // "showResults"
QT_MOC_LITERAL(172, 5) // "query"

    },
    "View::ResultsWidget\0refreshResults\0\0"
    "showItem\0const products::Car*\0item\0"
    "editItem\0deleteItem\0showAll\0"
    "products::List<const products::Car*>&\0"
    "items\0std::string\0type\0showResults\0"
    "query"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View__ResultsWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    1,   51,    2, 0x06,    2 /* Public */,
       6,    1,   54,    2, 0x06,    4 /* Public */,
       7,    1,   57,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   60,    2, 0x0a,    8 /* Public */,
      13,    2,   65,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 9,   14,   10,

       0        // eod
};

void View::ResultsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ResultsWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refreshResults(); break;
        case 1: _t->showItem((*reinterpret_cast< std::add_pointer_t<const products::Car*>>(_a[1]))); break;
        case 2: _t->editItem((*reinterpret_cast< std::add_pointer_t<const products::Car*>>(_a[1]))); break;
        case 3: _t->deleteItem((*reinterpret_cast< std::add_pointer_t<const products::Car*>>(_a[1]))); break;
        case 4: _t->showAll((*reinterpret_cast< std::add_pointer_t<products::List<const products::Car*>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 5: _t->showResults((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<products::List<const products::Car*>&>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ResultsWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsWidget::refreshResults)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ResultsWidget::*)(const products::Car * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsWidget::showItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ResultsWidget::*)(const products::Car * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsWidget::editItem)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ResultsWidget::*)(const products::Car * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsWidget::deleteItem)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject View::ResultsWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_View__ResultsWidget.offsetsAndSize,
    qt_meta_data_View__ResultsWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_View__ResultsWidget_t
, QtPrivate::TypeAndForceComplete<ResultsWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const products::Car *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const products::Car *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const products::Car *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<products::List<const products::Car*> &, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>, QtPrivate::TypeAndForceComplete<products::List<const products::Car*> &, std::false_type>


>,
    nullptr
} };


const QMetaObject *View::ResultsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::ResultsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View__ResultsWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int View::ResultsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void View::ResultsWidget::refreshResults()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void View::ResultsWidget::showItem(const products::Car * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void View::ResultsWidget::editItem(const products::Car * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void View::ResultsWidget::deleteItem(const products::Car * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
