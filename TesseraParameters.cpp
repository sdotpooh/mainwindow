#include "TesseraParameters.h"

TesseraParameters::TesseraParameters()
{
	reset();
}

TesseraParameters::TesseraParameters(const TesseraParameters &params)
	: m_origImage	(params.m_origImage),
	  m_image		(params.m_image),
	  m_brightness	(params.m_brightness),
	  m_contrast	(params.m_contrast),
	  m_hue			(params.m_hue),
	  m_saturation	(params.m_saturation),
	  m_lightness	(params.m_lightness),
	  m_colorMode	(params.m_colorMode),
	  m_zoomFactor  (params.m_zoomFactor)
{

}

TesseraParameters&
TesseraParameters::operator=(const TesseraParameters &params)
{
	if(&params == this)
		return *this;

	// input settings
	m_origImage		= params.m_origImage;
	m_image			= params.m_image;
	m_brightness	= params.m_brightness;
	m_contrast		= params.m_contrast;
	m_hue			= params.m_hue;
	m_saturation	= params.m_saturation;
	m_lightness		= params.m_lightness;
	m_colorMode		= params.m_colorMode;
	m_zoomFactor 	= params.m_zoomFactor;

	return *this;
}

void
TesseraParameters::reset()
{
	// input settings
	m_image			= QImage();
	m_origImage		= QImage();
	m_outImage 		= QImage();
	m_outOrigImage 	= QImage();
	m_brightness	= 0;
	m_contrast		= 0;
	m_hue			= 0;
	m_saturation	= 0;
	m_lightness		= 0;
	m_colorMode		= RGB;
	m_zoomFactor 	= 1;
}

void
TesseraParameters::setOriginalImage(const QImage &image)
{
	m_origImage = image;
}

void
TesseraParameters::setImage(const QImage &image)
{
	m_image = image;
}


void
TesseraParameters::setBrightness(int val)
{
	m_brightness = val;
}

void
TesseraParameters::setContrast(int val)
{
	m_contrast = val;
}

void
TesseraParameters::setHue(int val)
{
	m_hue = val;
}

void
TesseraParameters::setSaturation(int val)
{
	m_saturation = val;
}

void
TesseraParameters::setLightness(int val)
{
	m_lightness = val;
}

void
TesseraParameters::setColorMode(ColorMode val)
{
	m_colorMode = val;
}

void
TesseraParameters::setZoomFactor(double val)
{
	m_zoomFactor = val;
}

const QImage&
TesseraParameters::originalImage() const
{
	return m_origImage;
}

const QImage&
TesseraParameters::image() const
{
	return m_image;
}

int
TesseraParameters::brightness() const
{
	return m_brightness;
}

int
TesseraParameters::contrast() const
{
	return m_contrast;
}

int
TesseraParameters::hue() const
{
	return m_hue;
}
// DO SAME FOR saturation(), lightness(), colorMode()
int
TesseraParameters::saturation() const
{
    return m_saturation;
}

int
TesseraParameters::lightness() const
{
    return m_lightness;
}

double
TesseraParameters::zoomFactor() const
{
	return m_zoomFactor;
}

TesseraParameters::ColorMode
TesseraParameters::colorMode() const
{
    return m_colorMode;
}

//Output tab Image
void
TesseraParameters::setOutOriginalImage(const QImage &image)
{
	m_outOrigImage = image;
}

void
TesseraParameters::setOutImage(const QImage &image)
{
	m_outImage = image;
}

const QImage&
TesseraParameters::outOriginalImage() const
{
	return m_outOrigImage;
}

const QImage&
TesseraParameters::outImage() const
{
	return m_outImage;
}
