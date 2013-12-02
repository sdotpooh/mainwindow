// Group Members: Sean Vinas, Enmanuel Almanzar, Daniel Sodkiewicz
// Mosaic Tile Software Project
// CSC221 Section R: Software Design Lab
// Professor Wolberg
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QtGui>
#include <QWidget>
#include <QPainter>
#include "ControlPanel.h"
#include "ImageWindow.h"
#include "TesseraParameters.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

    TesseraParameters&	parameters		();
    void			    updateInputFrame();

    ~MainWindow();
	friend class Tree;

private slots:
    void s_newProject		();
    void s_loadProject		();
    void s_saveProject		();
    void s_undo				();
    void s_redo				();
    void s_zoomIn			();
    void s_zoomOut			();
	void s_sliderZoom 		(int);
    void s_showInputTab		();
    void s_showOutputTab	();
    void s_showPaletteTab	();
    void s_showInfoTab		();

private:
    void createActions 		();
    void createMenus 		();
	void createMenuFile 	();
	void createMenuEdit 	();
	void createMenuView 	();
	void createMenuTool 	();
    void createCentralWidget();
    void createToolBars 	();
    void createFileToolBar 	();
	void createViewToolBar   ();
	void createEditToolBar 	();

	QHBoxLayout *mainLayout;
    ImageWindow	*m_frameInput;
	ControlPanel*m_controlPanel;

    QMenuBar 	*mainMenu;
	QMenu  		*fileMenu;
    QMenu 		*editMenu;
    QMenu 		*viewMenu;
    QMenu 		*toolsMenu;

    QToolBar 	*fileToolBar;
	QToolBar 	*viewToolBar;
    QToolBar 	*editToolBar;

    QTabWidget  *windowTabs;
	QTabWidget	*m_tabPreview;

    QWidget     *centralWindow;
    QWidget     *outputTab;
    QWidget     *paletteTab;
    QWidget     *infoTab;
	QWidget     *m_frameOutput;
    QWidget     *m_framePalette;
    QWidget     *m_frameInfo;
    
    QAction 	*a_blendTool;
	QAction 	*a_bucketFill;
	QAction 	*a_byColorSelect;
	QAction 	*a_colorPicker;
	QAction 	*a_colorSelection;
	QAction 	*a_copy;
	QAction 	*a_copyCurrentLayer;
	QAction 	*a_cropInput;
    QAction 	*a_cropOutput;
	QAction 	*a_cut;
	QAction 	*a_eraser;
	QAction 	*a_exportPalette;
	QAction 	*a_fillSelection;
	QAction 	*a_fitWindow;
    QAction 	*a_fullscreen;
	QAction 	*a_fuzzySelect;
	QAction 	*a_info;
	QAction 	*a_input;
	QAction 	*a_load;
    QAction 	*a_loadPalette;
	QAction 	*a_new;
	QAction 	*a_none;
    QAction 	*a_open;
	QAction 	*a_output;
	QAction 	*a_palette;
	QAction 	*a_paste;
	QAction 	*a_pencil;
	QAction 	*a_quit;
	QAction 	*a_rectSelect;
    QAction 	*a_redo;
	QAction 	*a_resetAll;
	QAction 	*a_saveAsProject;
	QAction 	*a_savePalette;
	QAction 	*a_saveProject;
	QAction 	*a_showLayerManager;
	QAction 	*a_slider;
	QAction 	*a_toggleSections;
    QAction 	*a_undo;
    QAction 	*a_zoomIn;
    QAction 	*a_zoomOut;

    QSlider 	*slider;
    QLabel 		*sliderLabel;

    QString     m_currentInDir;

	QPushButton *fullScreenButton;
	QPushButton *fitWindowButton;

    TesseraParameters m_params;
};

#endif // MAINWINDOW_H



