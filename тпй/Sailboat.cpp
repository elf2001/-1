#include "Sailboat.h"

Sailboat::Sailboat() : Base("��������"), type("�� ������"), name("�� ������"), isMilitary(false), crew(0), lenght(0.0), speed(0.0)
{
	cout << "������ ����������� Sailboat" << endl;
}

Sailboat::Sailboat(string type, string name, bool isMilitary, int crew, double lenght, double speed) :
	Base("��������"), type(type), name(name), isMilitary(isMilitary), crew(crew), lenght(lenght), speed(speed)
{
	cout << "������ ����������� Sailboat" << endl;
}

Sailboat::Sailboat(const Sailboat& sailboat) :
	Base(sailboat), type(sailboat.type), name(sailboat.name), isMilitary(sailboat.isMilitary), 
	crew(sailboat.crew), lenght(sailboat.lenght), speed(sailboat.speed)
{
	cout << "������ ����������� ����������� Sailboat" << endl;
}

void Sailboat::inputFromConsole()
{
	cout << "������� ���: ";
	getline(cin, type);
	cout << "������� ��������: ";
	getline(cin, name);
	cout << "������� �� �����?(1/0): ";
	isMilitary = safeInput(0, INT32_MAX);
	cout << "������� ����������� �������: ";
	crew = safeInput(1, INT32_MAX);
	cout << "������� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ��������: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}

void Sailboat::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "���: " << type << endl;
	cout << "��������: " << name << endl;
	if (isMilitary)
		cout << "�������" << endl;
	else
		cout << "������" << endl;
	cout << "����������� �������: " << crew << endl;
	cout << "����� �������: " << lenght << endl;
	cout << "�������: " << speed << endl;
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
	cout << "������� ���� ���: ";
	getline(cin, type);
	cout << "������� ����� ��������: ";
	getline(cin, name);
	cout << "������� �� �����?(1/0): ";
	isMilitary = safeInput(0, INT32_MAX);
	cout << "������� ����� ����������� �������: ";
	crew = safeInput(1, INT32_MAX);
	cout << "������� ����� �����: ";
	lenght = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� ��������: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}