#include "Speedboat.h"

Speedboat::Speedboat() : Base("Катер"), specification("Не задано"), material("Не задано"), drivingQualities("Не задано"), 
countPeople(0), speed(0.0)
{
	cout << "Вызван конструктор Speedboat" << endl;
}

Speedboat::Speedboat(string specification, string material, string drivingQualities, int countPeople, double speed) :
	Base("Катер"), specification(specification), material(material), drivingQualities(drivingQualities), countPeople(countPeople), speed(speed)
{
	cout << "Вызван конструктор Speedboat" << endl;
}

Speedboat::Speedboat(const Speedboat& speedboat) :
	Base(speedboat), specification(speedboat.specification), material(speedboat.material), 
	drivingQualities(speedboat.drivingQualities), countPeople(speedboat.countPeople), speed(speedboat.speed)
{
	cout << "Вызван конструктор копирования Speedboat" << endl;
}

void Speedboat::inputFromConsole()
{
	cout << "Введите назначение: ";
	getline(cin, specification);
	cout << "Введите материал корпуса: ";
	getline(cin, material);
	cout << "Введите ходовые качества: ";
	getline(cin, drivingQualities);
	cout << "Введите количество людей: ";
	countPeople = safeInput(1, INT32_MAX);
	cout << "Введите скорость: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}

void Speedboat::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	specification = tmpS;
	if (!getline(file, tmpS))
		throw err;
	material = tmpS;
	if (!getline(file, tmpS))
		throw err;
	drivingQualities = tmpS;
	if (!getline(file, tmpS))
		throw err;
	countPeople = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	speed = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Speedboat::printToConsole()
{
	Base::printToConsole();
	cout << "Назначение: " << specification << endl;
	cout << "Материал корпуса: " << material << endl;
	cout << "Ходовые качества: " << drivingQualities << endl;
	cout << "Количество людей: " << countPeople << endl;
	cout << "Скорость: " << speed << endl;
}

void Speedboat::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << specification << endl;
	out << material << endl;
	out << drivingQualities << endl;
	out << countPeople << endl;
	out << speed << endl;
}

void Speedboat::change()
{
	cout << "Введите новое назначение: ";
	getline(cin, specification);
	cout << "Введите новый материал корпуса: ";
	getline(cin, material);
	cout << "Введите новые ходовые качества: ";
	getline(cin, drivingQualities);
	cout << "Введите новое количество людей: ";
	countPeople = safeInput(1, INT32_MAX);
	cout << "Введите новую скорость: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}