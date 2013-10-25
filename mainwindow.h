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
     void newFile();
     void open();
     void save();
     void print();
     void undo();
     void redo();
     void cut();
     void copy();
     void paste();
	 

 private:
     void createActions();
     void createMenus();
	 void createToolBars();

     QMenu *fileMenu;
     QMenu *editMenu;
     QMenu *formatMenu;
     QMenu *helpMenu;
     QActionGroup *alignmentGroup;
     QAction *newAct;
     QAction *openAct;
     QAction *saveAct;
     QAction *printAct;
     QAction *exitAct;
     QAction *undoAct;
     QAction *redoAct;
     QAction *zoominAct;
     QAction *zoomoutAct;
	 QAction *pasteAct;
	 //QAction *layerAct;
	 QLabel  *infoLabel;
	 QToolBar *fileToolBar;
     QToolBar *editToolBar;
 };

 #endif
