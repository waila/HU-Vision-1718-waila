#include "StudentLocalization.h"
#include "IntensityImageStudent.h"
#include "Point2D.h"

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
	
	const int BLACK = 240;
	const Intensity BLACKPIXEL = Intensity(255);
	IntensityImageStudent copy = IntensityImageStudent(image.getWidth(), image.getHeight());//volgens mij werkt dit niet

	Feature f = features.getFeature(1);
	int headX = f.getX();
	int headY = f.getY();

	Feature ff = features.getFeature(2);
	int headXx = ff.getX();
	int headYy = ff.getY();

	int centerHeadQuater = (headXx - headX) * 0.25;
	int centerHeadLeftX = headX + centerHeadQuater;
	int headCenterRightY = headXx - centerHeadQuater;


	int pix = 255;

	int indextemp = headY * image.getWidth() + (centerHeadLeftX - 1);
	for (int i = indextemp; i > 0; i = i - image.getWidth()){
		int x = (i % image.getWidth()); //x
		int y = (i / image.getWidth()); //y

		if (image.getPixel(x, y) == 0){
			Point2D<double> leftEyeRectBot(x, y+1);
			Point2D<double> leftEyeRectTop(x- 5, y- 10);
			Feature leftEyeRect(13, leftEyeRectTop);
			leftEyeRect.addPoint(leftEyeRectBot);
			features.putFeature(leftEyeRect);
			break;
		}
	}

	indextemp = headYy * image.getWidth() + (headCenterRightY - 1);
	for (int i = indextemp; i > 0; i = i - image.getWidth()){
		int x2 = (i % image.getWidth()); //x
		int y2 = (i / image.getWidth()); //y

		pix = image.getPixel(x2, y2);
		if (image.getPixel(x2, y2) == 0){
			Point2D<double> rightEyeRectBot(x2, y2+1);
			Point2D<double> rightEyeRectTop(x2 - 5, y2 - 10);
			Feature rightEyeRect(14, rightEyeRectTop);
			rightEyeRect.addPoint(rightEyeRectBot);
			features.putFeature(rightEyeRect);
			break;
		}
	}
	/*
	

	//48 100 148. 48- 148 = -100*-1 = 100 is center. delen door 4 = 25. dus 25 + 48 en 148 - 25 doen.

	int indextemp = f.getY() * copy.getWidth() + f.getX() - 1;
	for (int i = indextemp; i > 0; i = i - copy.getWidth()){
		//reverse x and y to index

		int x = (i / copy.getWidth()); //x
		int y = (i % copy.getWidth()); //y
		if (copy.getPixel(i) == 0){
			break;
			
	*/

	/*
	* 0 1 0 indexes: 1
	* 1 1 1 indexes: 0, 1, 2
	* 0 1 0 indexes: 1

	2,3 = 8

	2(x) * 3(width) = 6 + (y-1)

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
	//copy.ToString();
	return true;
}