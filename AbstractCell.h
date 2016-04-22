#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include <vector>
#include <stdlib.h> 
#include <iostream>
#include <string>

class AbstractCell {
	public:
		AbstractCell();
		bool isAlive();
		virtual int getNeighborCount(int, std::vector<AbstractCell*>, int, int) = 0;
		virtual void step(int) = 0;
		virtual void print() const = 0;
		virtual int getCellType() const = 0;
		virtual AbstractCell* read(char) = 0;
		enum CellType {
			CONWAY,
			FREDKIN
		};
	protected:
		bool alive;
};
#endif