//
// Created by Joe Bekor on 03/10/2017.
//

#ifndef CPP_MINESWEEPER_BEKOR_MINDSWEEPER_H
#define CPP_MINESWEEPER_BEKOR_MINDSWEEPER_H

#include <iostream>

class Minesweeper {
public:
    Minesweeper(const size_t width, const size_t height);
    virtual ~Minesweeper();
    /* In a real implementation there would also be a
     * - copy constructor
     * - assignment operator
     * - move constructor
     * - move assignment operator
     * We will learn about them later
     */

    void countNeighbours();
    void printTable() const;
    void printPlayerField() const;
    void reveal(int* x, int* y) const;
    void isGameOver(int* x, int* y);
private:
    void revealArea(int x, int y) const;
    void fillTable();
    void fillItWithZeros();
    bool isFieldCheckable(int x, int y) const;
    void markIt(int x, int y);
    bool isFieldRevealAble(int x, int y) const;

    const size_t width, height;
    char **table;
    char **copy_table;
};
#endif //CPP_MINESWEEPER_BEKOR_MINDSWEEPER_H
