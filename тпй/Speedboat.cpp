#include "Speedboat.h"

Speedboat::Speedboat() : Base("�����"), specification("�� ������"), material("�� ������"), drivingQualities("�� ������"), 
countPeople(0), speed(0.0)
{
	cout << "������ ����������� Speedboat" << endl;
}

Speedboat::Speedboat(string specification, string material, string drivingQualities, int countPeople, double speed) :
	Base("�����"), specification(specification), material(material), drivingQualities(drivingQualities), countPeople(countPeople), speed(speed)
{
	cout << "������ ����������� Speedboat" << endl;
}

Speedboat::Speedboat(const Speedboat& speedboat) :
	Base(speedboat), specification(speedboat.specification), material(speedboat.material), 
	drivingQualities(speedboat.drivingQualities), countPeople(speedboat.countPeople), speed(speedboat.speed)
{
	cout << "������ ����������� ����������� Speedboat" << endl;
}

void Speedboat::inputFromConsole()
{
	cout << "������� ����������: ";
	getline(cin, specification);
	cout << "������� �������� �������: ";
	getline(cin, material);
	cout << "������� ������� ��������: ";
	getline(cin, drivingQualities);
	cout << "������� ���������� �����: ";
	countPeople = safeInput(1, INT32_MAX);
	cout << "������� ��������: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}

void Speedboat::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "����������: " << specification << endl;
	cout << "�������� �������: " << material << endl;
	cout << "������� ��������: " << drivingQualities << endl;
	cout << "���������� �����: " << countPeople << endl;
	cout << "��������: " << speed << endl;
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
	cout << "������� ����� ����������: ";
	getline(cin, specification);
	cout << "������� ����� �������� �������: ";
	getline(cin, material);
	cout << "������� ����� ������� ��������: ";
	getline(cin, drivingQualities);
	cout << "������� ����� ���������� �����: ";
	countPeople = safeInput(1, INT32_MAX);
	cout << "������� ����� ��������: ";
	speed = safeInput(1.0, (double)INT32_MAX);
}