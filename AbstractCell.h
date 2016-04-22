#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include <vector>
#include <stdlib.h> 
#include <iostream>
#include <string>

class AbstractCell {
	public:
		AbstractCell();
		virtual ~AbstractCell() {};
		bool isAlive();
		virtual void flip();
		virtual void step(int) = 0;
		virtual void print() const = 0;
		virtual void read(char) = 0;
		virtual int getCellType() const = 0;
		virtual AbstractCell* clone() = 0;
		enum CellType {
			CONWAY,
			FREDKIN
		};
	protected:
		bool alive;
		bool toFlip;
};
#endif