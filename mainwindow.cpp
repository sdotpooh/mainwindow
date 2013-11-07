// Sean Vinas, Enmanuel Almanzar, and Daniel Sodkiewicz Mosaic software 

#include <QtGui>
#include<QString>
#include<QFile>
#include<QImage>
#include<QPixmap>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	//Begin Tree Widgets
    QTreeWidget *treeWidget = new QTreeWidget;
    treeWidget->header()->hide();

    QTreeWidgetItem *tree_Item_One = new QTreeWidgetItem(treeWidget);
    tree_Item_One->setText(0, tr("Input Settings"));

    QTreeWidgetItem *item_one = new QTreeWidgetItem(tree_Item_One);
    item_one->setText(0,"Settings Go Here");
    treeWidget->insertTopLevelItem(0,item_one);
    
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

   
	QTabWidget *tabWidget = new QTabWidget;  
	QTabWidget *inputTabWidget = new QTabWidget;

	QVBoxLayout *imageLayout = new QVBoxLayout;
	image = QPixmap("starrynight.png");
	QLabel *imageLabel = new QLabel();
	imageLabel->setPixmap(image);
	imageLayout->addWidget(imageLabel);
	
	QHBoxLayout *tabButtonslayout = new QHBoxLayout;
	tabButtonslayout->addWidget(new QPushButton("Full Screen"));
	tabButtonslayout->addWidget(new QPushButton("Fit Window"));
	tabButtonslayout->addWidget(new QSlider(Qt::Horizontal));
	
	QVBoxLayout *inTabLayout = new QVBoxLayout;
	inTabLayout->addLayout(imageLayout);
	inTabLayout->addLayout(tabButtonslayout);	
	inputTabWidget->setLayout(inTabLayout);

	tabWidget->addTab(inputTabWidget, "Input");
    tabWidget->addTab(new QTabWidget(), "Output");
    tabWidget->addTab(new QTabWidget(), "Palette");
    tabWidget->addTab(new QTabWidget(), "Info");

    QHBoxLayout *layout 		  = new QHBoxLayout;
	QVBoxLayout *tabLayout 		  = new QVBoxLayout;
	
    tabLayout->addWidget(tabWidget);
	layout->addLayout(tabLayout);
    layout->addWidget(treeWidget);

    widget->setLayout(layout);

    createActions();
    createMenus();
    createToolBars();

    setWindowTitle(tr("Tessera Grid V1.0"));
    setMinimumSize(160, 160);
    resize(980, 620);
}

MainWindow::~MainWindow()
{
	//save setting and image output
	//This is the destructor, add this functionality when appropriate
}

void
MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(zoominAct);
    menu.addAction(zoomoutAct);
    //menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}

void
MainWindow::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void
MainWindow::open()
{
    //infoLabel->setText(tr("Invoked <b>File|Open</b>"));
	QString fileName = QFileDialog::getOpenFileName(this,
			tr("Open File"),QDir::currentPath());
	if(!fileName.isEmpty())
	 {
		QImage image(fileName);
		if(image.isNull())
		{
             QMessageBox::information(this, tr("Image Viewer"),
                                      tr("Cannot load %1.").arg(fileName));
             return;
        }
	 }
}


void
MainWindow::load()
{
    infoLabel->setText(tr("Invoked <b>File|Load</b>"));
}

void
MainWindow::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void
MainWindow::saveAs()
{
    infoLabel->setText(tr("Invoked <b>File|Save As</b>"));
}

void
MainWindow::savePalette()
{
   infoLabel->setText(tr("Invoked <b>File|Save Palette</b>"));
}

void
MainWindow::loadPalette()
{
   infoLabel->setText(tr("Invoked <b>File|Load Palette</b>"));
}

void
MainWindow::exportImage()
{
    infoLabel->setText(tr("Invoked <b>File|Export Image</b>"));
}

void
MainWindow::close()
{
    infoLabel->setText(tr("Invoked <b>File|Close</b>"));
}

void
MainWindow::undo()
{
    infoLabel->setText(tr("Invoked <b>Edit|Undo</b>"));
}

void
MainWindow::redo()
{
    infoLabel->setText(tr("Invoked <b>Edit|Redo</b>"));
}

void
MainWindow::cut()
{
    infoLabel->setText(tr("Invoked <b>Edit|Cut</b>"));
}

void
MainWindow::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void
MainWindow::paste()
{
    infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}

void
MainWindow::fill()
{
    infoLabel->setText(tr("Invoked <b>Edit|Fill</b>"));
}

void
MainWindow::blend()
{
    infoLabel->setText(tr("Invoked <b>Edit|Blend</b>"));
}

void
MainWindow::copylayer()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy Layer</b>"));
}

void
MainWindow::resetall()
{
    infoLabel->setText(tr("Invoked <b>Edit|Reset All</b>"));
}

void
MainWindow::cropinput()
{
    infoLabel->setText(tr("Invoked <b>Edit|Crop Input</b>"));
}

void
MainWindow::cropoutput()
{
    infoLabel->setText(tr("Invoked <b>Edit|Crop Output</b>"));
}

void
MainWindow::zoomin()
{
    infoLabel->setText(tr("Invoked <b>View|Zoom In</b>"));
}

void
MainWindow::zoomout()
{
    infoLabel->setText(tr("Invoked <b>View|Zoom Out</b>"));
}

void
MainWindow::fitwindow()
{
	infoLabel->setText(tr("Invoked <b>View|Fit Window</b>"));
}

void
MainWindow::fullscreen()
{
    infoLabel->setText(tr("Invoked <b>View|Full Screen</b>"));
}

void
MainWindow::togglesections()
{
    infoLabel->setText(tr("Invoked <b>View|Toggle Sections</b>"));
}

void
MainWindow::showlayermanager()
{
    infoLabel->setText(tr("Invoked <b>View|Show Layer Manager</b>"));
}

void
MainWindow::input()
{
    infoLabel->setText(tr("Invoked <b>View|Input</b>"));
}

void
MainWindow::output()
{
    infoLabel->setText(tr("Invoked <b>View|Output</b>"));
}

void
MainWindow::palette()
{
    infoLabel->setText(tr("Invoked <b>View|Palette</b>"));
}

void
MainWindow::info()
{
    infoLabel->setText(tr("Invoked <b>View|Info</b>"));
}
void MainWindow::createActions()
{
    //File Actions
    newAct = new QAction(QIcon("icons/file-new.png"),tr("&New"), this);
    newAct->setShortcut(QKeySequence(tr("Ctrl+N")));
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon("icons/file-load.png"),tr("&Open"), this);
    openAct->setShortcut(QKeySequence(tr("Ctrl+O")));
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    loadAct = new QAction(tr("&Load..."), this);
    loadAct->setShortcut(QKeySequence(tr("Ctrl+L")));
    loadAct->setStatusTip(tr("Load image"));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(load()));

    saveAct = new QAction(QIcon("icons/file-save.png"),tr("&Save"), this);
    saveAct->setShortcut(QKeySequence(tr("Ctrl+S")));
    saveAct->setStatusTip(tr("Save the image"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveasAct = new QAction(tr("&Save As..."), this);
    saveasAct->setShortcut(QKeySequence(tr("Ctrl+Shift+S")));
    saveasAct->setStatusTip(tr("Save As the image"));
    connect(saveasAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    savepaletteAct = new QAction(tr("&Save palette..."), this);
    savepaletteAct->setShortcut(QKeySequence(tr("Ctrl+P")));
    savepaletteAct->setStatusTip(tr("Save the palette"));
    connect(savepaletteAct, SIGNAL(triggered()), this, SLOT(savePalette()));

    loadpaletteAct = new QAction(tr("&Load palette..."), this);
    loadpaletteAct->setShortcut(QKeySequence(tr("Ctrl+G")));
    loadpaletteAct->setStatusTip(tr("Load the palette"));
    connect(loadpaletteAct, SIGNAL(triggered()), this, SLOT(loadPalette()));

    exportAct = new QAction(tr("&Export..."), this);
    exportAct->setShortcut(QKeySequence(tr("Ctrl+E")));
    exportAct->setStatusTip(tr("Export"));
    connect(exportAct, SIGNAL(triggered()), this, SLOT(exportImage()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(QKeySequence(tr("Ctrl+Q")));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    //Edit Actions
    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcut(QKeySequence(tr("Ctrl+Z")));
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcut(QKeySequence(tr("Ctrl+Y")));
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

    cutAct = new QAction(tr("&Cut"), this);
    cutAct->setShortcut(QKeySequence(tr("Ctrl+X")));
    cutAct->setStatusTip(tr("Cut"));
    connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcut(QKeySequence(tr("Ctrl+C")));
    copyAct->setStatusTip(tr("Copy"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcut(QKeySequence(tr("Ctrl+V")));
    pasteAct->setStatusTip(tr("Paste"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

    fillselectionAct = new QAction(QIcon("icons/tool-bucket-fill-22.png"),
                                   tr("&Fill"), this);
    fillselectionAct->setShortcut(QKeySequence(tr("Ctrl+I")));
    fillselectionAct->setStatusTip(tr("Fill selection"));
    connect(fillselectionAct, SIGNAL(triggered()), this, SLOT(fill()));

    blendtoolAct = new QAction(tr("&Blend"), this);
    blendtoolAct->setShortcut(QKeySequence(tr("Ctrl+D")));
    blendtoolAct->setStatusTip(tr("Blend tool"));
    connect(blendtoolAct, SIGNAL(triggered()), this, SLOT(blend()));

    copycurrlayerAct = new QAction(tr("&Copy Layer"), this);
    copycurrlayerAct->setShortcut(QKeySequence(tr("Ctrl+Shift+C")));
    copycurrlayerAct->setStatusTip(tr("Copy Current Layer"));
    connect(copycurrlayerAct, SIGNAL(triggered()), this, SLOT(copylayer()));

    resetallAct = new QAction(tr("&Reset All"), this);
    resetallAct->setShortcut(QKeySequence(tr("Ctrl+A")));
    resetallAct->setStatusTip(tr("Reset All"));
    connect(resetallAct, SIGNAL(triggered()), this, SLOT(resetall()));

    cropinputAct = new QAction(tr("&Crop Input"), this);
    cropinputAct->setShortcut(QKeySequence(tr("Ctrl+R")));
    cropinputAct->setStatusTip(tr("Crop Input"));
    connect(cropinputAct, SIGNAL(triggered()), this, SLOT(cropinput()));

    cropoutputAct = new QAction(tr("&Crop Output"), this);
    cropoutputAct->setShortcut(QKeySequence(tr("Ctrl+T")));
    cropoutputAct->setStatusTip(tr("Crop Output"));
    connect(cropoutputAct, SIGNAL(triggered()), this, SLOT(cropoutput()));

    //View Actions
    zoominAct = new QAction(QIcon("icons/view-zoomin.png"),tr("&Zoom In"), this);
    zoominAct->setShortcut(QKeySequence(tr("Ctrl+Shift+V")));
    zoominAct->setStatusTip(tr("Zoom in"));
    connect(zoominAct, SIGNAL(triggered()), this, SLOT(zoomin()));

    zoomoutAct = new QAction(QIcon("icons/view-zoomout.png"),tr("&Zoom Out"), this);
    zoomoutAct->setShortcut(QKeySequence(tr("Ctrl+Shift+U")));
    zoomoutAct->setStatusTip(tr("Zoom out"));
    connect(zoomoutAct, SIGNAL(triggered()), this, SLOT(zoomout()));

    fitwindowAct = new QAction(tr("&Fit Window"), this);
    fitwindowAct->setShortcut(QKeySequence(tr("Ctrl+W")));
    fitwindowAct->setStatusTip(tr("Fit window"));
    connect(fitwindowAct, SIGNAL(triggered()), this, SLOT(fitwindow()));

    fullscreenAct = new QAction(tr("&Full Screen"), this);
    fullscreenAct->setShortcut(QKeySequence(tr("Ctrl+F")));
    fullscreenAct->setStatusTip(tr("Full screen"));
    connect(fullscreenAct, SIGNAL(triggered()), this, SLOT(fullscreen()));

    togglesectionsAct = new QAction(tr("&Toggle Sections"), this);
    togglesectionsAct->setShortcut(QKeySequence(tr("Ctrl+B")));
    togglesectionsAct->setStatusTip(tr("Toggle sections"));
    connect(togglesectionsAct, SIGNAL(triggered()), this, SLOT(togglesections()));

    showlayermanagerAct = new QAction(QIcon("icons/view-layer-manager.png"),
                                      tr("&Show Layer Manager"), this);
    showlayermanagerAct->setShortcut(QKeySequence(tr("Ctrl+M")));
    showlayermanagerAct->setStatusTip(tr("Show layer manager"));
    connect(showlayermanagerAct, SIGNAL(triggered()), this, SLOT(showlayermanager()));

    showlayermanagerAct = new QAction(QIcon("icons/view-layer-manager.png"),
                                      tr("&Show Layer Manager"), this);
    showlayermanagerAct->setShortcut(QKeySequence(tr("Ctrl+M")));
    showlayermanagerAct->setStatusTip(tr("Show layer manager"));
    connect(showlayermanagerAct, SIGNAL(triggered()), this, SLOT(showlayermanager()));
	
	pencilAct = new QAction(QIcon("icons/tool-pencil-22.png"),
                                      tr("&Pencil Tool"), this);

	eraserAct = new QAction(QIcon("icons/tool-eraser-22.png"),
                                      tr("&Eraser Tool"), this);
	
	fuzzyselectAct = new QAction(QIcon("icons/tool-fuzzy-select-22.png"),
                                      tr("&Fuzzy Tool"), this);
	
	colorselectAct = new QAction(QIcon("icons/tool-by-color-select-22.png"),
                                      tr("&By Color Select"), this);

	bucketfillAct = new QAction(QIcon("icons/tool-bucket-fill-22.png"),
                                      tr("&Bucket Fill"), this);

	colorpickerAct = new QAction(QIcon("icons/tool-color-picker-22.png"),
                                      tr("&Color Picker"), this);

	rectselectAct = new QAction(QIcon("icons/tool-rect-select-22.png"),
                                      tr("&Rectangular Select"), this);

	noneAct = new QAction(QIcon("icons/tool-none-icon.png"),
                                      tr("&None"), this);

	inputAct = new QAction(tr("&Input"), this);
    inputAct->setShortcut(QKeySequence(tr("1")));
    inputAct->setStatusTip(tr("Input"));
    connect(inputAct, SIGNAL(triggered()), this, SLOT(input()));

    outputAct = new QAction(tr("&Output"), this);
    outputAct->setShortcut(QKeySequence(tr("2")));
    outputAct->setStatusTip(tr("Output"));
    connect(outputAct, SIGNAL(triggered()), this, SLOT(output()));

    paletteAct = new QAction(tr("&Palette"), this);
    paletteAct->setShortcut(QKeySequence(tr("3")));
    paletteAct->setStatusTip(tr("Palette"));
    connect(paletteAct, SIGNAL(triggered()), this, SLOT(palette()));

    infoAct = new QAction(tr("&Info"), this);
    infoAct->setShortcut(QKeySequence(tr("4")));
    infoAct->setStatusTip(tr("Info"));
    connect(infoAct, SIGNAL(triggered()), this, SLOT(info()));

}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(loadAct);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveasAct);
    fileMenu->addSeparator();
    fileMenu->addAction(savepaletteAct);
    fileMenu->addAction(loadpaletteAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exportAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(fillselectionAct);
    editMenu->addAction(blendtoolAct);
    editMenu->addAction(copycurrlayerAct);
    editMenu->addSeparator();
    editMenu->addAction(resetallAct);
    editMenu->addSeparator();
    editMenu->addAction(cropinputAct);
    editMenu->addAction(cropoutputAct);

	viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(zoominAct);
    viewMenu->addAction(zoomoutAct);
    viewMenu->addAction(fitwindowAct);
    viewMenu->addAction(fullscreenAct);
    viewMenu->addSeparator();
    viewMenu->addAction(togglesectionsAct);
    viewMenu->addAction(showlayermanagerAct);
    viewMenu->addSeparator();
    viewMenu->addAction(inputAct);
    viewMenu->addAction(outputAct);
    viewMenu->addAction(paletteAct);
    viewMenu->addAction(infoAct);
}

void
MainWindow::createToolBars()
{
	fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    viewToolBar = addToolBar(tr("View"));
    viewToolBar->addAction(zoominAct);
    viewToolBar->addAction(zoomoutAct);
    viewToolBar->addAction(showlayermanagerAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(pencilAct);
    editToolBar->addAction(eraserAct);
	editToolBar->addAction(fuzzyselectAct);
	editToolBar->addAction(colorselectAct);
	editToolBar->addAction(bucketfillAct);
	editToolBar->addAction(colorpickerAct);
	editToolBar->addAction(rectselectAct);
	editToolBar->addSeparator();
	editToolBar->addAction(noneAct);
        
}
