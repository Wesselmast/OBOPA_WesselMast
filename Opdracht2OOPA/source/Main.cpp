#include "RuleBook.h"
#include <iostream>
#include <time.h>

int sleepTime = 1000;
int resolution = 50;

int main() {
	srand(time(0));

	/*
	Base for the base game of life rules
	TimeSpeedUp for a game that keeps on speeding up
	AntHill for a cavern-like structure you'd find in an ant hill
	*/
	Rule rule = TimeSpeedUp;

	switch (rule) {
	case Base: BaseRule(sleepTime, resolution); break;
	case TimeSpeedUp: SpeedUpRule(sleepTime, resolution); break;
	case AntHill: AntHillRule(sleepTime, resolution); break;
	}

	std::cin.get();
	return 0;
}