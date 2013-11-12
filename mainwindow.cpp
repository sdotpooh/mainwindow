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
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
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

    QTreeWidgetItem *tree_Item_One = new QTreeWidgetItem(treeWidget);
    tree_Item_One->setText(0, tr("Input Settings"));

    QTreeWidgetItem *item_one = new QTreeWidgetItem(tree_Item_One);
 	//item_one->setText(0,"Settings Go Here");
 	//treeWidget->insertTopLevelItem(0,item_one);
    
	QWidget *widget_setting_buttons =new QWidget;
	QGridLayout *layout_tree_item_one = new QGridLayout;
	//QButtonGroup *settings_buttons = new QButtonGroup(this);
	//settings_buttons->addButton(ui->radioButton);
	//ui->radioButton->setChecked(true);

	QRadioButton* button1 = new QRadioButton("Brightness-Con");
	QRadioButton* button2 = new QRadioButton("Hue-Saturation");
	//button1->setCheckable(true);

	layout_tree_item_one->addWidget(button1,0,0);
	layout_tree_item_one->addWidget(button2,0,1);
 
	QSlider *slider1 = new QSlider(Qt::Horizontal, this);
	//connect(slider1, SIGNAL(valueChanged(int)), this, SLOT(value(int)));

	QSlider *slider2 = new QSlider(Qt::Horizontal, this);
	//connect(slider2, SIGNAL(valueChanged(int)), this, SLOT(value(int)));

	layout_tree_item_one->addWidget(slider1,1,1);
	layout_tree_item_one->addWidget(slider2,2,1);

	QLabel *label1 = new QLabel("Brightness");
	layout_tree_item_one->addWidget(label1,1,0);
	QLabel *label2 = new QLabel("Contrast");
	layout_tree_item_one->addWidget(label2,2,0);

	QLabel *label_value_1 = new QLabel("0");
	layout_tree_item_one->addWidget(label_value_1,1,2);
	QLabel *label_value_2 = new QLabel("0");
	layout_tree_item_one->addWidget(label_value_2,2,2);

	QPushButton* button_brightness_reset = new QPushButton("Reset");
	QPushButton* button_contrast_reset = new QPushButton("Reset");
	QPushButton* button_revert_input_settings = new QPushButton("Revert to original");

	layout_tree_item_one->addWidget(button_brightness_reset,1,3);
	layout_tree_item_one->addWidget(button_contrast_reset,2,3);
	layout_tree_item_one->addWidget(button_revert_input_settings,3,0);

	widget_setting_buttons->setLayout(layout_tree_item_one); 
    treeWidget->setItemWidget(item_one,0,widget_setting_buttons);
    treeWidget->insertTopLevelItem(0,item_one);

    QTreeWidgetItem *tree_Item_Two = new QTreeWidgetItem(treeWidget);
    tree_Item_Two->setText(0, tr("Mosaic Rendering"));

 	QTreeWidgetItem *item_two = new QTreeWidgetItem(tree_Item_Two);
    //item_two->setText(0,"Mosaic Rendering Go Here");
    //treeWidget->insertTopLevelItem(0,item_two);

	QWidget *widget_mosaic_rend =new QWidget;
	QGridLayout *layout_tree_item_two = new QGridLayout;
	QComboBox *combo_tree_item_two = new QComboBox();
	QLabel *label_style = new QLabel("Style");
	combo_tree_item_two->addItem("Standard");
	combo_tree_item_two->addItem("Standard 2");
	combo_tree_item_two->addItem("Standard 3");
	//QObject::connect(combo_tree_item_two, SIGNAL(activated(int)),label_style, SLOT(open()));
	layout_tree_item_two->addWidget(label_style,0,0);
	layout_tree_item_two->addWidget(combo_tree_item_two,0,1);

	QLabel *label_dither_title = new QLabel("Dither");
	layout_tree_item_two->addWidget(label_dither_title,1,0);

	QLabel *label_dither_value = new QLabel("0%");
	layout_tree_item_two->addWidget(label_dither_value,1,2);

	QSlider *slider_dither = new QSlider(Qt::Horizontal, this);
	//connect(slider_dither, SIGNAL(valueChanged(int)), this, SLOT(value(int)));
    layout_tree_item_two->addWidget(slider_dither,1,1);

 	widget_mosaic_rend->setLayout(layout_tree_item_two); 

    treeWidget->setItemWidget(item_two,0,widget_mosaic_rend);
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
	//QWidget   	*topFiller 		  = new QWidget;
	//QWidget 	*bottomFiller 	  = new QWidget;
	
	//topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
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
