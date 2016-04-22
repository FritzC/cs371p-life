#ifndef LIFE_H
#define LIFE_H

#include <vector>
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

template<typename T>
class Life {
	public:
		Life(int width, int height) {
			this->width = width;
			this->height = height;
			generation = 0;
			cells = std::vector<T*>(width * height);
		};
		void step() {
			for (int i = 0; i < width * height; i++) {
				AbstractCell* cell = dynamic_cast<AbstractCell*>(cells.at(i));
				if (cell != nullptr) {
					cell->step(getNeighborCount(i));
				} else {
					//dynamic_cast<Cell*>(cells.at(i))->step();
				}
			}
			for (int i = 0; i < width * height; i++) {
				AbstractCell* cell = dynamic_cast<AbstractCell*>(cells.at(i));
				if (cell != nullptr) {
					cell->flip();
				} else {
					//dynamic_cast<Cell*>(cells.at(i))->step();
				}
			}
			generation++;
		};
		void readInput(char in, int position) {
			T* type = new T();
			AbstractCell* cell = dynamic_cast<AbstractCell*>(type);
			if (cell != nullptr) {
				cell->read(in);
				cells[position] = type;
			} else {
				//dynamic_cast<Cell*>(cells.at(i))->step();
			}
		};
		void print() {
			std::cout << "Generation = " << generation << ", Population = " << getPopulation() << ".";
			for (int i = 0; i < width * height; i++) {
				if (i % width == 0) {
					std::cout << std::endl;
				}
				AbstractCell* cell = dynamic_cast<AbstractCell*>(cells.at(i));
				if (cell != nullptr) {
					cell->print();
				} else {
					//dynamic_cast<Cell*>(cells.at(i))->step();
				}
			}
			std::cout << std::endl;
		};
		int getPopulation() {
			int population = 0;
			for (int i = 0; i < width * height; i++) {
				AbstractCell* cell = dynamic_cast<AbstractCell*>(cells.at(i));
				if (cell != nullptr) {
					if (cell->isAlive()) {
						population++;
					}
				} else {
					//dynamic_cast<Cell*>(cells.at(i))->step();
				}
			}
			return population;
		};
		int getNeighborCount(int position) {
			int cellX = position % width;
			int cellY = position / width;
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
						&& cells.at(checkX + checkY * width)->isAlive()) {
					neighbors++;
				}
			}
			return neighbors;
		}
		T* at(int index) {
			return cells.at(index);
		};
		T* begin() {
			return cells.begin();
		};
		T* end() {
			return cells.end();
		};
	private:
		int width;
		int height;
		int generation;
		std::vector<T*> cells;
};
#endif