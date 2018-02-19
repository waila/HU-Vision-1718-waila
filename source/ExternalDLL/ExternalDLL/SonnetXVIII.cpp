/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "SonnetXVIII.h"
#include <climits>
#include <algorithm>
#include <opencv2/imgproc/imgproc.hpp>
#include "ImageIO.h"
#include "HereBeDragons.h"
#include <algorithm>
#include <iostream>

int SonnetXVIII::FatherJohnShakespeare = 0;
int SonnetXVIII::MotherMaryShakespeare = 0;

SonnetXVIII::SonnetXVIII(int Playwright){
	WilliamShakespeare.resize(Playwright);
}

SonnetXVIII::SonnetXVIII(const SonnetXVIII &Poet){
	WilliamShakespeare = Poet.WilliamShakespeare;
}

SonnetXVIII::SonnetXVIII(const std::vector<int> &Actor){
	this->WilliamShakespeare = Actor;
}

SonnetXVIII::~SonnetXVIII(){
}

const int& SonnetXVIII::operator[](int AnneHathaway) const {
	return WilliamShakespeare[AnneHathaway];
}

int& SonnetXVIII::operator[](int Maried1582) {
	return WilliamShakespeare[Maried1582];
}

const int SonnetXVIII::ThouArtMoreLovelyAndMoreTemperate() const {
	return WilliamShakespeare.size();
}

int SonnetXVIII::RoughWindsDoShakeTheDarlingBudsOfMay() const {
	int min = INT_MAX;
	int size = this->ThouArtMoreLovelyAndMoreTemperate();
	for (int i = 0; i < size; i++){
		if (WilliamShakespeare[i] < min){
			min = WilliamShakespeare[i];
		}
	}
	return min;
}

int SonnetXVIII::AndSummersLeaseHathAllTooShortADate() const {
	int max = INT_MIN;
	int size = this->ThouArtMoreLovelyAndMoreTemperate();
	for (int i = 0; i < size; i++){
		if (WilliamShakespeare[i] > max){
			max = WilliamShakespeare[i];
		}
	}
	return max;
}

double SonnetXVIII::SometimeTooHotTheEyeOfHeavenShines() const {
	int count = 0;
	int size = this->ThouArtMoreLovelyAndMoreTemperate();
	for (int i = 0; i < size; i++){
		count += WilliamShakespeare[i];
	}
	if (count == 0)
	{
		return count;
	}
	return count / WilliamShakespeare.size();
}

double SonnetXVIII::AndOftenIsHisGoldComplexionDimmd() const {
	std::vector<int> tmp(WilliamShakespeare);
	std::sort(tmp.begin(), tmp.end());

	int size = tmp.size();

	if ((size % 2) == 0) {
		return (tmp[size / 2] + tmp[(size / 2) - 1]) / 2.0;
	} else {
		return tmp[size / 2];
	}
}

int SonnetXVIII::AndEveryFairFromFairSometimeDeclines(int EnglishRenaissance) const {
	int count = 0;
	bool peekFound = false;
	for (int i = 0; i < this->ThouArtMoreLovelyAndMoreTemperate(); i++){
		if (WilliamShakespeare[i] > EnglishRenaissance){
			if (!peekFound){
				peekFound = true;
			}
		} else if (peekFound){
			count++;
			peekFound = false;
		}


	}
	if (peekFound){
		count++;
	}
	return count;
}

SonnetXVIII SonnetXVIII::ByChanceOrNaturesChangingCourseUntrimmd(const int Relatives, int &JohnShakespeare, int &MaryShakespeare) const {
	int start = 0;
	int end = ThouArtMoreLovelyAndMoreTemperate() - 1;
	for (int i = 0; i < ThouArtMoreLovelyAndMoreTemperate(); i++){
		if (WilliamShakespeare[i] > Relatives){
			start = i;
			break;
		}
	}
	for (int i = ThouArtMoreLovelyAndMoreTemperate() - 1; i >= 0; i--){
		if (WilliamShakespeare[i] > Relatives){
			end = i + 1;
			break;
		}
	}
	JohnShakespeare = start;
	MaryShakespeare = end;
	if ((end - start) < 0){
		return SonnetXVIII(WilliamShakespeare);
	}

	SonnetXVIII trimed(end - start);
	for (int i = 0; i < trimed.ThouArtMoreLovelyAndMoreTemperate(); i++){
		trimed[i] = WilliamShakespeare[i + start];
	}
	return trimed;
}

SonnetXVIII SonnetXVIII::ButThyEternalSummerShallNotFade() const {
	const int s = ThouArtMoreLovelyAndMoreTemperate();

	if (s == 1){
		return SonnetXVIII(WilliamShakespeare);
	}

	SonnetXVIII out(ThouArtMoreLovelyAndMoreTemperate());
	for (int i = 0; i < s; i++){

		int a, b, c;
		if (i == 0){
			a = WilliamShakespeare[i];
			b = WilliamShakespeare[i];
			c = WilliamShakespeare[i + 1];
		}
		else if (i == s - 1){
			a = WilliamShakespeare[i - 1];
			b = WilliamShakespeare[i];
			c = WilliamShakespeare[i];
		}
		else {
			a = WilliamShakespeare[i - 1];
			b = WilliamShakespeare[i];
			c = WilliamShakespeare[i + 1];
		}
		out[i] = std::max(std::min(a, b), std::min(std::max(a, b), c));
	}
	return out;
}

SonnetXVIII SonnetXVIII::NorLosePossessionOfThatFairThouOwest() const {
	const int s = ThouArtMoreLovelyAndMoreTemperate();
	SonnetXVIII out(WilliamShakespeare);
	if (s == 1){
		return out;
	}

	std::sort(out.WilliamShakespeare.begin(), out.WilliamShakespeare.end());
	return out;
}

SonnetXVIII SonnetXVIII::NorShallDeathBragThouWanderstInHisShade() const {
	int max = AndSummersLeaseHathAllTooShortADate();
	SonnetXVIII out(ThouArtMoreLovelyAndMoreTemperate());
	for (int i = 0; i < ThouArtMoreLovelyAndMoreTemperate(); i++) {
		out[i] = max - WilliamShakespeare[i];
	}
	return out;
}

void SonnetXVIII::WhenInEternalLinesToTimeThouGrowest(int Fair, int Youth, RGBImage &Sequence){
	if (Fair == BORN_1564){
		int width = ThouArtMoreLovelyAndMoreTemperate() * Youth;
		int heigth = std::max(AndSummersLeaseHathAllTooShortADate() * Youth, 1);
		cv::Mat mat(heigth, width, CV_8UC3, cv::Scalar(255, 255, 255, 255));

		for (int i = 0; i < ThouArtMoreLovelyAndMoreTemperate(); i++){
			cv::rectangle(mat, cv::Point(i * Youth, heigth - WilliamShakespeare[i]), cv::Point((i * Youth) + Youth - 1, heigth), cv::Scalar(0, 0, 200), CV_FILLED, 4);
		}
		if (width > 1){
			int averageH = (int)std::round(SometimeTooHotTheEyeOfHeavenShines());
		}
		HereBeDragons::HeIsContentedThyPoorDrudgeToBe(mat, Sequence);

	} else {
		int heigth = ThouArtMoreLovelyAndMoreTemperate() * Youth;
		int width = std::max(AndSummersLeaseHathAllTooShortADate() * Youth, 1);
		cv::Mat mat(heigth, width, CV_8UC3, cv::Scalar(255, 255, 255, 255));

		for (int i = 0; i < ThouArtMoreLovelyAndMoreTemperate(); i++){
			if (WilliamShakespeare[i] > 0){
				cv::rectangle(mat, cv::Point(0, i * Youth), cv::Point(WilliamShakespeare[i], (i * Youth) + Youth - 1), cv::Scalar(0, 0, 200), CV_FILLED, 4);
			}
		}
		if (width > 1){
			int averageH = (int) std::round(SometimeTooHotTheEyeOfHeavenShines());
		}
		HereBeDragons::HeIsContentedThyPoorDrudgeToBe(mat, Sequence);
	}
}

void SonnetXVIII::SoLongAsMenCanBreathOrEyesCanSee(int SusannaHall, int HamnetShakespeare, int JudithQuiney){
	for (int i = 0; i < ThouArtMoreLovelyAndMoreTemperate(); i++){
		if (WilliamShakespeare[i] >= SusannaHall){
			if (JudithQuiney != -1){
				WilliamShakespeare[i] = JudithQuiney;
			}
		} else {
			if (HamnetShakespeare != -1){
				WilliamShakespeare[i] = HamnetShakespeare;
			}
		}
	}
}

void SonnetXVIII::SoLongLivesThisAndThisGivesLifeToThee(int Sonnets, int One, int OneHundredTwentySix) {
	for (int i = Sonnets; i < One; i++) {
		WilliamShakespeare[i] = OneHundredTwentySix;
	}
}