#include "ConwayCell.h"

/**
 * Steps the cell forward one generation
 *
 * @param neighborCount - Number of neighbors the cell has
 */
void ConwayCell::step(int neighborCount) {
	if (alive && (neighborCount < 2 || neighborCount > 3)) {
		toFlip = true;
	} else if (!alive && neighborCount == 3) {
		toFlip = true;
	}
}

/**
 * Prints the cell
 */
void ConwayCell::print() const {
	std::cout << ((alive) ? "*" : ".");
}

/**
 * Gets the cell type
 *
 * @return - Cell type
 */
int ConwayCell::getCellType() const {
	return CONWAY;
}

/**
 * Sets whether the cell is alive based on a char input
 */
void ConwayCell::read(char input) {
	alive = (input != '.');
}

/**
 * Clones the cell
 */
ConwayCell* ConwayCell::clone() {
	return new ConwayCell(*this);
}