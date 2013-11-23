// Group Members: Sean Vinas, Enmanuel Almanzar, Daniel Sodkiewicz
// Mosaic Tile Software Project
// CSC221 Section R: Software Design Lab
// Professor Wolberg
#include "mainwindow.h"
#include "Globals.h"
#include <iostream>
using namespace std;

MainWindow	*g_mainWindow = NULL;

MainWindow::MainWindow()
    : QMainWindow(),
           m_frameInput	 (NULL),
           m_frameOutput (NULL),
           m_framePalette(NULL),
           m_frameInfo	 (NULL),
           m_controlPanel(NULL),
           m_tabPreview	 (NULL)
{
    g_mainWindow = this;
    createActions();
    createMenus();
    createCentralWidget();
    createToolBars();
    setWindowTitle(tr("Tessera Grid V1.0"));
    setMinimumSize  (600,400);
    resize          (800,500);
    setCentralWidget(centralWindow);
}

MainWindow::~MainWindow() 
{
	delete centralWindow;
}

void 
MainWindow::createActions()
{ 
	a_blendTool 	= new QAction(tr("&Blend"),this);
    a_blendTool 	->setShortcut(QKeySequence("Ctrl+D"));
	a_blendTool 	->setStatusTip(tr("Blend tool"));

	a_bucketFill 	= new QAction(QIcon("icons/tool-bucket-fill-22.png"),
			                      tr("Bucket Fill"),this);

	a_byColorSelect = new QAction(QIcon("icons/tool-by-color-select-22.png"), 
								  tr("By Color Selection Tool"),this);

	a_colorPicker 	= new QAction(QIcon("icons/tool-color-picker-22.png"), 
								  tr("Color Picker"),this);

	a_colorSelection= new QAction(QIcon("icons/tool-by-color-select-22.png"),
								   tr("By Color Selection Tool"), this);

	a_copy 			= new QAction(tr("&Copy"),this);
    a_copy 			->setShortcut(QKeySequence::Copy);

	a_copyCurrentLayer= new QAction(tr("Cop&y Current Layer"),this);
    a_copyCurrentLayer->setShortcut(QKeySequence("Ctrl+Shift+C"));

	a_cropInput  	= new QAction(tr("&Crop Input"),this);
    a_cropInput 	->setShortcut(QKeySequence("Ctrl+Shift+R"));

    a_cropOutput 	= new QAction(tr("&Crop Output"),this);
    a_cropOutput 	->setShortcut(QKeySequence("Ctrl+Shift+T"));

	a_cut 			= new QAction(tr("&Cut"),this);
    a_cut 			->setShortcut(QKeySequence::Cut);

	a_eraser  		= new QAction(QIcon("icons/tool-eraser-22.png"), 
						          tr("Eraser"),this);

	a_exportPalette = new QAction(tr("&Export"),this);
    a_exportPalette ->setShortcut(QKeySequence("Ctrl+E"));

	a_fillSelection = new QAction(QIcon("icons/tool-bucket-fill-22.png"), 
								  tr("F&ill Selection"),this);
    a_fillSelection ->setShortcut(QKeySequence("Ctrl+I"));

	a_fitWindow 	= new QAction(tr("Fit &Window"),this);
    a_fitWindow 	->setShortcut(QKeySequence("Ctrl+W"));

    a_fullscreen 	= new QAction(tr("&Fullscreen"),this);
    a_fullscreen 	->setShortcut(QKeySequence("Ctrl+F"));

	a_fuzzySelect  	= new QAction(QIcon("icons/tool-fuzzy-select-22.png"), 
								  tr("Fuzzy Selection Tool"),this);

	a_info 			= new QAction(tr("I&nfo"),this);
    a_info 			->setShortcut(QKeySequence("4"));

	a_input 		= new QAction(tr("&Input"),this);
    a_input 		->setShortcut(QKeySequence("1"));

	a_load 			= new QAction(QIcon("icons/file-load.png"),
								  tr("&Load..."), this);
    a_load 			->setShortcut(QKeySequence(tr("Ctrl+L")));
    a_load 			->setStatusTip(tr("Load image"));
     				//connect(a_load, SIGNAL(triggered()), 
					//this, SLOT(s_load()));

	a_loadPalette 	= new QAction(tr("&Load Palette"),this);
    a_loadPalette 	->setShortcut(QKeySequence("Ctrl+Shift+L"));

	a_new  			= new QAction(QIcon("icons/file-new.png"),
								  tr("&New"), this);
    a_new 			->setShortcut(QKeySequence(tr("Ctrl+N")));
    a_new 			->setStatusTip(tr("Create A New Image"));
     				connect(a_new, SIGNAL(triggered()), 
							this,  SLOT(s_newProject()));


	a_none 			= new QAction(QIcon("icons/tool-none-icon.png"), 
			 			  		  tr("None"),this);

	a_open  		= new QAction(QIcon("icons/file-load.png"),
								  tr("&Open"), this);
    a_open 			->setShortcut(QKeySequence(tr("Ctrl+O")));
    a_open 			->setStatusTip(tr("Open Image"));
     				//connect(a_open, SIGNAL(triggered()), 
					            //this,  SLOT(s_loadProject()));
	
	a_output 		= new QAction(tr("O&utput"),this);
    a_output 		->setShortcut(QKeySequence("2"));

	a_palette  		= new QAction(tr("&Palette"),this);
    a_palette 		->setShortcut(QKeySequence("3"));

	a_paste 		= new QAction(tr("&Paste"),this);
    a_paste 		->setShortcut(QKeySequence::Paste);

    a_pencil  		= new QAction(QIcon("icons/tool-pencil-22.png"), 
						     	  tr("Pencil"),this);

	a_quit 			= new QAction(tr("&Quit"),this);
    a_quit 			->setShortcut(QKeySequence("Ctrl+Q"));
     				connect(a_quit, SIGNAL(triggered()), 
							this,   SLOT(close()));

	a_rectSelect 	= new QAction(QIcon("icons/tool-rect-select-22.png"), 
							      tr("Rectangle Selection"),this);

	a_redo  		= new QAction(tr("&Redo"),this);
    a_redo 			->setShortcut(QKeySequence::Redo);

	a_resetAll 		= new QAction(tr("Reset &All Parameters"),this);
    a_resetAll 		->setShortcut(QKeySequence("Ctrl+Shift+A"));

    a_saveAsProject = new QAction(tr("Save &As"),this);
    a_saveAsProject ->setShortcut(QKeySequence("Ctrl+Shift+S"));
    a_saveAsProject ->setStatusTip(tr("Save As"));

    a_savePalette 	= new QAction(tr("Save &Palette"),this);
    a_savePalette 	->setShortcut(QKeySequence("Ctrl+Shift+P"));
	a_savePalette 	->setStatusTip(tr("Save Palette"));

	a_saveProject 	= new QAction(QIcon("icons/file-save.png"), 
								  tr("&Save"),this);
    a_saveProject 	->setShortcut(QKeySequence(tr("Ctrl+S")));
    a_saveProject 	->setStatusTip(tr("Save"));

	a_showLayerManager= new QAction(QIcon("icons/view-layer-manager.png"), 
									tr("Show Layer &Manager"),this);
    a_showLayerManager->setShortcut(QKeySequence("Ctrl+M"));

	

	a_toggleSections= new QAction(tr("Toggle &Sections"),this);
    a_toggleSections->setShortcut(QKeySequence("Ctrl+B"));

    a_undo 			= new QAction(tr("&Undo"),this);
    a_undo 			->setShortcut(QKeySequence::Undo);

    a_zoomIn  		= new QAction(QIcon("icons/view-zoomin.png"), 
						   		  tr("&Zoom In"),this);
    a_zoomIn 		->setShortcut(QKeySequence("Ctrl+="));
					connect(a_zoomIn, SIGNAL(triggered()), 
						this,   SLOT(s_zoomIn()));
					//connect(a_zoomIn, SIGNAL(triggered()), 
					//		this,   SLOT(s_sliderValue()));

    a_zoomOut 		= new QAction(QIcon("icons/view-zoomout.png"), 
			  					  tr("Zoom &Out"),this);
    a_zoomOut 		->setShortcut(QKeySequence("Ctrl+-"));
					connect(a_zoomOut, SIGNAL(triggered()), 
							this,   SLOT(s_zoomOut()));
	
}
void
MainWindow::createMenus()
{
	createMenuFile();
	createMenuEdit();
	createMenuView();
	createMenuTool();
}
void 
MainWindow::createMenuFile()
{   
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(a_new);
    fileMenu->addAction(a_open);
    fileMenu->addAction(a_load);
    fileMenu->addSeparator();
    fileMenu->addAction(a_saveProject);
    fileMenu->addAction(a_saveAsProject);
    fileMenu->addSeparator();
    fileMenu->addAction(a_savePalette);
    fileMenu->addAction(a_loadPalette);
    fileMenu->addSeparator();
    fileMenu->addAction(a_exportPalette);
    fileMenu->addSeparator();
    fileMenu->addAction(a_quit);
}

void 
MainWindow::createMenuEdit()
{
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(a_undo);
    editMenu->addAction(a_redo);
    editMenu->addSeparator();
    editMenu->addAction(a_cut);
    editMenu->addAction(a_copy);
    editMenu->addAction(a_paste);
    editMenu->addAction(a_fillSelection);
    editMenu->addAction(a_blendTool);
    editMenu->addAction(a_copyCurrentLayer);
    editMenu->addSeparator();
    editMenu->addAction(a_resetAll);
    editMenu->addSeparator();
    editMenu->addAction(a_cropInput);
    editMenu->addAction(a_cropOutput);
}

void 
MainWindow::createMenuView()
{
    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(a_zoomIn);
    viewMenu->addAction(a_zoomOut);
    viewMenu->addAction(a_fitWindow);
    viewMenu->addAction(a_fullscreen);
    viewMenu->addSeparator();
    viewMenu->addAction(a_toggleSections);
    viewMenu->addAction(a_showLayerManager);
    viewMenu->addSeparator();
    viewMenu->addAction(a_input);
    viewMenu->addAction(a_output);
    viewMenu->addAction(a_palette);
    viewMenu->addAction(a_info);
}

void 
MainWindow::createMenuTool()
{
    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(a_pencil);
    toolsMenu->addAction(a_eraser);
    toolsMenu->addAction(a_fuzzySelect);
    toolsMenu->addAction(a_colorSelection);
    toolsMenu->addAction(a_bucketFill);
    toolsMenu->addAction(a_colorPicker);
    toolsMenu->addAction(a_rectSelect);
    toolsMenu->addAction(a_none);
}

void 
MainWindow::createCentralWidget()
{
    centralWindow= new QWidget;
    windowTabs   = new QTabWidget(this);
    m_frameInput = new ImageWindow(this);

	//Add Buttons to input Tab
	QTabWidget  *inputTabWidget = new QTabWidget;
	QVBoxLayout *imageTabLayout = new QVBoxLayout;
	QHBoxLayout *imageButtons   = new QHBoxLayout;
	
	fullScreenButton = new QPushButton("Full Screen");
	fitWindowButton  = new QPushButton("Fit Window");

	slider = new QSlider(Qt::Horizontal);
	slider->setTickPosition(QSlider::TicksBelow);
	slider->setMinimum(1);
	slider->setMaximum(45);
	slider->setTickInterval(1);
	slider->setSingleStep(1);
	sliderLabel = new QLabel("100%");
	connect(slider, SIGNAL(valueChanged(int)),
            this,     SLOT(s_sliderZoom(int)));
	

	imageButtons->addWidget(fullScreenButton);
	imageButtons->addWidget(fitWindowButton);
	imageButtons->addWidget(slider);
	imageButtons->addWidget(sliderLabel);
	
	imageTabLayout->addWidget(m_frameInput);
	imageTabLayout->addLayout(imageButtons);
	inputTabWidget->setLayout(imageTabLayout);

    outputTab    = new QWidget();
    paletteTab   = new QWidget();
    infoTab      = new QWidget();

    windowTabs->setMinimumSize(QSize(300,200)); 
	windowTabs->addTab(inputTabWidget, tr("Input"));
    windowTabs->addTab(outputTab,tr("Output"));
    windowTabs->addTab(paletteTab,tr("Palette"));
    windowTabs->addTab(infoTab,tr("Info"));

    m_controlPanel = new ControlPanel;
    m_controlPanel-> setMinimumSize(350, QSizePolicy::Expanding);

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(windowTabs);
    mainLayout->addWidget(m_controlPanel);
    centralWindow->setLayout(mainLayout);
    centralWindow->show();
}


void MainWindow::createToolBars()
{
	createFileToolBar();
	createViewToolBar();
	createEditToolBar();
}

void 
MainWindow::createFileToolBar()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(a_new);
    fileToolBar->addAction(a_load);
    fileToolBar->addAction(a_saveProject);
}

void 
MainWindow::createViewToolBar()
{
	viewToolBar = addToolBar(tr("View"));
    viewToolBar->addAction(a_zoomIn);
    viewToolBar->addAction(a_zoomOut);
    viewToolBar->addAction(a_showLayerManager);
}

void 
MainWindow::createEditToolBar()
{
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(a_pencil);
    editToolBar->addAction(a_eraser);
    editToolBar->addAction(a_fuzzySelect);
    editToolBar->addAction(a_byColorSelect);
    editToolBar->addAction(a_bucketFill);
    editToolBar->addAction(a_colorPicker);
    editToolBar->addAction(a_rectSelect);
    editToolBar->addSeparator();
    editToolBar->addAction(a_none);
}

void
MainWindow::updateInputFrame()
{
	if(m_params.image().isNull()) {
		qDebug() << "Error: NULL image.";
		return;
	}
	m_frameInput->setImage(m_params.image());
}

TesseraParameters&
MainWindow::parameters()
{
    return m_params;
}

void
MainWindow::s_newProject()
{
    QFileDialog dialog(this);
    if(!m_currentInDir.isEmpty())
        dialog.setDirectory(m_currentInDir);
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString sel("Images");
    QString file =  dialog.getOpenFileName(this,
                 "Open File", m_currentInDir,
                 "Image (*.bmp *.jpeg *.jpg *.png  *.tiff);"
                 , &sel);
    if(file.isNull())
        return;
    m_currentInDir = QFileInfo(file).dir().absolutePath();
    QImage image = QImage(file);
    if(image.isNull()) {
        QMessageBox::critical(this,
                              "Error",
                              "Image Read Error",
                              QMessageBox::Ok);
        return;
    }
    m_params.reset();
    m_params.setOriginalImage(image);
    m_params.setImage(image);
    m_controlPanel->resetControls();
    updateInputFrame();
}

void MainWindow::s_loadProject 	 ()	{}
void MainWindow::s_saveProject 	 ()	{}
void MainWindow::s_undo 		 ()	{}
void MainWindow::s_redo 		 ()	{}

void MainWindow::s_sliderValue()
{
	s_zoomIn();
	TesseraParameters &params   = g_mainWindow->parameters();
	
	slider->setValue(params.zoomFactor());
}

void MainWindow::s_sliderZoom(int zf)
{
	double zoomFactor;
	TesseraParameters &params   = g_mainWindow->parameters();
	const QImage &originalImage = params.originalImage();
	QImage zoomInImage = originalImage;
	//Determine if zoom in or out
	if (zf < params.zoomFactor())
		zoomFactor = -(double(zf)/2);
	else
		zoomFactor = double(zf)/2;
	
	if (zoomFactor < 1)
		zoomFactor = 1;
	if (zoomFactor > 45)
		zoomFactor = 45;
	
	params.setZoomFactor(zoomFactor);
	double w = zoomInImage.width();
	double h = zoomInImage.height();
	double zw = w/zoomFactor;
	double zh = h/zoomFactor;
	double xi = (w - zw)/2;
	double yi = (h - zh)/2;
	zoomInImage = zoomInImage.copy(xi, yi, zw, zh);
	
	//Display the image
	params.setImage(zoomInImage);
	g_mainWindow->updateInputFrame();
}
void 
MainWindow::s_zoomIn()	
{
	zoom(0.5);
}

void 
MainWindow::s_zoomOut()	
{
	zoom(-0.5);
}

void 
MainWindow::zoom(double factor)
{
	TesseraParameters &params = g_mainWindow->parameters();
	//Get the original image
	const QImage &originalImage = params.originalImage();
	QImage zoomInImage = originalImage;
	//Get the current zoomFactor
	double zoomFactor = params.zoomFactor();
	zoomFactor = zoomFactor + factor;
	//Make sure it doesn't zoom too close/far!
	if (zoomFactor < 1)
		zoomFactor = 1;
	if (zoomFactor > 45)
		zoomFactor = 45;
	params.setZoomFactor(zoomFactor);
	double w = zoomInImage.width();
	double h = zoomInImage.height();
	double zw = w/zoomFactor;
	double zh = h/zoomFactor;
	double xi = (w - zw)/2;
	double yi = (h - zh)/2;
	zoomInImage = zoomInImage.copy(xi, yi, zw, zh);
	
	//Display the image
	params.setImage(zoomInImage);
	g_mainWindow->updateInputFrame();
}
void MainWindow::s_showInputTab  () {m_tabPreview->setCurrentIndex(0);}
void MainWindow::s_showOutputTab () {m_tabPreview->setCurrentIndex(1);}
void MainWindow::s_showPaletteTab() {m_tabPreview->setCurrentIndex(2);}
void MainWindow::s_showInfoTab 	 () {m_tabPreview->setCurrentIndex(3);}


