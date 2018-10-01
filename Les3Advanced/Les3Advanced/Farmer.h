#pragma once
#include "ClassDecorator.h"

class Farmer : public ClassDecorator {
public:
	Farmer(Class* thisClass) {
		curClass = thisClass;
		curClass->name += "farmer!";
	}
};
