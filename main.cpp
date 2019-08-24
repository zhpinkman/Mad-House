#include <iostream>
#include "Input_handler/Input_handler.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "zhivar" << std::endl;
    Input_handler* input_handler = new Input_handler();
    input_handler->read_kids_from_input();
    return 0;
}