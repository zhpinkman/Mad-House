//
// Created by zhivar on 8/24/19.
//


#include <iostream>
#include <cmath>
#include "Kid.h"

Kid::Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius,
         int _anger, int _charisma, int _courage) {
    id = _id;
    type = _type;
    fragile = _fragile;
    posx = _posx;
    posy = _posy;
    vx = _vx;
    vy = _vy;
    radius = _radius;
    anger = _anger;
    charisma = _charisma;
    courage = _courage;
    is_dead = false;
}

void Kid::print_kid_situation() {
    std::string type_string;
    switch (type) {
        case Angry:
            type_string = ANGRY;
            break;
        case Coward:
            type_string = COWARD;
            break;
        case Peaceful:
            type_string = PEACEFUL;
            break;
    }
    std::cout << id << ", " << type_string << ", " <<  posx << ", " << posy << ", " << radius << ", " << anger << ", " <<
    charisma << ", " << courage << std::endl;
}

void Kid::move(int time_step) {
    posx = posx + vx * time_step;
    posy = posy + vy * time_step;
}

void Kid::change_speed_by_others_impact(Kid *other_kid) {
    double first_kid_radius_2 = pow(radius, 2);
    double second_kid_radius_2 = pow(other_kid->get_radius(), 2);
    double two_kid_radius_2_sum = first_kid_radius_2 + second_kid_radius_2;
    double first_expression = (first_kid_radius_2 - second_kid_radius_2) / (two_kid_radius_2_sum);
    double second_expression = ((2 * second_kid_radius_2) / two_kid_radius_2_sum);
    vx =  first_expression * vx + second_expression * other_kid->get_vx();
    vy = first_expression * vy + second_expression * other_kid->get_vy();
}

int Kid::get_next_state_posx(int time_step) {
    return posx + vx * time_step;
}

int Kid::get_next_state_posy(int time_step) {
    return posy + vy * time_step;
}

bool Kid::has_impact_on_other(Kid *other_kid) {
    double kids_distance = sqrt( pow(this->posx - other_kid->get_posx(), 2) + pow(this->posy - other_kid->get_posy(), 2) );
    double kids_radiuses_merged = radius + other_kid->get_radius();
    return kids_distance <= kids_radiuses_merged;
}
void Kid::check_death(){
    if ( radius <= MINIMUM_RADIUS || anger >= MAXIMUM_ANGER)
        is_dead = true;
}
