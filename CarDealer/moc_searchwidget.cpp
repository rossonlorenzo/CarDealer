/****************************************************************************
** Meta object code from reading C++ file 'searchwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "view/searchwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View__SearchWidget_t {
    const uint offsetsAndSize[18];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_View__SearchWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_View__SearchWidget_t qt_meta_stringdata_View__SearchWidget = {
    {
QT_MOC_LITERAL(0, 18), // "View::SearchWidget"
QT_MOC_LITERAL(19, 12), // "search_event"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 5), // "query"
QT_MOC_LITERAL(39, 12), // "filter_event"
QT_MOC_LITERAL(52, 11), // "std::string"
QT_MOC_LITERAL(64, 4), // "type"
QT_MOC_LITERAL(69, 6), // "search"
QT_MOC_LITERAL(76, 6) // "filter"

    },
    "View::SearchWidget\0search_event\0\0query\0"
    "filter_event\0std::string\0type\0search\0"
    "filter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View__SearchWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    1,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   44,    2, 0x0a,    5 /* Public */,
       8,    0,   45,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void View::SearchWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->search_event((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 1: _t->filter_event((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 2: _t->search(); break;
        case 3: _t->filter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchWidget::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchWidget::search_event)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SearchWidget::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchWidget::filter_event)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject View::SearchWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_View__SearchWidget.offsetsAndSize,
    qt_meta_data_View__SearchWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_View__SearchWidget_t
, QtPrivate::TypeAndForceComplete<SearchWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *View::SearchWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::SearchWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View__SearchWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int View::SearchWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void View::SearchWidget::search_event(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void View::SearchWidget::filter_event(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
