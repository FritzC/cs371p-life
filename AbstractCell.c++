#include "AbstractCell.h"

/**
 * Creates a cell
 */
AbstractCell::AbstractCell() {
	alive = true;
	toFlip = false;
}

/**
 * Checks if the cell is alive
 *
 * @return - Whether the cell is alive
 */
bool AbstractCell::isAlive() {
	return alive;
}

/**
 * Flips the alive flag of the cell
 */
void AbstractCell::flip() {
	if (toFlip) {
		toFlip = false;
		alive = !alive;
	}
}