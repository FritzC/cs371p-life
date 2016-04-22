#include "Life.h"

/**
 * Constructs a Life
 * @param width - Width of the Life grid
 * @param height - Height of the Life grid
 */
template<typename T>
Life<T>::Life(int width, int height) {
	this->width = width;
	this->height = height;
	generation = 0;
	cells = std::vector<T*>(width * height);
}

/**
 * Steps the Life forward one generation
 */
template<typename T>
void Life<T>::step() {
	for (int i = 0; i < width * height; i++) {
		AbstractCell* cell = dynamic_cast<AbstractCell*>(cells.at(i));
		if (cell != nullptr) {
			cell->step(cell->getNeighborCount(i, cells, width, height));
		} else {
			dynamic_cast<Cell*>(cells.at(i))->step();
		}
	}
	generation++;
}

template<typename T>
void Life<T>::readInput(char in, int position) {
	T type();
	AbstractCell* cell = dynamic_cast<AbstractCell*>(type);
	if (cell != nullptr) {
		cell->step(cell->getNeighborCount(i, cells, width, height));
		cells.assign(cell->readInput(in), position);
	} else {
		//dynamic_cast<Cell*>(cells.at(i))->step();
	}
}

template<typename T>
T* Life<T>::at(int index) {
	return cells.at(index);
}

template<typename T>
T* Life<T>::begin() {
	return cells.begin();
}

template<typename T>
T* Life<T>::end() {
	return cells.end();
}