#include "AbstractCell.h"

AbstractCell::AbstractCell() {
	alive = true;
}

bool AbstractCell::isAlive() {
	return alive;
}