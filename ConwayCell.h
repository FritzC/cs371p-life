#ifndef CONWAYCELL_H
#define CONWAYCELL_H

#include "AbstractCell.h"

class ConwayCell : public AbstractCell {
	public:
		void step(int);
		void print() const;
		int getCellType() const;
		void read(char);
		ConwayCell* clone();
};
#endif