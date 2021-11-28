#include "fabric.h"

Base* createObj(string name)
{
	if (name == "Парусник")
		return new Sailboat();
	if (name == "Катер")
		return new Speedboat();
	if (name == "Подводная лодка")
		return new Submarine();
	string err = "Тип объекта не распознан";
	throw err;
}