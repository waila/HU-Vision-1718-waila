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

		const int MAX_INDEX = ( image.getWidth() * image.getHeight() ) - 1;
		int x = (currentIndex / image.getWidth()) - 1; //x
		int y = (currentIndex % image.getWidth()) ; //y

		if (image.getPixel(currentIndex) > BLACK)
		{
			/*kernel
			0, 1, 2
			3, 4, 5
			6, 7, 8			*/			
			int pixelMiddle = currentIndex;
			int pixelTop = pixelMiddle - image.getWidth();
			int pixelMiddleLeft = pixelMiddle - 1;
			int pixelMiddleRight = pixelMiddle + 1;
			int pixelBottom = pixelMiddle + image.getWidth();
			

			//bot right
			if (currentIndex == MAX_INDEX) {
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				break;
			}
			//top left
			if (currentIndex == 0){
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);
				continue;
			}

			//top right
			if (currentIndex == image.getWidth() - 1){
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);
				continue;
			}

			//bot left
			if (currentIndex == MAX_INDEX - image.getWidth() + 1){
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
				continue;
			}

			//top
			if (currentIndex - image.getWidth() < 0){
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);
				continue;
			}
			
			//right
			if ((x == image.getWidth())){
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);
				continue;
			}

			//bot
			if (currentIndex + image.getWidth() > MAX_INDEX){
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
				continue;
			}
			//left
			if ((x == 0)){
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);
				continue;
			}

			copy.setPixel(pixelTop, BLACKPIXEL);
			copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
			copy.setPixel(pixelMiddle, BLACKPIXEL);
			copy.setPixel(pixelMiddleRight, BLACKPIXEL);
			copy.setPixel(pixelBottom, BLACKPIXEL);
			
			/*

			//	left top
	//		if (x < 0 && y - 1 < 0 ){
			if (currentIndex - image.getWidth < 0){
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);

				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
			}

			

			// right top
			if (x + 1 > image.getWidth() && y - 1 < 0){
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);
			}

			//bot left
			if (y + 1 > image.getHeight() && x - 1 < 0) {
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
			}
			
			//bot right
			if (currentIndex > MAX_INDEX ) {
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
			}

			if (currentIndex + image.getWidth() < MAX_INDEX ) {
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
			}


			else{
				copy.setPixel(pixelTop, BLACKPIXEL);
				copy.setPixel(pixelMiddleLeft, BLACKPIXEL);
				copy.setPixel(pixelMiddle, BLACKPIXEL);
				copy.setPixel(pixelMiddleRight, BLACKPIXEL);
				copy.setPixel(pixelBottom, BLACKPIXEL);
			}
			*/
		}
	}
	copy.ToString();
	return false;
}