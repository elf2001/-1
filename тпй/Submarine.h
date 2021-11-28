#pragma once
#include "Base.h"
class Submarine :
    public Base
{
private:
    string weapons;
    int crew;
	double lenght, width, maxHourUnderWater, maxSpeedUnderWater, maxSpeedAboveWater;
public:
	Submarine();
	Submarine(string weapons, int crew, double lenght, double width, double maxHourUnderWater, double maxSpeedUnderWater, double maxSpeedAboveWater);
	Submarine(const Submarine& submarine);
	~Submarine() { cout << "Вызван деструктор Submarine" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getWeapons() { return weapons; }
	void setWeapons(string weapons) { this->weapons = weapons; }

	int getCrew() { return crew; }
	void setCrew(int crew) { this->crew = crew; }

	double getLenght() { return lenght; }
	void setLenght(double lenght) { this->lenght = lenght; }

	double getWidth() { return width; }
	void setWidth(double width) { this->width = width; }

	double getMaxHourUnderWater() { return maxHourUnderWater; }
	void setMaxHourUnderWater(double maxHourUnderWater) { this->maxHourUnderWater = maxHourUnderWater; }

	double getMaxSpeedUnderWater() { return maxSpeedUnderWater; }
	void setMaxSpeedUnderWater(double maxSpeedUnderWater) { this->maxSpeedUnderWater = maxSpeedUnderWater; }

	double getMaxSpeedAboveWater() { return maxSpeedAboveWater; }
	void setMaxSpeedAboveWater(double maxSpeedAboveWater) { this->maxSpeedAboveWater = maxSpeedAboveWater; }

};

