#include "barrel.h"
#include <iostream>



Barrel::Barrel() {

	volume = 0;
	procentageOfAlcohol = 0.0;

}


Barrel::Barrel(int volume,float procentageOfAlcohol) {

	this->volume = volume;
	this->procentageOfAlcohol = procentageOfAlcohol;
}


int Barrel::getVolume() {

	return volume;
}

float Barrel::getProcentageOfAlcohol() {

	return procentageOfAlcohol;

}

void Barrel::setVolume(const int volume) {

	this->volume = volume;

}
void Barrel::setProcentageOfAlcohol(const float procentageOfAlcohol) {

	this->procentageOfAlcohol = procentageOfAlcohol;
}


void Barrel::tranfusion(Barrel& fromWhere, int valueOfTransfusion) {

	fromWhere.volume -= valueOfTransfusion;

	

	procentageOfAlcohol = ((fromWhere.procentageOfAlcohol + volume * procentageOfAlcohol) / (volume + valueOfTransfusion));

	volume += valueOfTransfusion;
	
	
}