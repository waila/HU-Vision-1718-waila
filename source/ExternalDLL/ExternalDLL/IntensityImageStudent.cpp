#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	storage = std::vector<std::vector<Intensity> >();
	std::cout << "DICKS OUT FOR HARAMBE";
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	storage = other.storage;
	std::cout << "DICKS OUT FOR HARAMBE";
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	//TODO: Initialize pixel storage
	//storage = std::vector<std::vector<Intensity> >(); //we gebruiken vector dus hoef niet?
	std::cout << "DICKS OUT FOR HARAMBE";
}

IntensityImageStudent::~IntensityImageStudent() {
	storage.clear();
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImageStudent::set(width, height);
	storage = std::vector<std::vector<Intensity> >();
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImageStudent::set(other.getWidth(), other.getHeight());
	//storage = std::vector<std::vector<Intensity> >();
	storage = other.storage;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	storage[x][y] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int x = floor(double(i / getWidth()) * getWidth());
	int y = i - x;

	storage[x][y] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return storage[x][y];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int x = floor(double(i / getWidth()) * getWidth());
	int y = i - x;

	return storage[x][y];
}