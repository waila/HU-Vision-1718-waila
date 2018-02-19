#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"



IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	/*
	Sauce: https://stackoverflow.com/questions/687261/converting-rgb-to-grayscale-intensity
	*/
	const double RintensityWeight = 0.2989;
	const double GintensityWeight = 0.5870;
	const double BintensityWeight = 0.1140;

	IntensityImageStudent * II = new IntensityImageStudent(image.getWidth(), image.getHeight());

	for (int i = 0; i < image.getWidth(); ++i)
	{
		for (int j = 0; j < image.getHeight(); j++)
		{
			RGB currentPixel = image.getPixel(i, j);
			const int Rintensity = currentPixel.r * RintensityWeight;
			const int Gintensity = currentPixel.g * GintensityWeight;
			const int Bintensity = currentPixel.b * BintensityWeight;

			Intensity currentIntensity(Rintensity + Gintensity + Bintensity);
			II->setPixel(i, j, currentIntensity);
		}
	}
	return II;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}