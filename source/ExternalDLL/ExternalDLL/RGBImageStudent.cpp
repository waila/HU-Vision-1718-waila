#include "RGBImageStudent.h"
#include <windows.h>

RGBImageStudent::RGBImageStudent() : RGBImage() {
	storage = std::vector<std::vector<RGB> >();
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	storage = other.storage;
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {	
	storage = std::vector<std::vector<RGB> >(); // Initialize storage
}

RGBImageStudent::~RGBImageStudent() {}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	storage = std::vector<std::vector<RGB> >();
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	storage = std::vector<std::vector<RGB> >();
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