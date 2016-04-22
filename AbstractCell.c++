#include "AbstractCell.h"

AbstractCell::AbstractCell() {
	alive = true;
}

bool AbstractCell::isAlive() {
	return alive;
}

void AbstractCell::flip() {
	if (toFlip) {
		toFlip = false;
		alive = !alive;
	}
}