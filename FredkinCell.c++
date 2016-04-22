#include "FredkinCell.h"

void FredkinCell::step(int neighborCount) {
	if (alive && neighborCount % 2 == 0) {
		toFlip = true;
	} else if (!alive && neighborCount % 2 == 1) {
		toFlip = true;
	}
}

void FredkinCell::print() const {
	if (alive) {
		if (age < 10) {
			std::cout << age;
		} else {
			std::cout << "+";
		}
	} else {
		std::cout << "-";
	}
}

int FredkinCell::getCellType() const {
	return FREDKIN;
}

void FredkinCell::read(char input) {
	alive = (input != '-');
	age = 0;
}

void FredkinCell::flip() {
	if (toFlip) {
		toFlip = false;
		alive = !alive;
	} else if (alive) {
		age++;
	}
}

FredkinCell* FredkinCell::clone() {
	return new FredkinCell(*this);
}

bool FredkinCell::needsTransform() {
	return age >= 2;
}