//
// Created by zhivar on 8/24/19.
//


#include "Coward_kid.h"

void Coward_kid::establish_boundaries(){
    if (anger < ANGER_LIMIT)
        anger = ANGER_LIMIT;
    if (charisma != CHARISMA_LIMIT)
        charisma = CHARISMA_LIMIT;
    if (courage != COURAGE_LIMIT)
        courage = COURAGE_LIMIT;
}


void Coward_kid::hit(Kid *other_kid, Kid *updated_other_kid) {

    if (!check_special_conditions(other_kid))
        change_speed_by_others_impact(other_kid);
    establish_boundaries();
    check_death();
}

bool Coward_kid::check_special_conditions(Kid *other_kid) {
    anger += HIT_INC_ANGER_RATE;
    if ( other_kid->get_anger() > SURREND_ANGER_CONDITION ){
        die();
        return true;
    }
    return false;
}