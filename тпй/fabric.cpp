#include "fabric.h"

Base* createObj(string name)
{
	if (name == "��������")
		return new Sailboat();
	if (name == "�����")
		return new Speedboat();
	if (name == "��������� �����")
		return new Submarine();
	string err = "��� ������� �� ���������";
	throw err;
}