#ifndef MAINWINDOW_H
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
	 //Sean: Can delete
	 //----------------------------------
     void bold();
     void italic();
     void leftAlign();
     void rightAlign();
     void justify();
     void center();
     void setLineSpacing();
     void setParagraphSpacing();
     void about();
     void aboutQt();
	//Sean: End of what needs to be deleted
	//-------------------------------------

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
	 //Sean: Can delete these:
	 //----------------------------
     QAction *pasteAct;
     QAction *boldAct;
     QAction *italicAct;
     QAction *leftAlignAct;
     QAction *rightAlignAct;
     QAction *justifyAct;
     QAction *centerAct;
     QAction *setLineSpacingAct;
     QAction *setParagraphSpacingAct;
     QAction *aboutAct;
     QAction *aboutQtAct;
	 //------------------------------
     QLabel  *infoLabel;
	 QToolBar *fileToolBar;
     QToolBar *editToolBar;
 };

 #endif
