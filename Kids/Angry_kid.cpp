//
// Created by zhivar on 8/24/19.
//

#include "Angry_kid.h"

void Angry_kid::establish_boundaries() {
    if (anger < ANGER_LIMIT)
        anger = ANGER_LIMIT;
    if (charisma != CHARISMA_LIMIT)
        charisma = CHARISMA_LIMIT;
    if (courage < COURAGE_LIMIT)
        courage = COURAGE_LIMIT;
}


void Angry_kid::hit(Kid *other_kid, Kid *copy_kid) {

    if (!check_special_conditions(other_kid))
        this->change_speed_by_others_impact(other_kid);
    establish_boundaries();
    check_death();
}

bool Angry_kid::check_special_conditions(Kid* other_kid){
    if ( other_kid->get_anger() > FIGHT_ANGER_CONDITION ){
        fight(other_kid);
        return true;
    }

    else if ( other_kid->get_courage() > TALK_COURAGE_CONDITION && other_kid->get_charisma() > TALK_CHARISMA_CONDITION ){
        talk(other_kid);
        return true;
    }
    return false;

}

void Angry_kid::fight(Kid *other_kid) {
    if ( radius < other_kid->get_radius() ){
        radius *= FIGHT_EFFECT_CONSTANT_1;
        anger += FIGHT_EFFECT_CONSTANT_2;
    }
}

void Angry_kid::talk(Kid *other_kid) {
    radius += TALK_EFFECT_CONSTANT_1 - ((other_kid->get_courage() + other_kid->get_charisma()) / TALK_EFFECT_CONSTANT_2)
            * TALK_EFFECT_CONSTANT_3 * other_kid->get_radius();
}