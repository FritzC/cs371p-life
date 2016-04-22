#include "ConwayCell.h"

int ConwayCell::getNeighborCount(int position, std::vector<AbstractCell*> cells, int width, int height) {
	int cellX = position % width;
	int cellY = position / height;
	int neighbors = 0;
	int checkX = 0;
	int checkY = 0;
	for (int i = 0; i < 8; i++) {
		if (i < 3) {
			checkX = cellX + i - 1;
			checkY = cellY - 1;
		} else if (i < 5) {
			checkX = cellX + (i * 2 - 7);
			checkY = cellY;
		} else {
			checkX = cellX + i - 6;
			checkY = cellY + 1;
		}
		if (checkX >= 0 && checkX < width && checkY >= 0 && checkY < height 
				&& cells.at(checkX + checkY * height)->isAlive()) {
			neighbors++;
		}
	}
	return neighbors;
}

void ConwayCell::step(int neighborCount) {
	if (neighborCount < 2 || neighborCount > 3) {
		alive = false;
	} else if (neighborCount == 3) {
		alive = true;
	}
}

void ConwayCell::print() const {
	std::cout << ((alive) ? "*" : ".");
}

int ConwayCell::getCellType() const {
	return CONWAY;
}

ConwayCell* ConwayCell::read(char input) {
	ConwayCell* cell = new ConwayCell();
	if (input == '.') {
		cell->alive = false;
	}
	return cell;
}