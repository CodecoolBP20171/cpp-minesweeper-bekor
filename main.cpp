#include <iostream>

namespace {
    class Minesweeper {
    public:
        Minesweeper(const size_t width, const size_t height)
                : width(width), height(height),
                  table(new char[width * height]) {
            fillTable();
        }

        /* In a real implementation there would also be a
         * - copy constructor
         * - assignment operator
         * - move constructor
         * - move assignment operator
         * We will learn about them later
         */

        virtual ~Minesweeper() {
            delete[] table;
        }

        void countNeighbours() {
        }

        void printTable() const {
            for(int i = 0; i < height; ++i){
                for(int j = 0; j < width; ++j){
                    std::cout << table[(i*width) + j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

    private:
        void fillTable() {
            int random = 0;
            for(int i = 0; i < height; ++i){
                for(int j = 0; j < width; ++j){
                    random = rand() % 100;
                    *(table+ (i*width) + j) = (random > 80) ? '*' : '.';
                }
            }
        }

        const size_t width, height;
        char *table;
    };
}

int main() {
    try {
        Minesweeper ms(10, 5);
        ms.printTable();
        ms.countNeighbours();
        ms.printTable();
    } catch (const std::bad_alloc &e) {
        std::cerr << "Couldn't allocate enough memory for minesweeper table" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}