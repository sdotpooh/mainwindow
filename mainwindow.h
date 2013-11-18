#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QWidget>
#include "TesseraParameters.h"
#include "ControlPanel.h"
#include "ImageWindow.h"

class mainwindow : public QMainWindow {
	Q_OBJECT

public:
	mainwindow();

	TesseraParameters&	parameters		();
	void			updateInputFrame	();

	~mainwindow();

public slots:
	void s_blend 			();
	void s_close 			();
	void s_copy 			();
	void s_copylayer 		();
	void s_cropinput 		();
	void s_cropoutput 		();
	void s_cut 				();
	void s_exportImage 		();
	void s_fill 			();
	void s_fitwindow 		();
	void s_fullscreen 		();
	void s_loadPalette 		();
	void s_loadProject		();
	void s_newProject		();
	void s_paste 			();
	void s_redo				();
	void s_resetall 		();
	void s_saveAs 			();
	void s_savePalette 		();
	void s_saveProject		();
	void s_showlayermanager ();
	void s_togglesections   ();
	void s_undo				();	
	void s_zoomin			();
	void s_zoomout			();

	void s_showInputTab		();
	void s_showOutputTab	();
	void s_showPaletteTab	();
	void s_showInfoTab		();

private:
	void	createWidgets		();
	void	createActions		();
	void	createActionsFile	();
	void	createActionsEdit	();
	void	createActionsView	();
	void	createMenus			();
	void	createMenuFile		();
	void	createMenuEdit		();
	void	createMenuView		();
	void 	createToolBars 		();
	void 	createToolBarFile 	();
	void 	createToolBarEdit 	();
	void 	createToolBarView 	();
	
	QMenu   *fileMenu;
    QMenu   *editMenu;
    QMenu   *viewMenu;

	QAction *newAct;
    QAction *openAct;
    QAction *loadAct;
    QAction *saveAct;
 	QAction *saveasAct;
    QAction *printAct;
    QAction *savepaletteAct;
    QAction *loadpaletteAct;
    QAction *exportAct;
    QAction *exitAct;
	//Edit Actions
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *fillselectionAct;
	QAction *blendtoolAct;
	QAction *copycurrlayerAct;
	QAction *resetallAct;
	QAction *cropinputAct;
    QAction *cropoutputAct;
	//View Actions
    QAction *zoominAct;
    QAction *zoomoutAct;
    QAction *fitwindowAct;
    QAction *fullscreenAct;
    QAction *togglesectionsAct;
    QAction *showlayermanagerAct;
    QAction *inputAct;
    QAction *outputAct;
    QAction *paletteAct;
	QAction *infoAct;
	//Toolbar actions
	QAction *pencilAct;
	QAction *eraserAct;
	QAction *fuzzyselectAct;
	QAction *colorselectAct;
	QAction *bucketfillAct;
	QAction *colorpickerAct;
	QAction *rectselectAct;
	QAction *noneAct;

	QToolBar*fileToolBar;
    QToolBar*viewToolBar;
    QToolBar*editToolBar;

	QHBoxLayout     *imageLayout;
    QTabWidget      *tabWidget;
    QWidget         *centralWindow;
    QWidget         *inputTab;
    QWidget         *outputTab;
    QWidget         *paletteTab;
    QWidget         *infoTab;
    ControlPanel    *controlPanel;	
	
	ImageWindow		*m_frameInput;
	QWidget			*m_frameOutput;
	QWidget			*m_framePalette;
	QWidget			*m_frameInfo;
	ControlPanel	*m_controlPanel;
	QTabWidget		*m_tabPreview;

	QString		  	m_currentInDir;
	TesseraParameters m_params;
};

#endif // MAINWINDOW_H

