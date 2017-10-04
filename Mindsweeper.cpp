//
// Created by Joe Bekor on 03/10/2017.
//

#include <cstring>
#include "Mindsweeper.h"
Minesweeper::Minesweeper(const size_t width, const size_t height)
        : width(width), height(height) {
    table = new char*[height];
    for (int i = 0; i < height; ++i) {
        table[i] = new char[width];
    }
    copy_table = new char*[height];
    for (int i = 0; i < height; ++i) {
        copy_table[i] = new char[width];
    }
    fillTable();
}


Minesweeper::~Minesweeper() {
    delete[] table;
    delete[] copy_table;
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

void Minesweeper::printPlayerField() const {
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            std::cout << copy_table[i][j] << " ";
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
            copy_table[i][j] = 'H';
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

void Minesweeper::isGameOver(int* x, int* y) {
    if (table[*y][*x] == '*') {
        std::cout << "Game Over";
        exit(0);
    }
}
void Minesweeper::reveal(int* x, int* y) const{
    std::cout << *x << " and " << *y << std::endl;
    if(table[*y][*x] > '0'){
        copy_table[*y][*x] = table[*y][*x];
    } else {
        revealArea(*x, *y);
    }
}

void Minesweeper::revealArea(int x, int y) const{
    copy_table[y][x] = table[y][x];
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if (isFieldRevealAble(x + j, y + i)){
                copy_table[y + i][x + j] = table[y + i][x + j];
                if('0' == table[y + i][x + j]){
                    revealArea(x + j, y + i);
                }
            };
        }
    }
}

bool Minesweeper::isFieldRevealAble(int x, int y) const {
    return !(
            x >= width
            || y >= height
            || x < 0
            || y < 0
            || table[y][x] == '*'
            || copy_table[y][x] != 'H'
    );
}