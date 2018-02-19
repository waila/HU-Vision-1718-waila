/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/
//voor zelf beter als .exe runnen en standard plaatje laten kiezen
//student preprocessing implementeren voor naar gray

#include <iostream> //std::cout
#include "ImageIO.h" //Image load and save functionality
#include "HereBeDragons.h"
#include "ImageFactory.h"
#include "DLLExecution.h"

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features);
bool executeSteps(DLLExecution * executor);

int main(int argc, char * argv[]) {

	//ImageFactory::setImplementation(ImageFactory::DEFAULT);
	ImageFactory::setImplementation(ImageFactory::STUDENT);


	ImageIO::debugFolder = "D:\\Users\\Rolf\\Downloads\\FaceMinMin";
	ImageIO::isInDebugMode = true; //If set to false the ImageIO class will skip any image save function calls




	RGBImage * input = ImageFactory::newRGBImage();
	if (!ImageIO::loadImage("D:\\Users\\Rolf\\Downloads\\TestA5.jpg", *input)) {
		std::cout << "Image could not be loaded!" << std::endl;
		system("pause");
		return 0;
	}


	ImageIO::saveRGBImage(*input, ImageIO::getDebugFileName("debug.png"));

	DLLExecution * executor = new DLLExecution(input);


	if (executeSteps(executor)) {
		std::cout << "Face recognition successful!" << std::endl;
		std::cout << "Facial parameters: " << std::endl;
		for (int i = 0; i < 16; i++) {
			std::cout << (i+1) << ": " << executor->facialParameters[i] << std::endl;
		}
	}

	delete executor;
	system("pause");
	return 1;
}










bool executeSteps(DLLExecution * executor) {

	//Execute the four Pre-processing steps
	if (!executor->executePreProcessingStep1(false)) {  //deze stap op true als we willen testen
		std::cout << "Pre-processing step 1 failed!" << std::endl;
		return false;
	}

	if (!executor->executePreProcessingStep2(false)) {
		std::cout << "Pre-processing step 2 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep2, ImageIO::getDebugFileName("Pre-processing-2.png"));

	if (!executor->executePreProcessingStep3(false)) {
		std::cout << "Pre-processing step 3 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep3, ImageIO::getDebugFileName("Pre-processing-3.png"));

	if (!executor->executePreProcessingStep4(false)) {
		std::cout << "Pre-processing step 4 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep4, ImageIO::getDebugFileName("Pre-processing-4.png"));



	//Execute the localization steps
	if (!executor->prepareLocalization()) {
		std::cout << "Localization preparation failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep1(false)) {
		std::cout << "Localization step 1 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep2(false)) {
		std::cout << "Localization step 2 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep3(false)) {
		std::cout << "Localization step 3 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep4(false)) {
		std::cout << "Localization step 4 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep5(false)) {
		std::cout << "Localization step 5 failed!" << std::endl;
		return false;
	}



	//Execute the extraction steps
	if (!executor->prepareExtraction()) {
		std::cout << "Extraction preparation failed!" << std::endl;
		return false;
	}

	if (!executor->executeExtractionStep1(false)) {
		std::cout << "Extraction step 1 failed!" << std::endl;
		return false;
	}

	if (!executor->executeExtractionStep2(false)) {
		std::cout << "Extraction step 2 failed!" << std::endl;
		return false;
	}

	if (!executor->executeExtractionStep3(false)) {
		std::cout << "Extraction step 3 failed!" << std::endl;
		return false;
	}


	//Post processing and representation
	if (!executor->executePostProcessing()) {
		std::cout << "Post-processing failed!" << std::endl;
		return false;
	}

	drawFeatureDebugImage(*executor->resultPreProcessingStep1, executor->featuresScaled);

	if (!executor->executeRepresentation()) {
		std::cout << "Representation failed!" << std::endl;
		return false;
	}
	return true;
}

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features) {
	RGB colorRed(244, 67, 54);
	RGBImage * debug = ImageFactory::newRGBImage(image.getWidth(), image.getHeight());
	ImageIO::intensityToRGB(image, *debug);

	//Nose
	Point2D<double> noseLeft = features.getFeature(Feature::FEATURE_NOSE_END_LEFT)[0];
	Point2D<double> noseRight = features.getFeature(Feature::FEATURE_NOSE_END_RIGHT)[0];
	Point2D<double> nostrilLeft = features.getFeature(Feature::FEATURE_NOSTRIL_LEFT)[0];
	Point2D<double> nostrilRight = features.getFeature(Feature::FEATURE_NOSTRIL_RIGHT)[0];
	Point2D<double> noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM)[0];


	//These (weird) methods can be used to draw debug points
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseBottom, colorRed);

	//Chin
	std::vector<Point2D<double>> points = features.getFeature(Feature::FEATURE_CHIN_CONTOUR).getPoints();
	for (size_t i = 0; i < points.size(); i++) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, points[i], colorRed);
	}

	//Eye
	Feature leftEye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature rightEye = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);


	//These (weird) methods can be used to draw debug rects
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, leftEye[0], leftEye[1], colorRed);
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, rightEye[0], rightEye[1], colorRed);


	//Head
	Feature headTop = features.getFeature(Feature::FEATURE_HEAD_TOP);
	Feature headLeftNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_MIDDLE);
	Feature headLeftNoseBottom = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM);
	Feature headRightNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_MIDDLE);
	Feature headRightNoseBottom = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headTop[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseBottom[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseBottom[0], colorRed);

	//Mouth
	Point2D<double> mouthTop = features.getFeature(Feature::FEATURE_MOUTH_TOP)[0];
	Point2D<double> mouthBottom = features.getFeature(Feature::FEATURE_MOUTH_BOTTOM)[0];
	Point2D<double> mouthLeft = features.getFeature(Feature::FEATURE_MOUTH_CORNER_LEFT)[0];
	Point2D<double> mouthRight = features.getFeature(Feature::FEATURE_MOUTH_CORNER_RIGHT)[0];

	//This (weird) method can be used to draw a debug line
	HereBeDragons::ButRisingAtThyNameDothPointOutThee(*debug, mouthLeft, mouthRight, colorRed);

	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthTop, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthBottom, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthRight, colorRed);

	ImageIO::saveRGBImage(*debug, ImageIO::getDebugFileName("feature-points-debug.png"));
	delete debug;
}