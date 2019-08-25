#include <iostream>
#include <cmath>
#include "Input_handler/Input_handler.h"

double newPrecision(double n, int i)
{
    return floor(pow(10,i)*n)/pow(10,i);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "zhivar" << std::endl;
    std::cout << newPrecision(3.453234, 1) << std::endl;
    Input_handler* input_handler = new Input_handler();
    input_handler->read_kids_from_input();
    return 0;
}