#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QSlider;
class QTreeWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
    	MainWindow();
		~MainWindow();

 	protected:
     	void contextMenuEvent(QContextMenuEvent *event);

 	private slots:
        //File Slots
     	void newFile();
     	void open();
     	void load();
    	void save();
        void saveAs();
        void savePalette();
        void loadPalette();
        void exportImage();
        void close();
        //Edit Slots
        void undo();
        void redo();
        void cut();
        void copy();
        void paste();
        void fill();
        void blend();
        void copylayer();
        void resetall();
        void cropinput();
        void cropoutput();
        //View Slots
        void zoomin();
    	void zoomout();
        void fitwindow();
    	void fullscreen();
        void togglesections();
        void showlayermanager();
        void input();
        void output();
        void palette();
        void info();
        
 	private:
    	void createActions();
    	void createMenus();
		void createToolBars();
		void createTrees(QTreeWidget *treeWidget);
		void updateActions();

    	QActionGroup *alignmentGroup;

    	QMenu *fileMenu;
    	QMenu *editMenu;
    	QMenu *viewMenu;
    	//File Actions
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

    	QLabel *infoLabel;
    	QToolBar *fileToolBar;
    	QToolBar *viewToolBar;
    	QToolBar *editToolBar;
		QPixmap image;
		QLabel *imageLabel;
		QSlider *slider;
		//QTreeWidget *treeWidget;
};

#endif
