#include <iostream>
#include <string>
using namespace std;

class Reservoir {
private:

	char* name;

	double lenght;
	double width;
	double max_depth;

public:

	Reservoir(const char* nameP, const double lenghtP, const double widthP, const double max_depthP) 
			  :name{ nullptr }, lenght{ lenghtP }, width{ widthP }, max_depth{ max_depthP } {

		if (nameP != nullptr) {

			name = new char[strlen(nameP) + 1];
			for (int i{ 0 }; i <= strlen(nameP); i++)name[i] = nameP[i];

		}
	}

	Reservoir(const char* nameP, const double lenghtP, const double widthP)
			  :Reservoir{ nameP, lenghtP, widthP, 0 } {}

	Reservoir(const char* nameP, const double lenghtP) :Reservoir{ nameP, lenghtP, 0, 0 } {}

	Reservoir(const char* nameP):Reservoir{ nameP, 0, 0, 0 } {}

	Reservoir(const Reservoir& reservior) 
		:Reservoir{ reservior.name, reservior.lenght, reservior.width, reservior.max_depth } {}

	Reservoir() :Reservoir{ nullptr, 0, 0, 0} {}

	~Reservoir() { delete[]this->name; }


	string GetName() { return this->name != nullptr ? this->name : "None information"; }

	double GetLenght() { return this->lenght; }

	double GetWidth() { return this->width; }

	double GetMaxDepth() { return this->max_depth; }

	void CopyInfo(const Reservoir& reservoir) {
		delete[]this->name;
		if (reservoir.name != nullptr) {

			this->name = new char[strlen(reservoir.name) + 1];
			for (int i{ 0 }; i <= strlen(reservoir.name); i++)this->name[i] = reservoir.name[i];

		}
		else this->name = nullptr;

		lenght = reservoir.lenght;
		width = reservoir.width;
		max_depth = reservoir.max_depth;
	}

	
};