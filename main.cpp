#include "Mindsweeper.h"

int main() {
    try {
        Minesweeper ms(12, 10);
        ms.printTable();
        ms.countNeighbours();
        ms.printTable();
    } catch (const std::bad_alloc &e) {
        std::cerr << "Couldn't allocate enough memory for minesweeper table" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}