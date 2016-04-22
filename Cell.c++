#include "Cell.h"

/**
 * Steps forward a generation
 *
 * @param neighbors - Number of neighbors the cell has
 */
void Cell::step(int neighbors) {
	cell->step(neighbors);
}

/**
 * Gets the type of cell
 *
 * @return - Type of cell
 */
int Cell::getCellType() {
	return cell->getCellType();
}

/*
 * Prints the cell
 */
void Cell::print() {
	cell->print();
}

/*
 * Transforms the cell at the end of the turn if necessary
 */
void Cell::flip() {
	cell->flip();
	if (getCellType() == AbstractCell::FREDKIN
			&& dynamic_cast<FredkinCell*>(cell)->needsTransform()) {
		read('*');
	}
}

/*
 * Checks if the cell is still alive
 */
bool Cell::isAlive() {
	return cell->isAlive();
}

/*
 * Reads in a character and assigns the cell type accordingly
 */
void Cell::read(char in) {
	if (in == '*' || in == '.') {
		cell = new ConwayCell();
	} else {
		cell = new FredkinCell();
	}
	cell->read(in);
}