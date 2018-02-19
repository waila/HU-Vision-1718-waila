/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "Image.h"
#include "PixelType.h"

class IntensityImage: public Image {
public:
	IntensityImage();
	IntensityImage(const int width, const int height);
	virtual ~IntensityImage();

	virtual void set(const int width, const int height) = 0;

	virtual void setPixel(int x, int y, Intensity pixel) = 0;
	virtual void setPixel(int i, Intensity pixel) = 0;

	virtual Intensity getPixel(int x, int y) const = 0;
	virtual Intensity getPixel(int i) const = 0;

};