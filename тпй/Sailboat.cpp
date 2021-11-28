#include "Sailboat.h"

Sailboat::Sailboat() : Base("Парусник"), type("Не задано"), name("Не задано"), isMilitary(false), crew(0), lenght(0.0), speed(0.0)
{
	cout << "Вызван конструктор Sailboat" << endl;
}

Sailboat::Sailboat(string type, string name, bool isMilitary, int crew, double lenght, double speed) :
	Base("Парусник"), type(type), name(name), isMilitary(isMilitary), crew(crew), lenght(lenght), speed(speed)
{
	cout << "Вызван конструктор Sailboat" << endl;
}

Sailboat::Sailboat(const Sailboat& sailboat) :
	Base(sailboat), type(sailboat.type), name(sailboat.name), isMilitary(sailboat.isMilitary), 
	crew(sailboat.crew), lenght(sailboat.lenght), speed(sailboat.speed)
{
	cout << "Вызван конструктор копирования Sailboat" << endl;
}

void Sailboat::inputFromConsole()
{
	cout << "Введите тип: ";
	getline(cin, type);
	cout << "Введите название: ";
	getline(cin, name);
	cout << "Военное ли судно?(1/0): ";
	isMilitary = safeInput(0, INT32_MAX);
	cout << "Введите численность экипажа: ";
	crew = safeInput(1, INT32_MAX);
	cout << "Введите длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите скорость: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}

void Sailboat::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	type = tmpS;
	if (!getline(file, tmpS))
		throw err;
	name = tmpS;
	if (!getline(file, tmpS))
		throw err;
	isMilitary = (checkStringToBool(tmpS) ? tmpS[0] - '0' : 0);
	if (!getline(file, tmpS))
		throw err;
	crew = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	lenght = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	speed = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Sailboat::printToConsole()
{
	Base::printToConsole();
	cout << "Тип: " << type << endl;
	cout << "Название: " << name << endl;
	if (isMilitary)
		cout << "Военное" << endl;
	else
		cout << "Мирное" << endl;
	cout << "Численность экапажа: " << crew << endl;
	cout << "Длина корпуса: " << lenght << endl;
	cout << "Сорость: " << speed << endl;
}

void Sailboat::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << type << endl;
	out << name << endl;
	out << isMilitary << endl;
	out << crew << endl;
	out << lenght << endl;
	out << speed << endl;
}

void Sailboat::change()
{
	cout << "Введите ноый тип: ";
	getline(cin, type);
	cout << "Введите новое название: ";
	getline(cin, name);
	cout << "Военное ли судно?(1/0): ";
	isMilitary = safeInput(0, INT32_MAX);
	cout << "Введите новую численность экипажа: ";
	crew = safeInput(1, INT32_MAX);
	cout << "Введите новую длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую скорость: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}