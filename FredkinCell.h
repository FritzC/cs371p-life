#ifndef FREDKINCELL_H
#define FREDKINCELL_H

#include "AbstractCell.h"

class FredkinCell : AbstractCell {
	public:
		int getNeighborCount(int, std::vector<AbstractCell*>, int, int);
		void step(int);
		void print() const;
		int getCellType() const;
		FredkinCell* read(char);
};
#endif