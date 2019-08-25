//
// Created by zhivar on 8/24/19.
//

#include "Input_handler.h"
#include "../Kids/Angry_kid.h"
#include "../Kids/Peaceful_kid.h"
#include "../Kids/Coward_kid.h"

void Input_handler::read_kids_from_input() {
    int id, radius, anger, charisma, courage;
    double posx, posy, vx, vy;
    Kid_type kid_type;
    bool fragile;
    std::string type_string, comma, fragile_string;

    while(std::cin >> id >> comma >> type_string >> fragile_string >> posx >> comma >> posy >> comma >> vx
        >> comma >> vy >> comma >> radius >> comma >> anger >> comma >> charisma >> comma >> courage) {
        type_string = type_string.substr(0, type_string.size() - 1);
        fragile_string = fragile_string.substr(0, fragile_string.size() - 1);
        fragile = (fragile_string == TRUE);

        if (type_string == ANGRY){
            kid_type = Angry;
            Kid* new_kid = new Angry_kid(id, kid_type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage);
            kids.push_back(new_kid);
        }
        else if( type_string == PEACEFUL){
            kid_type = Peaceful;
            Kid* new_kid = new Peaceful_kid(id, kid_type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage);
            kids.push_back(new_kid);
        }
        else if( type_string == COWARD){
            kid_type = Coward;
            Kid* new_kid = new Coward_kid(id, kid_type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage);
            kids.push_back(new_kid);
        }
    }
}