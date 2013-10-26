 #ifndef  MAINWINDOW_H 
 #define MAINWINDOW_H

 #include <QMainWindow>

 class QAction;
 class QActionGroup;
 class QLabel;
 class QMenu;

 class MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     MainWindow();

 protected:
     void contextMenuEvent(QContextMenuEvent *event);

 private slots:
	 //File Slots
     void newFile();
     void open();
     void load();
     void save();
<<<<<<< HEAD
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
	 
=======
     void print();
     void undo();
     void redo();
     void cut();
     void copy();
     void paste();
	 

>>>>>>> 8ac407f79f0f5f4c2189ac8119662efa7d6c931d
 private:
     void createActions();
     void createMenus();
	 void createToolBars();

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
<<<<<<< HEAD
	 QAction *fitwindowAct;
	 QAction *fullscreenAct;
	 QAction *togglesectionsAct;
	 QAction *showlayermanagerAct;
	 QAction *inputAct;
	 QAction *outputAct;
	 QAction *paletteAct;
	 QAction *infoAct;

     QLabel  *infoLabel;
=======
	 QAction *pasteAct;
	 //QAction *layerAct;
	 QLabel  *infoLabel;
>>>>>>> 8ac407f79f0f5f4c2189ac8119662efa7d6c931d
	 QToolBar *fileToolBar;
	 QToolBar *viewToolBar;
     QToolBar *editToolBar;
 };

 #endif
