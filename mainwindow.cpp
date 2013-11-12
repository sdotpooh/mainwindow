// Sean Vinas, Enmanuel Almanzar, and Daniel Sodkiewicz Mosaic software 

#include <QtGui>
#include <QString>
#include <QFile>
#include <QImage>
#include <QPixmap>
#include "mainwindow.h"

#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QRadioButton>
#include <QSlider>

MainWindow::MainWindow() 
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    createActions();
	createMenus();
    createToolBars();
	createLayout(widget);
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
    
}

void
MainWindow::open()
{
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
		//imageLabel->setPixmap(image);
		imageLabel->setPixmap(QPixmap::fromImage(image));
        
		//scaleFactor = 1.0;

        //printAct->setEnabled(true);
        //fitToWindowAct->setEnabled(true);
        //updateActions();

        //if (!fitToWindowAct->isChecked())
        //    imageLabel->adjustSize();
	 }
}


void
MainWindow::load()
{
    
}

void
MainWindow::save()
{
    
}

void
MainWindow::saveAs()
{
    
}

void
MainWindow::savePalette()
{
   
}

void
MainWindow::loadPalette()
{
   
}

void
MainWindow::exportImage()
{
    
}

void
MainWindow::close()
{
    
}

void
MainWindow::undo()
{
    
}

void
MainWindow::redo()
{
   
}

void
MainWindow::cut()
{
    
}

void
MainWindow::copy()
{
    
}

void
MainWindow::paste()
{
    
}

void
MainWindow::fill()
{
    
}

void
MainWindow::blend()
{
    
}

void
MainWindow::copylayer()
{
    
}

void
MainWindow::resetall()
{
    
}

void
MainWindow::cropinput()
{
    
}

void
MainWindow::cropoutput()
{
    
}

void
MainWindow::zoomin()
{
    
}

void
MainWindow::zoomout()
{
    
}

void
MainWindow::fitwindow()
{
	bool fitwindow = fitwindowAct->isChecked();
     //scrollArea->setWidgetResizable(fitwindow);
     if (!fitwindow) {
         fullscreen();
     }
     updateActions();
}

void
MainWindow::fullscreen()
{
    
}

void
MainWindow::togglesections()
{
    
}

void
MainWindow::showlayermanager()
{
    
}

void
MainWindow::input()
{
    
}

void
MainWindow::output()
{
    
}

void
MainWindow::palette()
{
    
}

void
MainWindow::info()
{
    
}
void 
MainWindow::createActions()
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
	zoominAct->setEnabled(false);
    connect(zoominAct, SIGNAL(triggered()), this, SLOT(zoomin()));

    zoomoutAct = new QAction(QIcon("icons/view-zoomout.png"),tr("&Zoom Out"), this);
    zoomoutAct->setShortcut(QKeySequence(tr("Ctrl+Shift+U")));
    zoomoutAct->setStatusTip(tr("Zoom out"));
	zoomoutAct->setEnabled(false);
    connect(zoomoutAct, SIGNAL(triggered()), this, SLOT(zoomout()));

    fitwindowAct = new QAction(tr("&Fit Window"), this);
    fitwindowAct->setShortcut(QKeySequence(tr("Ctrl+W")));
    fitwindowAct->setStatusTip(tr("Fit window"));
	fitwindowAct->setEnabled(false);
    connect(fitwindowAct, SIGNAL(triggered()), this, SLOT(fitwindow()));

    fullscreenAct = new QAction(tr("&Full Screen"), this);
    fullscreenAct->setShortcut(QKeySequence(tr("Ctrl+F")));
    fullscreenAct->setStatusTip(tr("Full screen"));
	fullscreenAct->setEnabled(false);
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

void 
MainWindow::createMenus()
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

void
MainWindow::createTrees(QTreeWidget *treeWidget)
{
    treeWidget->header()->hide();

    QTreeWidgetItem *treeItemOne   = new QTreeWidgetItem(treeWidget);
	QTreeWidgetItem *itemOne 	   = new QTreeWidgetItem(treeItemOne);
	QTreeWidgetItem *treeItemTwo   = new QTreeWidgetItem(treeWidget);
	QTreeWidgetItem *itemTwo 	   = new QTreeWidgetItem(treeItemTwo);
	QTreeWidgetItem *treeItemThree = new QTreeWidgetItem(treeWidget);
	QTreeWidgetItem *itemThree 	   = new QTreeWidgetItem(treeItemThree);
	QTreeWidgetItem *treeItemFour  = new QTreeWidgetItem(treeWidget);
	QTreeWidgetItem *itemFour 	   = new QTreeWidgetItem(treeItemFour);
	QTreeWidgetItem *treeItemFive  = new QTreeWidgetItem(treeWidget);
	QTreeWidgetItem *itemFive 	   = new QTreeWidgetItem(treeItemFive);

	QComboBox *comboTreeItemTwo    = new QComboBox();
	
	QLabel *label1 			 = new QLabel("Brightness");
	QLabel *label2 			 = new QLabel("Contrast");
	QLabel *labelDitherTitle = new QLabel("Dither");
	QLabel *labelStyle 		 = new QLabel("Style");
	QLabel *labelDitherValue = new QLabel("0%");
	QLabel *labelValue1 	 = new QLabel("0");
	QLabel *labelValue2 	 = new QLabel("0");
	
	QSlider *sliderDither 	 = new QSlider(Qt::Horizontal, this);
    QSlider *slider1 		 = new QSlider(Qt::Horizontal, this);
	QSlider *slider2 		 = new QSlider(Qt::Horizontal, this);

	QRadioButton* button1 = new QRadioButton("Brightness-Con");
	QRadioButton* button2 = new QRadioButton("Hue-Saturation");

	QPushButton* buttonBrightReset     = new QPushButton("Reset");
	QPushButton* buttonContrastReset   = new QPushButton("Reset");
	QPushButton* buttonRevertInSetting = new QPushButton("Revert to original");

	QWidget *widgetSettingButtons =new QWidget;
	QWidget *widgetMosaicRend 	  =new QWidget;

	QGridLayout *layoutTreeItemOne = new QGridLayout;
	QGridLayout *layoutTreeItemTwo = new QGridLayout;
	
	layoutTreeItemOne->addWidget(button1, 0, 0);
	layoutTreeItemOne->addWidget(button2, 0, 1);
	layoutTreeItemOne->addWidget(slider1, 1, 1);
	layoutTreeItemOne->addWidget(slider2, 2, 1);
	layoutTreeItemOne->addWidget(label1, 1, 0);
	layoutTreeItemOne->addWidget(label2, 2, 0);
	layoutTreeItemOne->addWidget(labelValue1, 1, 2);
	layoutTreeItemOne->addWidget(labelValue2, 2, 2);
	layoutTreeItemOne->addWidget(buttonBrightReset, 1, 3);
	layoutTreeItemOne->addWidget(buttonContrastReset, 2, 3);
	layoutTreeItemOne->addWidget(buttonRevertInSetting, 3, 0);

	comboTreeItemTwo->addItem("Standard"  );
	comboTreeItemTwo->addItem("Standard 2");
	comboTreeItemTwo->addItem("Standard 3");
	
	layoutTreeItemTwo->addWidget(labelStyle, 0, 0      );
	layoutTreeItemTwo->addWidget(comboTreeItemTwo, 0, 1);
	layoutTreeItemTwo->addWidget(labelDitherTitle, 1, 0);
	layoutTreeItemTwo->addWidget(labelDitherValue, 1, 2);
    layoutTreeItemTwo->addWidget(sliderDither, 1, 1   );

	widgetSettingButtons->setLayout(layoutTreeItemOne);
 	widgetMosaicRend    ->setLayout(layoutTreeItemTwo); 

	treeWidget->setItemWidget(itemOne, 0, widgetSettingButtons);
    treeWidget->setItemWidget(itemTwo, 0, widgetMosaicRend    );
    
	treeItemOne  ->setText(0, tr("Input Settings"  ));
    treeItemTwo  ->setText(0, tr("Mosaic Rendering"));
    treeItemThree->setText(0, tr("Mosaic Size"     ));
    treeItemFour ->setText(0, tr("Title Palette"   )); 
	treeItemFive ->setText(0, tr("Grout"           ));

	itemThree->setText(0,"Mosaic Size Go Here"  );
	itemFour ->setText(0,"Title Palette Go Here");
	itemFive ->setText(0,"Grout Go Here"        );

	treeWidget->insertTopLevelItem(0, itemOne  );
	treeWidget->insertTopLevelItem(0, itemTwo  );
	treeWidget->insertTopLevelItem(0, itemThree);
    treeWidget->insertTopLevelItem(0, itemFour );
    treeWidget->insertTopLevelItem(0, itemFive );
}

void 
MainWindow::createLayout(QWidget *widget)
{
	QHBoxLayout *layout 		  = new QHBoxLayout;
	QHBoxLayout *tabButtonslayout = new QHBoxLayout;
	QVBoxLayout *tabLayout 		  = new QVBoxLayout;
	QVBoxLayout *imageLayout 	  = new QVBoxLayout;
	QVBoxLayout *inTabLayout 	  = new QVBoxLayout;
	QTabWidget  *tabWidget        = new QTabWidget;  
	QTabWidget  *inputTabWidget   = new QTabWidget;
	QTreeWidget *treeWidget  	  = new QTreeWidget;
	QLabel 		*imageLabel 	  = new QLabel();
	QLabel 		*sliderLabel  	  = new QLabel("100%");
	
	createTrees(treeWidget);

	image  			= QPixmap("starrynight.png");
	imageLabel 		->setPixmap(image);
	imageLayout 	->addWidget(imageLabel);
	tabButtonslayout->addWidget(new QPushButton("Full Screen"));
	tabButtonslayout->addWidget(new QPushButton("Fit Window"));
	slider  		= new QSlider(Qt::Horizontal);
    slider 			->setTickPosition(QSlider::TicksBelow);
    slider 			->setTickInterval(5);
    slider 			->setSingleStep(1);
	tabButtonslayout->addWidget(slider);	
	tabButtonslayout->addWidget(sliderLabel);
	inTabLayout   	->addLayout(imageLayout);
	inTabLayout   	->addLayout(tabButtonslayout);
	inputTabWidget 	->setLayout(inTabLayout);
	tabWidget 		->addTab(inputTabWidget,   "Input");
    tabWidget 		->addTab(new QTabWidget(), "Output");
    tabWidget 		->addTab(new QTabWidget(), "Palette");
    tabWidget 		->addTab(new QTabWidget(), "Info");
    tabLayout 		->addWidget(tabWidget);
	layout  		->addLayout(tabLayout);
    layout 			->addWidget(treeWidget);
    widget 			->setLayout(layout);
}
void 
MainWindow::updateActions()
{
     zoominAct    ->setEnabled(!fitwindowAct->isChecked());
     zoomoutAct   ->setEnabled(!fitwindowAct->isChecked());
     fullscreenAct->setEnabled(!fitwindowAct->isChecked());
}
