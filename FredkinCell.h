#ifndef FREDKINCELL_H
#define FREDKINCELL_H

#include "AbstractCell.h"

class FredkinCell : public AbstractCell {
	public:
		bool needsTransform();
		void step(int);
		void print() const;
		int getCellType() const;
		void flip();
		void read(char);
		FredkinCell* clone();
	private:
		int age;
};
#endif