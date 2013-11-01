/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Nov 1 18:31:49 2013
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
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      22,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      43,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      80,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     109,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     209,   11,   11,   11, 0x08,
     219,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     261,   11,   11,   11, 0x08,
     280,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,
     307,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newFile()\0open()\0load()\0"
    "save()\0saveAs()\0savePalette()\0"
    "loadPalette()\0exportImage()\0close()\0"
    "undo()\0redo()\0cut()\0copy()\0paste()\0"
    "fill()\0blend()\0copylayer()\0resetall()\0"
    "cropinput()\0cropoutput()\0zoomin()\0"
    "zoomout()\0fitwindow()\0fullscreen()\0"
    "togglesections()\0showlayermanager()\0"
    "input()\0output()\0palette()\0info()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->open(); break;
        case 2: _t->load(); break;
        case 3: _t->save(); break;
        case 4: _t->saveAs(); break;
        case 5: _t->savePalette(); break;
        case 6: _t->loadPalette(); break;
        case 7: _t->exportImage(); break;
        case 8: _t->close(); break;
        case 9: _t->undo(); break;
        case 10: _t->redo(); break;
        case 11: _t->cut(); break;
        case 12: _t->copy(); break;
        case 13: _t->paste(); break;
        case 14: _t->fill(); break;
        case 15: _t->blend(); break;
        case 16: _t->copylayer(); break;
        case 17: _t->resetall(); break;
        case 18: _t->cropinput(); break;
        case 19: _t->cropoutput(); break;
        case 20: _t->zoomin(); break;
        case 21: _t->zoomout(); break;
        case 22: _t->fitwindow(); break;
        case 23: _t->fullscreen(); break;
        case 24: _t->togglesections(); break;
        case 25: _t->showlayermanager(); break;
        case 26: _t->input(); break;
        case 27: _t->output(); break;
        case 28: _t->palette(); break;
        case 29: _t->info(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
