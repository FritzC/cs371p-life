#include <assert.h>
#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

TEST(LifeFixture, initLife1) {
	Life<ConwayCell> life(10, 99);
	assert(life.width == 10);
}

TEST(LifeFixture, initLife2) {
	Life<ConwayCell> life(10, 99);
	assert(life.height == 99);
}

TEST(LifeFixture, initLife3) {
	Life<ConwayCell> life(0, 0);
	assert(life.width == 0); 
}

TEST(LifeFixture, initLife4) {
	Life<ConwayCell> life(0, 0);
	assert(life.height == 0);
}

TEST(LifeFixture, initLife5) {
	Life<ConwayCell> life(0, 0);
	assert(life.generation == 0);
}

TEST(LifeFixture, stepLife1) {
	Life<ConwayCell> life(2, 2);
	life.readInput('.', 0);
	life.readInput('.', 1);
	life.readInput('.', 2);
	life.readInput('.', 3);
	life.step();
	assert(life.generation == 1);
}

TEST(LifeFixture, stepLife2) {
	Life<ConwayCell> life(2, 2);
	life.readInput('.', 0);
	life.readInput('.', 1);
	life.readInput('.', 2);
	life.readInput('.', 3);
	life.step();
	life.step();
	assert(life.generation == 2);
}

TEST(LifeFixture, stepLife3) {
	Life<ConwayCell> life(2, 2);
	life.readInput('.', 0);
	life.readInput('.', 1);
	life.readInput('.', 2);
	life.readInput('.', 3);
	for (int i = 0; i < 10; i++) {
		life.step();
	}
	assert(life.generation == 10);
}

TEST(LifeFixture, readLife1) {
	Life<ConwayCell> life(2, 2);
	life.readInput('.', 0);
	assert(life.at(0)->getCellType() == AbstractCell::CONWAY && !life.at(0)->isAlive());
}

TEST(LifeFixture, readLife2) {
	Life<ConwayCell> life(2, 2);
	life.readInput('*', 0);
	assert(life.at(0)->getCellType() == AbstractCell::CONWAY && life.at(0)->isAlive());
}

TEST(LifeFixture, readLife3) {
	Life<Cell> life(2, 2);
	life.readInput('*', 1);
	assert(life.at(1)->getCellType() == AbstractCell::CONWAY && life.at(1)->isAlive());
}

TEST(LifeFixture, readLife4) {
	Life<FredkinCell> life(2, 2);
	life.readInput('0', 1);
	assert(life.at(1)->getCellType() == AbstractCell::FREDKIN && life.at(1)->isAlive());
}

TEST(LifeFixture, readLife5) {
	Life<FredkinCell> life(2, 2);
	life.readInput('-', 1);
	assert(life.at(1)->getCellType() == AbstractCell::FREDKIN && !life.at(1)->isAlive());
}

TEST(LifeFixture, population1) {
	Life<ConwayCell> life(2, 2);
	life.readInput('.', 0);
	life.readInput('.', 1);
	life.readInput('.', 2);
	life.readInput('.', 3);
	assert(life.getPopulation() == 0);
}

TEST(LifeFixture, population2) {
	Life<ConwayCell> life(2, 2);
	life.readInput('*', 0);
	life.readInput('.', 1);
	life.readInput('.', 2);
	life.readInput('*', 3);
	assert(life.getPopulation() == 2);
}

TEST(LifeFixture, population3) {
	Life<ConwayCell> life(2, 2);
	life.readInput('*', 0);
	life.readInput('*', 1);
	life.readInput('*', 2);
	life.readInput('*', 3);
	assert(life.getPopulation() == 4);
}

TEST(LifeFixture, population4) {
	Life<FredkinCell> life(2, 2);
	life.readInput('-', 0);
	life.readInput('-', 1);
	life.readInput('-', 2);
	life.readInput('-', 3);
	assert(life.getPopulation() == 0);
}

TEST(LifeFixture, population5) {
	Life<FredkinCell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('-', 1);
	life.readInput('-', 2);
	life.readInput('-', 3);
	assert(life.getPopulation() == 1);
}

TEST(LifeFixture, population6) {
	Life<FredkinCell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('1', 1);
	life.readInput('1', 2);
	life.readInput('1', 3);
	assert(life.getPopulation() == 4);
}

TEST(LifeFixture, population7) {
	Life<Cell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('.', 1);
	life.readInput('-', 2);
	life.readInput('*', 3);
	assert(life.getPopulation() == 2);
}

TEST(LifeFixture, neighborCount1) {
	Life<Cell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('.', 1);
	life.readInput('-', 2);
	life.readInput('*', 3);
	assert(life.getNeighborCount(0) == 0);
}

TEST(LifeFixture, neighborCount2) {
	Life<Cell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('.', 1);
	life.readInput('-', 2);
	life.readInput('*', 3);
	assert(life.getNeighborCount(3) == 1);
}

TEST(LifeFixture, iterator1) {
	Life<Cell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('.', 1);
	life.readInput('-', 2);
	life.readInput('*', 3);
	assert(life.begin() == &life.cells[0]);
}

TEST(LifeFixture, iterator2) {
	Life<Cell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('.', 1);
	life.readInput('-', 2);
	life.readInput('*', 3);
	assert(life.end() == &life.cells[4]);
}

TEST(LifeFixture, iterator3) {
	Life<Cell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('.', 1);
	life.readInput('-', 2);
	life.readInput('*', 3);
	assert(*life.begin() == life.cells[0]);
}

TEST(LifeFixture, iterator4) {
	Life<Cell> life(2, 2);
	life.readInput('1', 0);
	life.readInput('.', 1);
	life.readInput('-', 2);
	life.readInput('*', 3);
	assert(life.begin() + 4 == life.end());
}

TEST(LifeFixture, iterator5) {
	const Life<Cell> life(2, 2);
	assert(life.begin() == &life.cells[0]);
}

TEST(LifeFixture, iterator6) {
	const Life<Cell> life(2, 2);
	assert(life.end() == &life.cells[4]);
}

TEST(LifeFixture, iterator7) {
	const Life<Cell> life(2, 2);
	assert(life.begin() + 1 == &life.cells[1]);
}

TEST(LifeFixture, iterator8) {
	const Life<Cell> life(2, 2);
	assert(life.begin() + 4 == life.end());
}

TEST(LifeFixture, conwayStep1) {
	ConwayCell c;
	c.step(1);
	c.flip();
	assert(!c.isAlive());
}

TEST(LifeFixture, conwayStep2) {
	ConwayCell c;
	c.step(4);
	c.flip();
	assert(!c.isAlive());
}

TEST(LifeFixture, conwayStep3) {
	ConwayCell c;
	c.step(3);
	c.flip();
	assert(c.isAlive());
}

TEST(LifeFixture, conwayType) {
	ConwayCell c;
	assert(c.getCellType() == AbstractCell::CONWAY);
}

TEST(LifeFixture, conwayRead1) {
	ConwayCell c;
	c.read('.');
	assert(!c.isAlive());
}

TEST(LifeFixture, conwayRead2) {
	ConwayCell c;
	c.read('*');
	assert(c.isAlive());
}

TEST(LifeFixture, fredkinStep1) {
	FredkinCell c;
	c.step(1);
	c.flip();
	assert(c.isAlive());
}

TEST(LifeFixture, fredkinStep2) {
	FredkinCell c;
	c.step(4);
	c.flip();
	assert(!c.isAlive());
}

TEST(LifeFixture, fredkinStep3) {
	FredkinCell c;
	c.step(3);
	c.flip();
	assert(c.isAlive());
}

TEST(LifeFixture, fredkinType) {
	FredkinCell c;
	assert(c.getCellType() == AbstractCell::FREDKIN);
}

TEST(LifeFixture, fredkinRead1) {
	FredkinCell c;
	c.read('-');
	assert(!c.isAlive());
}

TEST(LifeFixture, fredkinRead2) {
	FredkinCell c;
	c.read('0');
	assert(c.isAlive());
}

TEST(LifeFixture, fredkinTransform) {
	FredkinCell c;
	c.read('0');
	c.flip();
	c.flip();
	assert(c.needsTransform());
}

TEST(LifeFixture, cellRead1) {
	Cell c;
	c.read('0');
	assert(c.getCellType() == AbstractCell::FREDKIN);
}

TEST(LifeFixture, cellRead2) {
	Cell c;
	c.read('*');
	assert(c.getCellType() == AbstractCell::CONWAY);
}

TEST(LifeFixture, cellRead3) {
	Cell c;
	c.read('0');
	assert(c.isAlive());
}

TEST(LifeFixture, cellRead4) {
	Cell c;
	c.read('*');
	assert(c.isAlive());
}

TEST(LifeFixture, cellRead5) {
	Cell c;
	c.read('-');
	assert(!c.isAlive());
}

TEST(LifeFixture, cellRead6) {
	Cell c;
	c.read('.');
	assert(!c.isAlive());
}