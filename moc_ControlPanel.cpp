/****************************************************************************
** Meta object code from reading C++ file 'ControlPanel.h'
**
** Created: Sun Dec 1 22:19:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ControlPanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ControlPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      29,   13,   13,   13, 0x0a,
      47,   13,   13,   13, 0x0a,
      63,   13,   13,   13, 0x0a,
      74,   13,   13,   13, 0x0a,
      92,   13,   13,   13, 0x0a,
     109,   13,   13,   13, 0x0a,
     131,   13,   13,   13, 0x0a,
     151,   13,   13,   13, 0x0a,
     166,   13,   13,   13, 0x0a,
     188,   13,   13,   13, 0x0a,
     209,   13,   13,   13, 0x0a,
     226,   13,   13,   13, 0x0a,
     247,   13,   13,   13, 0x0a,
     263,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ControlPanel[] = {
    "ControlPanel\0\0expandPanels()\0"
    "resetBrightness()\0resetContrast()\0"
    "resetHue()\0resetSaturation()\0"
    "resetLightness()\0changeBrightness(int)\0"
    "changeContrast(int)\0changeHue(int)\0"
    "changeSaturation(int)\0changeLightness(int)\0"
    "revertOriginal()\0resetInputControls()\0"
    "resetControls()\0updateOutputImage()\0"
};

void ControlPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ControlPanel *_t = static_cast<ControlPanel *>(_o);
        switch (_id) {
        case 0: _t->expandPanels(); break;
        case 1: _t->resetBrightness(); break;
        case 2: _t->resetContrast(); break;
        case 3: _t->resetHue(); break;
        case 4: _t->resetSaturation(); break;
        case 5: _t->resetLightness(); break;
        case 6: _t->changeBrightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changeContrast((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeHue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeSaturation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->changeLightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->revertOriginal(); break;
        case 12: _t->resetInputControls(); break;
        case 13: _t->resetControls(); break;
        case 14: _t->updateOutputImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ControlPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ControlPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlPanel,
      qt_meta_data_ControlPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel))
        return static_cast<void*>(const_cast< ControlPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
