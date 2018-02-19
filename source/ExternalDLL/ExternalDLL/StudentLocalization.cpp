#include "StudentLocalization.h"
#include "IntensityImageStudent.h"

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	
	const int BLACK = 220;
	const Intensity BLACKPIXEL = Intensity(255);
	IntensityImageStudent copy = IntensityImageStudent(image.getWidth(), image.getHeight());

	/*
	* 0 1 0 indexes: 1
	* 1 1 1 indexes: 0, 1, 2
	* 0 1 0 indexes: 1
	*/

	/*
	* RANDVOORWAARDE 1
	* @Brief
	* DetectiePixelIndex - (AantalRijenGehad * image.GetWidth()) > 0
	* 1 X X
	* 1 1 X
	* 1 X X
	*/

	/* RANDVOORWAARDE 2
	* @Brief
	* DetectiePixelIndex + (2 * image.GetWidth()) < image.Getwidth() * image.GetHeight();
	* X 1 X
	* 1 1 1
	* DEZE LIJN VALT WEG
	*/

	for (int currentIndex = 0; currentIndex < image.getWidth() * image.getHeight(); ++currentIndex)
	{
		if (image.getPixel(currentIndex) > BLACK)
		{
			copy.setPixel(currentIndex, BLACKPIXEL); // 0 1 0 TOP PIXEL
			int pixelMiddleLeft = currentIndex + image.getWidth() - 1;
			int pixelMiddle = pixelMiddleLeft + 1;
			int pixelMiddleRight = pixelMiddle + 1;
			int pixelBottom = pixelMiddle + image.getWidth();

			if ()
			copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
			copy.setPixel(pixelMiddle, BLACKPIXEL);
			copy.setPixel(pixelMiddleRight, BLACKPIXEL);
			copy.setPixel(pixelBottom, BLACKPIXEL);
		}
	}

	return false;
}