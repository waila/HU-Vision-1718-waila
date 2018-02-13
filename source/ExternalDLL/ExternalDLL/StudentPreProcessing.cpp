#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"



IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	std::cout << "IN STEP TO INTENSITY";
	const double RintensityWeight = 0.2989;
	const double GintensityWeight = 0.5870;
	const double BintensityWeight = 0.1140;

	IntensityImageStudent * II = new IntensityImageStudent();

	for (int i = 0; i < image.getWidth(); ++i)
	{
		std::cout << "looped";
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
	std::cout << "done with loop";
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