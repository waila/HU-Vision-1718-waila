#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	storage = getEmptyStorage();
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	storage = other.storage;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	storage = fillStorage(width, height); // Initialize storage
}

IntensityImageStudent::~IntensityImageStudent() {
	storage.clear();
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	storage = fillStorage(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	storage = other.storage;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	storage[x][y] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	
	
	int x = floor(double (i / getWidth()) );
	int y = i - (x * getWidth());

	//als 0 is dan niks doen

	std::vector<Intensity> currentPixel = storage.at(0);

	currentPixel[y] = pixel;
	storage[x] = currentPixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return storage[x][y];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int x = floor(double(i / getWidth()));
	int y = i - (x * getWidth());

	return storage[x][y];
}

std::vector<std::vector<Intensity> > IntensityImageStudent::getEmptyStorage()
{
	std::vector<std::vector<Intensity> > filledStorage = std::vector<std::vector<Intensity > >();
	return filledStorage;
}

std::vector<std::vector<Intensity> > IntensityImageStudent::fillStorage(const int width, const int height)
{
	std::vector<std::vector<Intensity> > filledStorage = std::vector<std::vector<Intensity > >();
	const Intensity DEFAULT_INTENSITY = Intensity(0);
	std::vector<Intensity> IntensityStorage = std::vector < Intensity >();
	for (int j = 0; j < height; ++j)
	{
		IntensityStorage.push_back(DEFAULT_INTENSITY);
	}

	for (int i = 0; i < width; ++i) {
		filledStorage.push_back(IntensityStorage);
	}

	return filledStorage;
}