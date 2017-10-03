//
// Created by Joe Bekor on 03/10/2017.
//

#include "Mindsweeper.h"
Minesweeper::Minesweeper(const size_t width, const size_t height)
        : width(width), height(height) {
    table = new char*[height];
    for (int i = 0; i < height; ++i) {
        table[i] = new char[width];
    }
    fillTable();
}


Minesweeper::~Minesweeper() {
    delete[] table;
}

void Minesweeper::countNeighbours() {
    fillItWithZeros();
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j) {
            if (table[i][j] == '*')
                markIt(j,i);
        }
    }
}

void Minesweeper::printTable() const {
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Minesweeper::fillTable() {
    int random = 0;
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            random = rand() % 100;
            table[i][j] =  (random > 80) ? '*' : '.';
        }
    }
}

void Minesweeper::fillItWithZeros() {
    for(int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (table[i][j] != '*')
                table[i][j] = '0';
        }
    }
}

bool Minesweeper::isFieldCheckable(int x, int y) const {
    return !(
            x >= width
            || y >= height
            || x < 0
            || y < 0
            || table[y][x] == '*'
    );
}

void Minesweeper::markIt(int x, int y) {
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if (isFieldCheckable(x + j, y + i)) table[y + i][x + j]++;
        }
    }
}
