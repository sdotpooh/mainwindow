// Group Members: Sean Vinas, Enmanuel Almanzar, Daniel Sodkiewicz
// Mosaic Tile Software Project
// CSC221 Section R: Software Design Lab
// Professor Wolberg
#include "ControlPanel.h"
#include "mainwindow.h"
#include "Globals.h"
#include "HSL.h"

ControlPanel::ControlPanel(QWidget *parent, Qt::WindowFlags f)
    : QWidget	(parent, f)
{
    createPanelTree();
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(m_tree);
    setLayout(vbox);
}

void
ControlPanel::createPanelTree()
{
    m_tree = new QTreeWidget();
    m_tree->setHeaderHidden(true);      
    m_tree->setColumnCount(1);          
    m_tree->setIndentation(10);         
    m_tree->setAnimated(true);         
    m_tree->setSelectionMode(QAbstractItemView::NoSelection);
    m_tree->setFocusPolicy(Qt::NoFocus);
    m_tree->setFixedWidth(350);
    m_tree->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    m_group.push_back(createGroupInput  ());
    m_group.push_back(createGroupSize   ());
    m_group.push_back(createGroupRender ());
    m_group.push_back(createGroupTile   ());
    m_group.push_back(createGroupGrout  ());

    QFont font("Arial", 12, QFont::Bold);
    QStringList name;
    name    << "Input Settings"
            << "Mosaic Size"
            << "Mosaic Rendering"
            << "Tile Palette"
            << "Grout";

    // create each control panel in tree
    for(int i = 0; i < m_group.size(); i++) {
        // make control panel header and widget
        m_header.push_back(new QTreeWidgetItem(m_tree));
        m_item.push_back  (new QTreeWidgetItem(m_header[i]));

        // make pushbutton to expand/collapse control panel; set its properties
        m_button.push_back(new QPushButton(name[i]));
        m_button[i]->setFixedWidth(300);
        m_button[i]->setFont(font);
        m_button[i]->setFlat(true);
        // set the header item to be a pushbutton
        m_tree->setItemWidget(m_header[i], 0, m_button[i]);
        // set the widget item to be a groupbox
        m_group[i]->setFixedWidth(320);
        m_tree->setItemWidget(m_item[i], 0, m_group[i]);
        // init signal/slot connections to allow
        // expansion/collapse when headers are pressed
        connect(m_button[i], SIGNAL(pressed()),
            this,            SLOT  (expandPanels()));
    }
    m_header[0]->setExpanded(true);
}

QGroupBox*
ControlPanel::createGroupInput()
{
    QGroupBox *groupBox = new QGroupBox;
    // create reset pushbuttons
    for(int i = 0; i < 5; i++)
        m_buttonIn[i] = new QPushButton("Reset");
    // pushbutton for resetting all parameters
    QPushButton *revertOriginal = new QPushButton("Revert to Original");
    // init slider labels
    QLabel      *label[5];
    label[0] = new QLabel("Brightness");
    label[1] = new QLabel("Contrast");
    label[2] = new QLabel("Hue");
    label[3] = new QLabel("Saturation");
    label[4] = new QLabel("Lightness");

    // create brightness/contrast sliders
    for(int i = 0; i < 5; ++i) {
        // create slider and init value
        m_sliderIn[i] = new QSlider(Qt::Horizontal); //create
        m_sliderIn[i]->setValue(0); //initialize
        // set range of slider values
        switch(i) {
            case 0: m_sliderIn[i]->setRange(-128, 128); break; // brightness
            case 1: m_sliderIn[i]->setRange(-100, 100); break; // contrast
            case 2: m_sliderIn[i]->setRange(-180, 180); break; // hue
            case 3: m_sliderIn[i]->setRange(-100, 100); break; // saturation
            case 4: m_sliderIn[i]->setRange(-100, 100); break; //lightness
        }
        // init label for slider value
        m_labelIn[i] = new QLabel(QString("%1").arg(0, 5));
        // set width of reset buttons
        m_buttonIn[i]->setFixedWidth(70);
    }
    // create brightness/contrast widget
    QWidget *bcWidget = new QWidget;
    // asssemble widgets in grid
    QGridLayout *gridBC = new QGridLayout; //grid == gridBC
    gridBC->setColumnMinimumWidth(2, 35);
    for(int i = 0; i < 2; ++i) {
        gridBC->addWidget(label       [i], i, 0);
        gridBC->addWidget(m_sliderIn  [i], i, 1);
        gridBC->addWidget(m_labelIn   [i], i, 2);
        gridBC->addWidget(m_buttonIn  [i], i, 3);
    }
    bcWidget->setLayout(gridBC);
    // create hue/saturation widget
    QWidget *hslWidget = new QWidget;
    // assemble widgets in grid
    QGridLayout *gridHS = new QGridLayout;
    gridHS->setColumnMinimumWidth(2, 35);
    for(int i = 2; i < 5; i++) {
        gridHS->addWidget(label     [i], i, 0);
        gridHS->addWidget(m_sliderIn[i], i, 1);
        gridHS->addWidget(m_labelIn [i], i, 2);
        gridHS->addWidget(m_buttonIn[i], i, 3);
    }
    hslWidget->setLayout(gridHS); //grid2 == gridHS
    // create tab widget
    m_stackWidgetIn = new QStackedWidget;
    // create radio buttons for switching between RGB and HSL
    m_radioIn[0] = new QRadioButton("Brightness-Contrast");
    m_radioIn[0]->setChecked(true);
    m_radioIn[1] = new QRadioButton("Hue-Saturation");
    // create button group and insert the two radio buttons into it
    QButtonGroup *buttonGroupBCHS = new QButtonGroup;
    buttonGroupBCHS->addButton(m_radioIn[0], 0);
    buttonGroupBCHS->addButton(m_radioIn[1], 1);
    // add both radio buttons into a widget having a horizontal layout
    QHBoxLayout *hBoxRadio = new QHBoxLayout;
    hBoxRadio->setContentsMargins(0, 0, 0, 0);
    hBoxRadio->addWidget(m_radioIn[0]);
    hBoxRadio->addWidget(m_radioIn[1]);
    // add radio buttons, stack widget, and revertOriginal pushButton into a vbox layout
    QWidget *w = new QWidget;
    w->setContentsMargins(0, 0, 0 ,0);
    w->setLayout(hBoxRadio);
    QVBoxLayout *vBoxTop = new QVBoxLayout;
    vBoxTop->setContentsMargins(0, 0, 0, 0);
    vBoxTop->addWidget(w);
    vBoxTop->addWidget(m_stackWidgetIn);
    vBoxTop->addWidget(revertOriginal);
    m_stackWidgetIn->addWidget(bcWidget);
    m_stackWidgetIn->addWidget(hslWidget);
    groupBox->setLayout(vBoxTop); //set return value
    // Brightness/Contrast connections
    connect(buttonGroupBCHS,    SIGNAL(buttonClicked   (int)),
            m_stackWidgetIn,    SLOT  (setCurrentIndex (int)));
    connect(m_sliderIn[0],      SIGNAL(valueChanged    (int)),
            this,               SLOT  (changeBrightness(int)));
    connect(m_sliderIn[1],      SIGNAL(valueChanged    (int)),
            this,               SLOT  (changeContrast  (int)));
    connect(m_buttonIn[0],      SIGNAL(clicked            ()),
            this,               SLOT  (resetBrightness    ()));
    connect(m_buttonIn[1],      SIGNAL(clicked            ()),
            this,               SLOT  (resetContrast      ()));
    // Hue/Saturation connections
    connect(m_buttonIn[2], 		SIGNAL(clicked            ()),
            this,          		SLOT  (resetHue           ()));
    connect(m_buttonIn[3], 		SIGNAL(clicked            ()),
            this,          		SLOT  (resetSaturation    ()));
    connect(m_buttonIn[4], 		SIGNAL(clicked            ()),
            this,          		SLOT  (resetLightness     ()));
    connect(m_sliderIn[2], 		SIGNAL(valueChanged    (int)),
            this,          		SLOT  (changeHue       (int)));
    connect(m_sliderIn[3], 		SIGNAL(valueChanged    (int)),
            this,          		SLOT  (changeSaturation(int)));
    connect(m_sliderIn[4], 		SIGNAL(valueChanged    (int)),
            this,          		SLOT  (changeLightness (int)));
    connect(revertOriginal, 	SIGNAL(clicked()),
            this,           	SLOT  (revertOriginal()));
    return groupBox;
}

QGroupBox*
ControlPanel::createGroupSize()
{
    QLabel *label[2];
    for(int i = 0; i < 2; i++) {
        label[i] = new QLabel("Width");
        label[i]->setAlignment(Qt::AlignRight);
    }
    QTextEdit *input[2];
    for(int i = 0; i < 2; i++) {
        input[i] = new QTextEdit;
        input[i]->setFixedHeight(27);
        input[i]->setAlignment(Qt::AlignLeft);
    }
    QGridLayout *grid = new QGridLayout;
    grid->setColumnMinimumWidth(2,35);
    for(int i = 0; i < 2; i++) {
        grid->addWidget(label[i],i,0);
        grid->addWidget(input[i],i,1);
        grid->addWidget(new QLabel("in"),i,2);
    }

    QRadioButton *radioUS = new QRadioButton("US");
    radioUS-> setChecked(true);
    QRadioButton *radioM = new QRadioButton("Metric");
    radioM-> setChecked(false);
    QRadioButton *radioT = new QRadioButton("Tiles");
    radioT-> setChecked(false);

    QButtonGroup *bGroup = new QButtonGroup;
    QVBoxLayout *layoutRadio = new QVBoxLayout;
    layoutRadio->addWidget(radioUS);
    layoutRadio->addWidget(radioM);
    layoutRadio->addWidget(radioT);
    bGroup->addButton(radioUS,0);
    bGroup->addButton(radioM,1);
    bGroup->addButton(radioT,2);
    bGroup->setExclusive(true);

    QHBoxLayout *stacklayout = new QHBoxLayout;
    stacklayout->addLayout(grid);
    stacklayout->addLayout(layoutRadio);
    QGroupBox *groupBox = new QGroupBox;
    groupBox->setLayout(stacklayout);
    return groupBox;
}

QGroupBox*
ControlPanel::createGroupRender()
{
    QGroupBox *groupBox = new QGroupBox;
    QVBoxLayout *vbox   = new QVBoxLayout;
	TesseraParameters &params = g_mainWindow->parameters();
	const QImage &origImage = params.originalImage();
	const QImage &curImage = params.image();
    vbox->addWidget(new QPushButton("Set Output Image"));
    groupBox->setLayout(vbox);
	params.setOutImage(curImage);
    return groupBox;
}

QGroupBox*
ControlPanel::createGroupTile()
{
    QGroupBox *groupBox = new QGroupBox;
    QVBoxLayout *vbox   = new QVBoxLayout;
    vbox->addWidget(new QPushButton("Empty"));
    groupBox->setLayout(vbox);
    return groupBox;
}

QGroupBox*
ControlPanel::createGroupGrout()
{
    QGroupBox *groupBox = new QGroupBox;
    QVBoxLayout *vbox   = new QVBoxLayout;
    vbox->addWidget(new QPushButton("Empty"));
    groupBox->setLayout(vbox);
    return groupBox;
}

void
ControlPanel::expandPanels()
{
    for(int i = 0; i < m_group.size(); i++) {
        if(m_button[i]->isDown()) {
        	if(m_header[i]->isExpanded())
            	m_header[i]->setExpanded(false);
        	else	
				m_header[i]->setExpanded(true);
        }
    }
}

void
ControlPanel::resetBrightness()
{
    changeBrightness(0);
}

void
ControlPanel::resetContrast()
{
    changeContrast(0);
}

void
ControlPanel::resetHue()
{
    changeHue(0);
}

void
ControlPanel::resetSaturation()
{
    changeSaturation(0);
}

void
ControlPanel::resetLightness()
{
    changeLightness(0);
}

void
ControlPanel::changeBrightness(int val)
{
    blockSignals(true);
    m_sliderIn[0]->setValue(val);
    m_labelIn[0] ->setText(QString::number(val));
    g_mainWindow ->parameters().setBrightness(val);
    updateInputImage(TesseraParameters::RGB);
    blockSignals(false);
}

void
ControlPanel::changeContrast(int val)
{
    blockSignals(true);
    m_sliderIn[1]->setValue(val);
    m_labelIn[1] ->setText(QString::number(val));
    g_mainWindow ->parameters().setContrast(val);
    updateInputImage(TesseraParameters::RGB);
    blockSignals(false);
}

void
ControlPanel::changeHue(int val)
{    
    blockSignals(true);
    m_sliderIn[2]->setValue(val);
    m_labelIn[2] ->setText(QString::number(val));
    g_mainWindow ->parameters().setHue(val);
    updateInputImage(TesseraParameters::HSL);
    blockSignals(false);
}

void
ControlPanel::changeSaturation(int val)
{
    blockSignals(true);
    m_sliderIn[3]->setValue(val);
    m_labelIn[3]->setText(QString::number(val));
    g_mainWindow->parameters().setSaturation(val);
    updateInputImage(TesseraParameters::HSL);
    blockSignals(false);
}

void
ControlPanel::changeLightness(int val)
{
    blockSignals(true);
    m_sliderIn[4]->setValue(val);
    m_labelIn[4] ->setText(QString::number(val));
    g_mainWindow ->parameters().setLightness(val);
    updateInputImage(TesseraParameters::HSL);
    blockSignals(false);
}

void
ControlPanel::resetImage()
{
    m_image = QImage();
}

void
ControlPanel::resetControls()
{
    resetInputControls();
}

void
ControlPanel::resetInputControls()
{
    blockSignals(true);
    for(int i = 0; i < 5; ++i) {
        m_sliderIn[i]->setValue(0);
        m_labelIn[i]->setText(QString::number(0));
    }
    resetImage();
    blockSignals(false);
}

void
ControlPanel::revertOriginal()
{
    TesseraParameters &params = g_mainWindow->parameters();
    const QImage &origImage   = params.originalImage();
    const QImage &curImage    = params.image();
    if(origImage.isNull() || curImage.isNull())
        return;
    g_mainWindow->parameters().setBrightness(0);
    g_mainWindow->parameters().setContrast	(0);
    g_mainWindow->parameters().setHue       (0);
    g_mainWindow->parameters().setSaturation(0);
    g_mainWindow->parameters().setLightness	(0);
	g_mainWindow->parameters().setZoomFactor(1);
	
    resetInputControls();
    m_image = origImage;
    params.setImage(m_image);
    g_mainWindow->updateInputFrame();
}

int
ControlPanel::updateInputImage(TesseraParameters::ColorMode mode)
{
	TesseraParameters &params = g_mainWindow->parameters();
	const QImage &origImage = params.originalImage();
	const QImage &curImage = params.image();
	if(origImage.isNull() || curImage.isNull())
		return 0;
	if(m_image.isNull())
		m_image = origImage;
	if(params.colorMode() != mode)
		m_image = curImage;
	params.setColorMode(mode);
	QImage inImage = m_image;
	QImage outImage;
	if(params.colorMode() == TesseraParameters::RGB) {// brightness-contrast
		// get contrast and brightness
		int	contrast	= params.contrast();
		int	brightness	= params.brightness();
		// init slope of intensity ramp
		double	c;
		if(contrast >= 0)
			c = contrast/25. + 1.0;   // slope: 1 to 5
		else	
			c = 1. + (contrast/133.); // slope: 1 to 0
		// init lookup table: multiply by contrast; add brightness
		int lut[256];
		for(int v=0; v<256; v++) {
			int i = (v - 128)*c + (128 + brightness);
			lut[v] = CLIP(i, 0, 255);
		}
		// init input dimensions
		int w = inImage.width ();
		int h = inImage.height();
		// create output image
		outImage = QImage(w, h, QImage::Format_RGB32);
		// apply lookup table to source image to make input image
		for(int y = 0; y < h; y++) {
			const QRgb *src = (const QRgb*) inImage.scanLine(y);
			QRgb *out  = (QRgb*) outImage.scanLine(y);
			for(int x = 0; x < w; x++) {
				// set transparent pixels to white
				if(qAlpha(src[x]) < 128) {
					*out++ = qRgb(255, 255, 255);
				} 
				else {
					*out++ = qRgb(lut[qRed  (src[x])],
						      lut[qGreen(src[x])],
						      lut[qBlue (src[x])]);
				}
			}
		}
	} 
	else {			// hue-saturation
		double h = params.hue()    	  / 180.0;
		double s = params.saturation()/ 100.0;
		double l = params.lightness() / 100.0;
		HSL hsl;
		hsl.setHue	           (HSL::AllHues, h       );
		hsl.setSaturation      (HSL::AllHues, s       );
		hsl.setLightness       (HSL::AllHues, l       );
		hsl.adjustHueSaturation(inImage, 	  outImage);
	}
	params.setImage(outImage);
	g_mainWindow->updateInputFrame();
	return 1;
}
