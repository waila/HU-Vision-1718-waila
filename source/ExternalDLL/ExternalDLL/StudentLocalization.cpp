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

	const Feature headLeft = features.getFeature(1);
	const Feature headRight = features.getFeature(2);

	const int headLeftx = headLeft.getX();
	const int headLeftY = headLeft.getY();

	const int headRightx = headLeft.getX();
	const int headRightY = headLeft.getY();

	const double QUARTER = 0.25;
	const int FeatureLeftEye = 13;
	const int FeatureRightEye = 14;

	Feature leftEyeRect; // forward declaration
	Feature rightEyeRect; // forward declaration



	int centerHeadQuater = (headRightx - headLeftx) * 0.25;
	int centerHeadLeftX = headRightx + centerHeadQuater;
	int headCenterRightY = headRightx - centerHeadQuater;
	
	bool found = false;
	for (int currentIndex = headLeftY * image.getWidth() + (centerHeadLeftX); currentIndex > 0; currentIndex -= image.getWidth())
	{
		const int x = (currentIndex % image.getWidth()); //x
		const int y = (currentIndex / image.getHeight()); //y

		if (image.getPixel(x, y) == 0) {
			Point2D<double> leftEyeRectBot(x, y);
			leftEyeRect = Feature(FeatureLeftEye, leftEyeRectBot);
			found = true;
			break;
		}
	}

	if (!found)
	{
		for (int currentIndex = headLeftY * image.getWidth() + (centerHeadLeftX); currentIndex < image.getHeight() * image.getWidth(); currentIndex += image.getWidth())
		{
			const int x = (currentIndex % image.getWidth()); //x
			const int y = (currentIndex / image.getWidth()); //y

			if (image.getPixel(x, y) == 0) {
				Point2D<double> leftEyeRectBot(x, y);
				leftEyeRect = Feature(FeatureLeftEye, leftEyeRectBot);
				break;
			}
		}
	}
	
	found = false;
	for (int currentIndex = headRightY * image.getWidth() + headCenterRightY; currentIndex > 0; currentIndex -= image.getWidth()){
		const int x = (currentIndex / image.getWidth()); //x
		const int y = (currentIndex / image.getHeight()); //y

		if (image.getPixel(x, y) == 0){
			Point2D<double> rightEyeRectBot(x, leftEyeRect.getY());
			rightEyeRect = Feature(FeatureRightEye, rightEyeRectBot);
			found = true;
			break;
		}
	}

	if (!found)
	{
		for (int currentIndex = headRightY * image.getWidth() + headCenterRightY; currentIndex > image.getHeight() * image.getWidth(); currentIndex += image.getWidth()){
			const int x = (currentIndex % image.getWidth()); //x
			const int y = (currentIndex / image.getWidth()); //y

			if (image.getPixel(x, y) == 0){
				Point2D<double> rightEyeRectBot(x, leftEyeRect.getY());
				rightEyeRect = Feature(FeatureRightEye, rightEyeRectBot);
				found = true;
				break;
			}
		}
	}
	
	int eyeRectangleBoxOffset;
	if (rightEyeRect.getX() > leftEyeRect.getX())
		eyeRectangleBoxOffset = ((rightEyeRect.getX() - leftEyeRect.getX()) * 2) / 10;
	else
		eyeRectangleBoxOffset = ((leftEyeRect.getX() - rightEyeRect.getX()) * 2) / 10;

	Point2D<double> leftEyeRectTop(leftEyeRect.getX(), leftEyeRect.getY() + eyeRectangleBoxOffset); 
	leftEyeRect.addPoint(leftEyeRectTop);

	Point2D<double> rightEyeRectTop(rightEyeRect.getX() , rightEyeRect.getY() + eyeRectangleBoxOffset); 
	rightEyeRect.addPoint(rightEyeRectTop);

	features.putFeature(leftEyeRect);
	features.putFeature(rightEyeRect);

	return true;
}