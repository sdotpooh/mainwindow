/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Nov 18 14:53:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainwindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      22,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      55,   11,   11,   11, 0x0a,
      69,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      92,   11,   11,   11, 0x0a,
     108,   11,   11,   11, 0x0a,
     117,   11,   11,   11, 0x0a,
     131,   11,   11,   11, 0x0a,
     146,   11,   11,   11, 0x0a,
     162,   11,   11,   11, 0x0a,
     178,   11,   11,   11, 0x0a,
     193,   11,   11,   11, 0x0a,
     203,   11,   11,   11, 0x0a,
     212,   11,   11,   11, 0x0a,
     225,   11,   11,   11, 0x0a,
     236,   11,   11,   11, 0x0a,
     252,   11,   11,   11, 0x0a,
     268,   11,   11,   11, 0x0a,
     289,   11,   11,   11, 0x0a,
     308,   11,   11,   11, 0x0a,
     317,   11,   11,   11, 0x0a,
     328,   11,   11,   11, 0x0a,
     340,   11,   11,   11, 0x0a,
     357,   11,   11,   11, 0x0a,
     375,   11,   11,   11, 0x0a,
     394,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mainwindow[] = {
    "mainwindow\0\0s_blend()\0s_close()\0"
    "s_copy()\0s_copylayer()\0s_cropinput()\0"
    "s_cropoutput()\0s_cut()\0s_exportImage()\0"
    "s_fill()\0s_fitwindow()\0s_fullscreen()\0"
    "s_loadPalette()\0s_loadProject()\0"
    "s_newProject()\0s_paste()\0s_redo()\0"
    "s_resetall()\0s_saveAs()\0s_savePalette()\0"
    "s_saveProject()\0s_showlayermanager()\0"
    "s_togglesections()\0s_undo()\0s_zoomin()\0"
    "s_zoomout()\0s_showInputTab()\0"
    "s_showOutputTab()\0s_showPaletteTab()\0"
    "s_showInfoTab()\0"
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mainwindow *_t = static_cast<mainwindow *>(_o);
        switch (_id) {
        case 0: _t->s_blend(); break;
        case 1: _t->s_close(); break;
        case 2: _t->s_copy(); break;
        case 3: _t->s_copylayer(); break;
        case 4: _t->s_cropinput(); break;
        case 5: _t->s_cropoutput(); break;
        case 6: _t->s_cut(); break;
        case 7: _t->s_exportImage(); break;
        case 8: _t->s_fill(); break;
        case 9: _t->s_fitwindow(); break;
        case 10: _t->s_fullscreen(); break;
        case 11: _t->s_loadPalette(); break;
        case 12: _t->s_loadProject(); break;
        case 13: _t->s_newProject(); break;
        case 14: _t->s_paste(); break;
        case 15: _t->s_redo(); break;
        case 16: _t->s_resetall(); break;
        case 17: _t->s_saveAs(); break;
        case 18: _t->s_savePalette(); break;
        case 19: _t->s_saveProject(); break;
        case 20: _t->s_showlayermanager(); break;
        case 21: _t->s_togglesections(); break;
        case 22: _t->s_undo(); break;
        case 23: _t->s_zoomin(); break;
        case 24: _t->s_zoomout(); break;
        case 25: _t->s_showInputTab(); break;
        case 26: _t->s_showOutputTab(); break;
        case 27: _t->s_showPaletteTab(); break;
        case 28: _t->s_showInfoTab(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData mainwindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mainwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainwindow,
      qt_meta_data_mainwindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainwindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow))
        return static_cast<void*>(const_cast< mainwindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
