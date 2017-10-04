#include <string>
#include "Mindsweeper.h"

const int MAX_WIDTH = 12;
const int MAX_HEIGHT = 10;
void getPlayerInput(int* x, int* y, bool* esc);

int main() {
    try {
        Minesweeper ms(MAX_WIDTH, MAX_HEIGHT);
        ms.printTable();
        ms.countNeighbours();
        ms.printTable();
        ms.printPlayerField();
        bool esc = false;
        int x = -1, y = -1;
        while(!esc) {
            getPlayerInput(&x, &y, &esc);
            if(esc){
                break;
            }
            ms.isGameOver(&x, &y);
            ms.reveal(&x, &y);
            ms.printPlayerField();
            x = -1, y = -1;
        }
    } catch (const std::bad_alloc &e) {
        std::cerr << "Couldn't allocate enough memory for minesweeper table" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

void getPlayerInput(int* x, int* y, bool* esc) {
    std::string next_input = "";
    do{
        if(*x < 0){
            std::cout << "Please chose a coordinate from 0 to MAX_WIDTH"<< std::endl;;
            getline(std::cin, next_input);
            if(std::stoi(next_input) ){
                *x = std::stoi(next_input);
            } else if("0" == next_input){
                *x = 0;
            } else if (next_input != "q"){
                bool esc = true;
            }
        } else {
            std::cout << "Please chose a coordinate from 0 to MAX_Height"<< std::endl;
            getline(std::cin, next_input);
            if(std::stoi(next_input)){
                *y = std::stoi(next_input);
            } else if("0" == next_input){
                *y = 0;
            } else if (next_input != "q"){
                bool esc = true;
            }
        }
    }
    while(!esc || !(*x >= 0 && *y >= 0));
}
