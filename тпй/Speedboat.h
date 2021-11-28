#pragma once
#include "Base.h"
class Speedboat :
    public Base
{
private:
	string specification, material, drivingQualities;
	int countPeople;
	double speed;
public:
	Speedboat();
	Speedboat(string specification, string material, string drivingQualities, int countPeople, double speed);
	Speedboat(const Speedboat& speedboat);
	~Speedboat() { cout << "Вызван деструктор Speedboat" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getSpecification() { return specification; }
	void setSpecification(string specification){ this->specification = specification; }

	string getMaterial() { return material; }
	void setMaterial(string material) { this->material = material; }

	string getDrivingQualities() { return drivingQualities; }
	void setDrivingQualities(string drivingQualities) { this->drivingQualities = drivingQualities; }

	int getCountPeople() { return countPeople; }
	void setCountPeople(int countPeople) { this->countPeople = countPeople; }

	double getSpeed() { return speed; }
	void setSpeed(double speed) { this->speed = speed; }
};

