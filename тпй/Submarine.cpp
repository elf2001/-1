#include "Submarine.h"

Submarine::Submarine() : Base("Подводная лодка"), crew(0), lenght(0.0), width(0.0),
maxHourUnderWater(0.0), maxSpeedUnderWater(0.0), maxSpeedAboveWater(0.0)
{
	cout << "Вызван конструктор Submarine" << endl;
}

Submarine::Submarine(string weapons, int crew, double lenght, double width,
	double maxHourUnderWater, double maxSpeedUnderWater, double maxSpeedAboveWater) :
	Base("Подводная лодка"), weapons(weapons), crew(crew), lenght(lenght), width(width),
	maxHourUnderWater(maxHourUnderWater), maxSpeedUnderWater(maxSpeedUnderWater), maxSpeedAboveWater(maxSpeedAboveWater)
{
	cout << "Вызван конструктор Submarine" << endl;
}

Submarine::Submarine(const Submarine& submarine) :
	Base(submarine), weapons(submarine.weapons), crew(submarine.crew), lenght(submarine.lenght), width(submarine.width),
	maxHourUnderWater(submarine.maxHourUnderWater), maxSpeedUnderWater(submarine.maxSpeedUnderWater), maxSpeedAboveWater(submarine.maxSpeedAboveWater)
{
	cout << "Вызван конструктор копирования Submarine" << endl;
}

void Submarine::inputFromConsole()
{
	cout << "Введите вооружение: ";
	getline(cin, weapons);
	cout << "Введите численность экипажа: ";
	crew = safeInput(1, INT32_MAX);
	cout << "Введите длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите ширину: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите время непрерывного пребывания под водой: ";
	maxHourUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите максимальную подводную скорость: ";
	maxSpeedUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите максимальную наддводную скорость: ";
	maxSpeedAboveWater = safeInput(1.0, (double)INT32_MAX);
}

void Submarine::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	weapons = tmpS;
	if (!getline(file, tmpS))
		throw err;
	crew = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	lenght = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	width = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	maxHourUnderWater = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	maxSpeedUnderWater = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	maxSpeedAboveWater = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Submarine::printToConsole()
{
	Base::printToConsole();
	cout << "Вооружение: " << weapons << endl;
	cout << "Численность экипажа: " << crew << endl;
	cout << "Длина: " << lenght << endl;
	cout << "Ширина: " << width << endl;
	cout << "Время непрерывного пребывания под водой: " << maxHourUnderWater << endl;
	cout << "Максимальная подводная скорость: " << maxSpeedUnderWater << endl;
	cout << "Максимальная наддводная скорость: " << maxSpeedAboveWater << endl;
}

void Submarine::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << weapons << endl;
	out << crew << endl;
	out << lenght << endl;
	out << width << endl;
	out << maxHourUnderWater << endl;
	out << maxSpeedUnderWater << endl;
	out << maxSpeedAboveWater << endl;
}

void Submarine::change()
{
	cout << "Введите новое вооружение: ";
	getline(cin, weapons);
	cout << "Введите новую численность экипажа: ";
	crew = safeInput(1, INT32_MAX);
	cout << "Введите новую длину: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую ширину: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новое время непрерывного пребывания под водой: ";
	maxHourUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую максимальную подводную скорость: ";
	maxSpeedUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "Введите новую максимальную наддводную скорость: ";
	maxSpeedAboveWater = safeInput(1.0, (double)INT32_MAX);
}