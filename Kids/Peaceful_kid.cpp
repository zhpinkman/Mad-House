//
// Created by zhivar on 8/24/19.
//

#include "Peaceful_kid.h"

void Peaceful_kid::establish_boundaries() {
    if (anger > ANGER_LIMIT)
        anger = ANGER_LIMIT;
    if (charisma < CHARISMA_LIMIT)
        charisma = CHARISMA_LIMIT;
    if (courage < COURAGE_LIMIT)
        courage = COURAGE_LIMIT;
}

void Peaceful_kid::hit(Kid *other_kid, Kid *updated_other_kid) {

    if (!check_special_conditions(other_kid, updated_other_kid))
        change_speed_by_others_impact(other_kid);
    establish_boundaries();
    check_death();
}

bool Peaceful_kid::check_special_conditions(Kid *other_kid, Kid* updated_other_kid) {
    if ( other_kid->get_anger() > TALK_ANGER_CONDITION && other_kid->get_courage() > TALK_COURAGE_CONDITION){
        talk(other_kid);
        return true;
    }

    else if ( other_kid->get_courage() > UNITY_COURAGE_CONDITION && other_kid->get_charisma() > UNITY_CHARISMA_CONDITION){
        unity(other_kid, updated_other_kid);
        return true;
    }
    return false;
}

void Peaceful_kid::talk(Kid *other_kid) {
    radius -= TALK_EFFECT_CONSTANT_1 - ((courage + charisma) / TALK_EFFECT_CONSTANT_2)
                                       * TALK_EFFECT_CONSTANT_3 * radius;
    courage -= TALK_EFFECT_CONSTANT_4;
}

void Peaceful_kid::unity(Kid *other_kid, Kid* updated_other_kid) {
    if(updated_other_kid->get_vx() != vx || updated_other_kid->get_vy() != vy){
        vx = ( other_kid->get_vx() + vx ) / 2;
        vy = ( other_kid->get_vy() + vy ) / 2;
        updated_other_kid->set_vx(vx);
        updated_other_kid->set_vy(vy);
    }
    charisma += UNITY_EFFECT_CONSTANTS_1;
    courage += UNITY_EFFECT_CONSTANTS_2;
}
