#include "Input_handler/Input_handler.h"
#include "Mad_house/Mad_house.h"
#define MAP_ADDRESS "map.dat"



int main(int argc, char** argv) {
    int time_step = atoi(argv[1]);
    int total_time = atoi(argv[2]);
    Input_handler* input_handler = new Input_handler();
    input_handler->read_kids_from_input();
    std::cout << "test" << std::endl;
    std::vector<Kid*> kids = input_handler->get_kids();
    std::cout << "negar" << std::endl;
    Mad_house mad_house(MAP_ADDRESS, time_step, total_time, kids);
    std::cout << "sasan" << std::endl;
    mad_house.execute_all_steps();
    return 0;
}