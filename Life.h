#ifndef LIFE_H
#define LIFE_H

#include <vector>
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

template<typename T>
class Life {
	public:
		Life(int, int);
		void step();
		void readInput(char);
		T* at(int);
		T* begin();
		T* end();
	private:
		int width;
		int height;
		int generation;
		std::vector<T*> cells;
};
#endif