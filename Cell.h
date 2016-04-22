#ifndef CELL_H
#define CELL_H

#include <vector>
#include <algorithm>
#include "FredkinCell.h"
#include "ConwayCell.h"

class Cell {
	public:
		void step(int);
		bool isAlive();
		void print();
		int getCellType();
		void flip();
		void read(char);
		Cell() {
			cell = nullptr;
		};
		~Cell() {
			delete cell;
		};
		Cell(const Cell& rhs) {
			if (!rhs.cell) {
				cell = 0;
			} else {
				cell = rhs.cell->clone();
			}
		};
		Cell& operator = (Cell rhs) {
			std::swap(cell, rhs.cell);
			return *this;
		};
	private:
		AbstractCell* cell;
};
#endif