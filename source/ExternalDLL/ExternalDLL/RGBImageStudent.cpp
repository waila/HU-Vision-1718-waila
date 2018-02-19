#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	storage = getEmptyStorage();
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	storage = fillStorage(other.getWidth(), other.getHeight());
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {	
	storage = fillStorage(width, height); // Initialize storage
}

RGBImageStudent::~RGBImageStudent() {}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	storage = fillStorage(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	storage = other.storage;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	storage[x][y] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int x = floor(double(i / getWidth()) * getWidth());
	int y = i - x;

	storage[x][y] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return storage[x][y];
}

RGB RGBImageStudent::getPixel(int i) const {
	int x = floor(double(i / getWidth()) * getWidth());
	int y = i - x;
	
	return storage[x][y];
}

std::vector<std::vector<RGB> > RGBImageStudent::getEmptyStorage()
{
	std::vector<std::vector<RGB> > filledStorage = std::vector<std::vector<RGB > >();
	return filledStorage;
}

std::vector<std::vector<RGB> > RGBImageStudent::fillStorage(const int width, const int height)
{
	std::vector<std::vector<RGB> > filledStorage = std::vector<std::vector<RGB > >();
	const RGB DEFAULT_RGB = RGB(0, 0, 0);
	std::vector<RGB> RGBStorage = std::vector < RGB >();
	for (int j = 0; j < height; ++j)
	{
		RGBStorage.push_back(DEFAULT_RGB);
	}

	for (int i = 0; i < width; ++i) {
		filledStorage.push_back(RGBStorage);
	}

	return filledStorage;
}