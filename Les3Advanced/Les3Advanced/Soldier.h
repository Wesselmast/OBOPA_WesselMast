#pragma once
#include "ClassDecorator.h"

class Soldier : public ClassDecorator {
public:
	Soldier(Class* thisClass) {
		curClass = thisClass;		
		curClass->name += "soldier!";

	}
};

