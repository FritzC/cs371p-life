// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <fstream>
#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;

    char c;
    std::ifstream is("RunLife.in");

    // ----------------------
    // Life<ConwayCell> 21x13
    // ----------------------

    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    Life<ConwayCell> first(13, 21);

    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    for (int i = 0; i < 21 * 13; i++) {
        is.get(c);
        if (c == '\n') {
            i--;
            continue;
        }
        first.readInput(c, i);
    }
    cout << endl;
    for (int i = 0; i < 12; i++) {
        first.print();
        first.step();
        cout << endl;
    }
    first.print();
    cout << "\n";

    // ----------------------
    // Life<ConwayCell> 20x29
    // ----------------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    Life<ConwayCell> second(29, 20);

    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    for (int i = 0; i < 29 * 20; i++) {
        is.get(c);
        if (c == '\n') {
            i--;
            continue;
        }
        second.readInput(c, i);
    }
    cout << endl;
    for (int i = 0; i < 28; i++) {
        if (i % 4 == 0) {
            second.print();
        }
        second.step();
        if (i % 4 == 0) {
            cout << endl;
        }
    }
    second.print();
    cout << "\n";

    // -----------------------
    // Life<ConwayCell> 109x69
    // -----------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
    Life<ConwayCell> third(69, 109);

    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */

    for (int i = 0; i < 109 * 69; i++) {
        is.get(c);
        if (c == '\n') {
            i--;
            continue;
        }
        third.readInput(c, i);
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        third.print();
        third.step();
        cout << endl;
    }
    for (int i = 0; i < 273; i++) {
        third.step();
    }
    third.print();
    cout << endl;
    for (int i = 0; i < 40; i++) {
        third.step();
    }
    third.print();
    cout << endl;
    for (int i = 0; i < 2177; i++) {
        third.step();
    }
    third.print();
    cout << "\n";

    // -----------------------
    // Life<FredkinCell> 20x20
    // -----------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    Life<FredkinCell> fourth(20, 20);

    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    for (int i = 0; i < 20 * 20; i++) {
        is.get(c);
        if (c == '\n') {
            i--;
            continue;
        }
        fourth.readInput(c, i);
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        fourth.print();
        fourth.step();
        cout << endl;
    }
    fourth.print();
    cout << "\n";

    // ----------------
    // Life<Cell> 20x20
    // ----------------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    Life<Cell> five(20, 20);
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    for (int i = 0; i < 20 * 20; i++) {
        is.get(c);
        if (c == '\n') {
            i--;
            continue;
        }
        five.readInput(c, i);
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        five.print();
        five.step();
        cout << endl;
    }
    five.print();
    cout << "\n";

    return 0;}