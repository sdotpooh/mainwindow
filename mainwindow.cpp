#include "mainwindow.h"
#include "Globals.h"

using namespace std;

mainwindow	*g_mainWindow = NULL;

mainwindow::mainwindow	 ()
	:QMainWindow	( 	 ),
	m_frameInput	(NULL),
	m_frameOutput 	(NULL),
	m_framePalette 	(NULL),
	m_frameInfo	 	(NULL),
	m_controlPanel 	(NULL),
	m_tabPreview	(NULL)
{
	g_mainWindow = this;	
	createActions();	
	createMenus  ();	
	createWidgets();
	createToolBars();
	setWindowTitle(tr("Tessera Grid V1.0"));
	setMinimumSize(600, 600);
	resize	      (800, 600);
	setCentralWidget(centralWindow);
	
}

mainwindow::~mainwindow() 
{

}

void
mainwindow::createActions()
{
	createActionsFile();
	createActionsEdit();
	createActionsView();
}

void
mainwindow::createMenus()
{
	createMenuFile();
	createMenuEdit();
	createMenuView();
}
void
mainwindow::createToolBars()
{
	createToolBarFile();
	createToolBarEdit();
	createToolBarView();
}

void
mainwindow::createActionsFile()
{
	newAct = new QAction(QIcon("icons/file-new.png"),tr("&New"), this);
    newAct->setShortcut(QKeySequence(tr("Ctrl+N")));
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(s_newProject()));

    openAct = new QAction(QIcon("icons/file-load.png"),tr("&Open"), this);
    openAct->setShortcut(QKeySequence(tr("Ctrl+O")));
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(s_loadProject()));

    loadAct = new QAction(tr("&Load..."), this);
    loadAct->setShortcut(QKeySequence(tr("Ctrl+L")));
    loadAct->setStatusTip(tr("Load image"));
    //connect(loadAct, SIGNAL(triggered()), this, SLOT(s_load()));

    saveAct = new QAction(QIcon("icons/file-save.png"),tr("&Save"), this);
    saveAct->setShortcut(QKeySequence(tr("Ctrl+S")));
    saveAct->setStatusTip(tr("Save the image"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(s_saveProject()));

    saveasAct = new QAction(tr("&Save As..."), this);
    saveasAct->setShortcut(QKeySequence(tr("Ctrl+Shift+S")));
    saveasAct->setStatusTip(tr("Save As the image"));
    connect(saveasAct, SIGNAL(triggered()), this, SLOT(s_saveAs()));

    savepaletteAct = new QAction(tr("&Save palette..."), this);
    savepaletteAct->setShortcut(QKeySequence(tr("Ctrl+P")));
    savepaletteAct->setStatusTip(tr("Save the palette"));
    connect(savepaletteAct, SIGNAL(triggered()), this, SLOT(s_savePalette()));

    loadpaletteAct = new QAction(tr("&Load palette..."), this);
    loadpaletteAct->setShortcut(QKeySequence(tr("Ctrl+G")));
    loadpaletteAct->setStatusTip(tr("Load the palette"));
    connect(loadpaletteAct, SIGNAL(triggered()), this, SLOT(s_loadPalette()));

    exportAct = new QAction(tr("&Export..."), this);
    exportAct->setShortcut(QKeySequence(tr("Ctrl+E")));
    exportAct->setStatusTip(tr("Export"));
    connect(exportAct, SIGNAL(triggered()), this, SLOT(s_exportImage()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(QKeySequence(tr("Ctrl+Q")));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(s_close()));
}

void
mainwindow::createActionsEdit()
{
	undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcut(QKeySequence(tr("Ctrl+Z")));
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(s_undo()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcut(QKeySequence(tr("Ctrl+Y")));
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(s_redo()));

    cutAct = new QAction(tr("&Cut"), this);
    cutAct->setShortcut(QKeySequence(tr("Ctrl+X")));
    cutAct->setStatusTip(tr("Cut"));
    connect(cutAct, SIGNAL(triggered()), this, SLOT(s_cut()));

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcut(QKeySequence(tr("Ctrl+C")));
    copyAct->setStatusTip(tr("Copy"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(s_copy()));

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcut(QKeySequence(tr("Ctrl+V")));
    pasteAct->setStatusTip(tr("Paste"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(s_paste()));

    fillselectionAct = new QAction(QIcon("icons/tool-bucket-fill-22.png"),
                                   tr("&Fill"), this);
    fillselectionAct->setShortcut(QKeySequence(tr("Ctrl+I")));
    fillselectionAct->setStatusTip(tr("Fill selection"));
    connect(fillselectionAct, SIGNAL(triggered()), this, SLOT(s_fill()));

    blendtoolAct = new QAction(tr("&Blend"), this);
    blendtoolAct->setShortcut(QKeySequence(tr("Ctrl+D")));
    blendtoolAct->setStatusTip(tr("Blend tool"));
    connect(blendtoolAct, SIGNAL(triggered()), this, SLOT(s_blend()));

    copycurrlayerAct = new QAction(tr("&Copy Layer"), this);
    copycurrlayerAct->setShortcut(QKeySequence(tr("Ctrl+Shift+C")));
    copycurrlayerAct->setStatusTip(tr("Copy Current Layer"));
    connect(copycurrlayerAct, SIGNAL(triggered()), this, SLOT(s_copylayer()));

    resetallAct = new QAction(tr("&Reset All"), this);
    resetallAct->setShortcut(QKeySequence(tr("Ctrl+A")));
    resetallAct->setStatusTip(tr("Reset All"));
    connect(resetallAct, SIGNAL(triggered()), this, SLOT(s_resetall()));

    cropinputAct = new QAction(tr("&Crop Input"), this);
    cropinputAct->setShortcut(QKeySequence(tr("Ctrl+R")));
    cropinputAct->setStatusTip(tr("Crop Input"));
    connect(cropinputAct, SIGNAL(triggered()), this, SLOT(s_cropinput()));

    cropoutputAct = new QAction(tr("&Crop Output"), this);
    cropoutputAct->setShortcut(QKeySequence(tr("Ctrl+T")));
    cropoutputAct->setStatusTip(tr("Crop Output"));
    connect(cropoutputAct, SIGNAL(triggered()), this, SLOT(s_cropoutput()));
}

void
mainwindow::createActionsView()
{
	zoominAct = new QAction(QIcon("icons/view-zoomin.png"),tr("&Zoom In"), this);
    zoominAct->setShortcut(QKeySequence(tr("Ctrl+Shift+V")));
    zoominAct->setStatusTip(tr("Zoom in"));
	zoominAct->setEnabled(false);
    connect(zoominAct, SIGNAL(triggered()), this, SLOT(s_zoomin()));

    zoomoutAct = new QAction(QIcon("icons/view-zoomout.png"),tr("&Zoom Out"), this);
    zoomoutAct->setShortcut(QKeySequence(tr("Ctrl+Shift+U")));
    zoomoutAct->setStatusTip(tr("Zoom out"));
	zoomoutAct->setEnabled(false);
    connect(zoomoutAct, SIGNAL(triggered()), this, SLOT(s_zoomout()));

    fitwindowAct = new QAction(tr("&Fit Window"), this);
    fitwindowAct->setShortcut(QKeySequence(tr("Ctrl+W")));
    fitwindowAct->setStatusTip(tr("Fit window"));
	fitwindowAct->setEnabled(false);
    connect(fitwindowAct, SIGNAL(triggered()), this, SLOT(s_fitwindow()));

    fullscreenAct = new QAction(tr("&Full Screen"), this);
    fullscreenAct->setShortcut(QKeySequence(tr("Ctrl+F")));
    fullscreenAct->setStatusTip(tr("Full screen"));
	fullscreenAct->setEnabled(false);
    connect(fullscreenAct, SIGNAL(triggered()), this, SLOT(s_fullscreen()));

    togglesectionsAct = new QAction(tr("&Toggle Sections"), this);
    togglesectionsAct->setShortcut(QKeySequence(tr("Ctrl+B")));
    togglesectionsAct->setStatusTip(tr("Toggle sections"));
    connect(togglesectionsAct, SIGNAL(triggered()), this, SLOT(s_togglesections()));

    showlayermanagerAct = new QAction(QIcon("icons/view-layer-manager.png"),
                                      tr("&Show Layer Manager"), this);
    showlayermanagerAct->setShortcut(QKeySequence(tr("Ctrl+M")));
    showlayermanagerAct->setStatusTip(tr("Show layer manager"));
    connect(showlayermanagerAct, SIGNAL(triggered()), this, SLOT(s_showlayermanager()));
	
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
    connect(inputAct, SIGNAL(triggered()), this, SLOT(s_showInputTab()));

    outputAct = new QAction(tr("&Output"), this);
    outputAct->setShortcut(QKeySequence(tr("2")));
    outputAct->setStatusTip(tr("Output"));
    connect(outputAct, SIGNAL(triggered()), this, SLOT(s_showOutputTab()));

    paletteAct = new QAction(tr("&Palette"), this);
    paletteAct->setShortcut(QKeySequence(tr("3")));
    paletteAct->setStatusTip(tr("Palette"));
    connect(paletteAct, SIGNAL(triggered()), this, SLOT(s_showPaletteTab()));

    infoAct = new QAction(tr("&Info"), this);
    infoAct->setShortcut(QKeySequence(tr("4")));
    infoAct->setStatusTip(tr("Info"));
    connect(infoAct, SIGNAL(triggered()), this, SLOT(s_showInfoTab()));
}

void
mainwindow::createMenuFile()
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
}

void
mainwindow::createMenuEdit()
{
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
}

void
mainwindow::createToolBarView()
{
	viewToolBar = addToolBar(tr("View"));
    viewToolBar->addAction(zoominAct);
    viewToolBar->addAction(zoomoutAct);
    viewToolBar->addAction(showlayermanagerAct);
}

void
mainwindow::createToolBarFile()
{
	fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
}

void
mainwindow::createToolBarEdit()
{
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

void
mainwindow::createMenuView()
{
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
mainwindow::createWidgets()
{
	centralWindow   = new QWidget;
    tabWidget   	= new QTabWidget(this);

    inputTab 		= new ImageWindow(this);
    outputTab   	= new QWidget();
    paletteTab  	= new QWidget();
    infoTab     	= new QWidget();

    tabWidget->setMinimumSize(QSize(300,200));
    tabWidget->addTab(inputTab, tr("Input"));
    tabWidget->addTab(outputTab,tr("Output"));
    tabWidget->addTab(paletteTab,tr("Palette"));
    tabWidget->addTab(infoTab,tr("Info"));

    //Create contro panel
    controlPanel = new ControlPanel;
    controlPanel-> setMinimumSize(350, QSizePolicy::Expanding);

    imageLayout = new QHBoxLayout;
    imageLayout->addWidget(tabWidget);
    imageLayout->addWidget(controlPanel);
    centralWindow->setLayout(imageLayout);
    centralWindow->show();
}

void
mainwindow::updateInputFrame()
{
	if(m_params.image().isNull()) {
		qDebug() << "Error: NULL image.";
		return;
	}
	m_frameInput->setImage(m_params.image());
}

TesseraParameters&
mainwindow::parameters()
{
	return m_params;
}


void mainwindow::s_blend() 		{}
void mainwindow::s_close() 		{}
void mainwindow::s_copy() 		{}
void mainwindow::s_copylayer() 	{}
void mainwindow::s_cropinput() 	{}
void mainwindow::s_cropoutput() {}
void mainwindow::s_cut() 		{}
void mainwindow::s_exportImage(){}
void mainwindow::s_fill() 		{}
void mainwindow::s_fitwindow() 	{}
void mainwindow::s_fullscreen() {}
void mainwindow::s_loadPalette(){}
void mainwindow::s_loadProject(){}

void
mainwindow::s_newProject()
{
	QFileDialog dialog(this);
	if(!m_currentInDir.isEmpty())
		dialog.setDirectory(m_currentInDir);
	dialog.setFileMode(QFileDialog::ExistingFile);
	QString sel("Images");
	QString file =  dialog.getOpenFileName(this,
			     "Open File", m_currentInDir,
			     "Image (*.bmp *.tiff *.jpeg *.jpg *.png)"
			      , &sel);
	if(file.isNull())
		return;
	m_currentInDir = QFileInfo(file).dir().absolutePath();
	QImage image = QImage(file);
	if(image.isNull()) {
		QMessageBox::critical(this,"Error", "Image Read Error",QMessageBox::Ok);
		return;
	}
	m_params.reset();
	m_params.setOriginalImage(image);
	m_params.setImage(image);
	m_controlPanel->resetControls();
	updateInputFrame();
}

void mainwindow::s_paste() 			 {}
void mainwindow::s_redo() 			 {}
void mainwindow::s_resetall() 		 {}
void mainwindow::s_saveAs() 		 {}
void mainwindow::s_savePalette() 	 {}
void mainwindow::s_saveProject() 	 {}
void mainwindow::s_showlayermanager(){}
void mainwindow::s_togglesections()  {}
void mainwindow::s_undo() 			 {}
void mainwindow::s_zoomin() 		 {}
void mainwindow::s_zoomout() 		 {}

// Make the input/output/palette/info page current in the tab widget
void mainwindow::s_showInputTab()  {m_tabPreview->setCurrentIndex(0);}
void mainwindow::s_showOutputTab() {m_tabPreview->setCurrentIndex(1);}
void mainwindow::s_showPaletteTab(){m_tabPreview->setCurrentIndex(2);}
void mainwindow::s_showInfoTab()   {m_tabPreview->setCurrentIndex(3);}


