#pragma once
class Barrel {

	int volume;
	float procentageOfAlcohol;
	
	/*Constructors*/
	public:

	Barrel();
	Barrel(int volume, float procentageOfAlcohol);

	/*Class methods*/

	int getVolume();
	float getProcentageOfAlcohol();

	void setVolume(int volume);
	void setProcentageOfAlcohol(float procentageOfAlcohol);

	void tranfusion(Barrel& fromWhere, int valueOfTransfusion);  //from this to barrelToTransfuse


};