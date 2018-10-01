#pragma once
#include "Class.h"

class ClassDecorator : public Class {
protected:
	Class* curClass;
public:
	void render() {
		curClass->render();
	}
};

