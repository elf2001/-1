#include "Submarine.h"

Submarine::Submarine() : Base("��������� �����"), crew(0), lenght(0.0), width(0.0),
maxHourUnderWater(0.0), maxSpeedUnderWater(0.0), maxSpeedAboveWater(0.0)
{
	cout << "������ ����������� Submarine" << endl;
}

Submarine::Submarine(string weapons, int crew, double lenght, double width,
	double maxHourUnderWater, double maxSpeedUnderWater, double maxSpeedAboveWater) :
	Base("��������� �����"), weapons(weapons), crew(crew), lenght(lenght), width(width),
	maxHourUnderWater(maxHourUnderWater), maxSpeedUnderWater(maxSpeedUnderWater), maxSpeedAboveWater(maxSpeedAboveWater)
{
	cout << "������ ����������� Submarine" << endl;
}

Submarine::Submarine(const Submarine& submarine) :
	Base(submarine), weapons(submarine.weapons), crew(submarine.crew), lenght(submarine.lenght), width(submarine.width),
	maxHourUnderWater(submarine.maxHourUnderWater), maxSpeedUnderWater(submarine.maxSpeedUnderWater), maxSpeedAboveWater(submarine.maxSpeedAboveWater)
{
	cout << "������ ����������� ����������� Submarine" << endl;
}

void Submarine::inputFromConsole()
{
	cout << "������� ����������: ";
	getline(cin, weapons);
	cout << "������� ����������� �������: ";
	crew = safeInput(1, INT32_MAX);
	cout << "������� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ������������ ���������� ��� �����: ";
	maxHourUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ������������ ��������� ��������: ";
	maxSpeedUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ������������ ���������� ��������: ";
	maxSpeedAboveWater = safeInput(1.0, (double)INT32_MAX);
}

void Submarine::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "����������: " << weapons << endl;
	cout << "����������� �������: " << crew << endl;
	cout << "�����: " << lenght << endl;
	cout << "������: " << width << endl;
	cout << "����� ������������ ���������� ��� �����: " << maxHourUnderWater << endl;
	cout << "������������ ��������� ��������: " << maxSpeedUnderWater << endl;
	cout << "������������ ���������� ��������: " << maxSpeedAboveWater << endl;
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
	cout << "������� ����� ����������: ";
	getline(cin, weapons);
	cout << "������� ����� ����������� �������: ";
	crew = safeInput(1, INT32_MAX);
	cout << "������� ����� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ������: ";
	width = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ����� ������������ ���������� ��� �����: ";
	maxHourUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ������������ ��������� ��������: ";
	maxSpeedUnderWater = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ������������ ���������� ��������: ";
	maxSpeedAboveWater = safeInput(1.0, (double)INT32_MAX);
}