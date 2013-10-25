#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow()
{
 	QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	//new part
	QTabWidget  *tabWidget = new QTabWidget;
	QVBoxLayout *lay = new QVBoxLayout;
	QHBoxLayout *hlay = new QHBoxLayout;
	hlay->addStretch();
	hlay-> addWidget(new QPushButton("Full Screen"));
	hlay-> addWidget(new QPushButton("Fit Window"));
	lay -> addStretch();
	lay -> addLayout(hlay);
	QTabWidget *blah = new QTabWidget;
	blah->setLayout(lay);

	tabWidget->addTab(blah, "hello");
	tabWidget->addTab(new QTabWidget(), "Input");
	tabWidget->addTab(new QTabWidget(), "Output");
	tabWidget->addTab(new QTabWidget(), "Palette");
	tabWidget->addTab(new QTabWidget(), "Info");


    QTreeWidget *treeWidget = new QTreeWidget;
	treeWidget->header()->hide();

    QTreeWidgetItem *tree_Item_One = new QTreeWidgetItem(treeWidget);
    tree_Item_One->setText(0, tr("Input Settings"));

	QTreeWidgetItem *item_one = new QTreeWidgetItem(tree_Item_One);
	item_one->setText(0,"Settings Go Here");
	treeWidget->insertTopLevelItem(0,item_one);

	//QTreeWidgetItem *tree_Item_One_Widget = new QTreeWidgetItem(tree_Item_One);
	//tree_Item_One_Widget->setText(0, tr("Input Settings Widget Inside"));

	QTreeWidgetItem *tree_Item_Two = new QTreeWidgetItem(treeWidget);
    tree_Item_Two->setText(0, tr("Mosaic Rendering"));

	QTreeWidgetItem *item_two = new QTreeWidgetItem(tree_Item_Two);
	item_two->setText(0,"Mosaic Rendering Go Here");
	treeWidget->insertTopLevelItem(0,item_two);

    QTreeWidgetItem *tree_Item_Three = new QTreeWidgetItem(treeWidget);
    tree_Item_Three->setText(0, tr("Mosaic Size"));

	QTreeWidgetItem *item_three = new QTreeWidgetItem(tree_Item_Three);
	item_three->setText(0,"Mosaic Size Go Here");
	treeWidget->insertTopLevelItem(0,item_three);

	QTreeWidgetItem *tree_Item_Four = new QTreeWidgetItem(treeWidget);
    tree_Item_Four->setText(0, tr("Title Palette"));
	   
	QTreeWidgetItem *item_four = new QTreeWidgetItem(tree_Item_Four);
	item_four->setText(0,"Title Palette Go Here");
	treeWidget->insertTopLevelItem(0,item_four);


	QTreeWidgetItem *tree_Item_Five = new QTreeWidgetItem(treeWidget);
    tree_Item_Five->setText(0, tr("Grout"));

	QTreeWidgetItem *item_five = new QTreeWidgetItem(tree_Item_Five);
	item_five->setText(0,"Grout Go Here");
	treeWidget->insertTopLevelItem(0,item_five);

	//QTreeWidgetItem *tree_Item_Two = new QTreeWidgetItem(tree_Item_Two);
	//tree_Item_Two->setText(0, tr("Input Setting s2"));
	    
    //set_a->setText(0, tr("Input Settings"));
	//set_b->setText(0, tr("Input Settings2"));
	// layout

	QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(5);
	layout->addWidget(tabWidget);
	layout->addWidget(treeWidget);

	widget->setLayout(layout);

	
	createActions();
    createMenus();
	createToolBars();

    setWindowTitle(tr("Tessera Grid V1.0"));
    setMinimumSize(160, 160);
    resize(980, 620);
}

void 
MainWindow::contextMenuEvent(QContextMenuEvent *event)
 {
     QMenu menu(this);
     menu.addAction(zoominAct);
     menu.addAction(zoomoutAct);
     menu.addAction(pasteAct);
     menu.exec(event->globalPos());
 }

 void MainWindow::newFile()
 {
     infoLabel->setText(tr("Invoked <b>File|New</b>"));
 }

 void MainWindow::open()
 {
     infoLabel->setText(tr("Invoked <b>File|Open</b>"));
 }

 void MainWindow::save()
 {
     infoLabel->setText(tr("Invoked <b>File|Save</b>"));
 }

 void MainWindow::print()
 {
     infoLabel->setText(tr("Invoked <b>File|Print</b>"));
 }

 void MainWindow::undo()
 {
     infoLabel->setText(tr("Invoked <b>Edit|Undo</b>"));
 }

 void MainWindow::redo()
 {
     infoLabel->setText(tr("Invoked <b>Edit|Redo</b>"));
 }

 void MainWindow::cut()
 {
     
 }

 void MainWindow::copy()
 {
	
 }

 void MainWindow::paste()
 {
     infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
 }

 

void MainWindow::createActions()
{
    newAct = new QAction(QIcon("icons/file-new.png"),tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon("icons/file-load.png"),tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon("icons/file-save.png"),tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the document"));
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

    zoominAct = new QAction(QIcon("icons/view-zoomin.png"),tr("Zoom&Out"), this);
    zoominAct->setShortcuts(QKeySequence::Cut);
    zoominAct->setStatusTip(tr("Cut the current selection's contents to the "
                             "clipboard"));
    connect(zoominAct, SIGNAL(triggered()), this, SLOT(cut()));

    zoomoutAct = new QAction(QIcon("icons/view-zoomout.png"),tr("Zoom&In"), this);
    zoomoutAct->setShortcuts(QKeySequence::Copy);
    zoomoutAct->setStatusTip(tr("Copy the current selection's contents to the "
                              "clipboard"));
    connect(zoomoutAct, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                               "selection"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

	/*layerAct = new QAction(QIcon("icons/view-layer-manager.png"),tr("&Layer"), this);
    layerAct->setShortcuts(QKeySequence::Layer);
    layerAct->setStatusTip(tr("View Layer Manager"));
    connect(layerAct, SIGNAL(triggered()), this, SLOT(layer()));*/
}

 void MainWindow::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&File"));
     fileMenu->addAction(newAct);
     fileMenu->addAction(openAct);
     fileMenu->addAction(saveAct);
     fileMenu->addAction(printAct);
     fileMenu->addSeparator();
     fileMenu->addAction(exitAct);

     editMenu = menuBar()->addMenu(tr("&Edit"));
     editMenu->addAction(undoAct);
     editMenu->addAction(redoAct);
     editMenu->addSeparator();
     editMenu->addAction(zoominAct);
     editMenu->addAction(zoomoutAct);
     editMenu->addAction(pasteAct);
	 //editMenu->addAction(layerAct);
     editMenu->addSeparator();

 }
 void 
 MainWindow::createToolBars()
 {
     fileToolBar = addToolBar(tr("File"));
     fileToolBar->addAction(newAct);
     fileToolBar->addAction(openAct);
     fileToolBar->addAction(saveAct);

     editToolBar = addToolBar(tr("Edit"));
     editToolBar->addAction(zoominAct);
     editToolBar->addAction(zoomoutAct);
 }



