#include "ConwayCell.h"

void ConwayCell::step(int neighborCount) {
	if (alive && (neighborCount < 2 || neighborCount > 3)) {
		toFlip = true;
	} else if (!alive && neighborCount == 3) {
		toFlip = true;
	}
}

void ConwayCell::print() const {
	std::cout << ((alive) ? "*" : ".");
}

int ConwayCell::getCellType() const {
	return CONWAY;
}

void ConwayCell::read(char input) {
	alive = (input != '.');
	/*ConwayCell* cell = new ConwayCell();
	if (input == '.') {
		cell->alive = false;
	}
	return cell;*/
}

ConwayCell* ConwayCell::clone() {
	return new ConwayCell(*this);
}