#ifndef CONWAYCELL_H
#define CONWAYCELL_H

#include "AbstractCell.h"

class ConwayCell : AbstractCell {
	public:
		int getNeighborCount(int, std::vector<AbstractCell*>, int, int);
		void step(int);
		void print() const;
		int getCellType() const;
		ConwayCell* read(char);
};
#endif