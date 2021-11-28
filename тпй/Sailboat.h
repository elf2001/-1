#pragma once
#include "Base.h"

class Sailboat :
    public Base
{
private:
	string type, name;
	bool isMilitary;
	int crew;
	double lenght, speed;
public:
	Sailboat();
	Sailboat(string type, string name, bool isMilitary, int crew, double lenght, double speed);
	Sailboat(const Sailboat& sailboat);
	~Sailboat() { cout << "Вызван деструктор Sailboat" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getType() { return type; }
	void setType(string type) { this->type = type; }

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	bool getIsMilitary() { return isMilitary; }
	void setIsMilitary(bool isMilitary) { this->isMilitary = isMilitary; }

	int getCrew() { return crew; }
	void setCrew(int crew) { this->crew = crew; }

	double getLenght() { return lenght; }
	void setLenght(double lenght) { this->lenght = lenght; }

	double getSpeed() { return speed; }
	void setSpeed(double speed) { this->speed = speed; }
};

