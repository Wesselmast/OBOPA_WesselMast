#pragma once
#include "ClassDecorator.h"

class Shaman : public ClassDecorator {
public:
	Shaman(Class* thisClass) {
		curClass = thisClass;
		curClass->name += "shaman!";

	}
};

