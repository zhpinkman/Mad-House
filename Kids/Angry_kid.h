//
// Created by zhivar on 8/24/19.
//

#ifndef AP_TA_EXAM_ANGRY_KID_H
#define AP_TA_EXAM_ANGRY_KID_H

#include "Kid.h"

#define FIGHT_ANGER_CONDITION 70
#define TALK_COURAGE_CONDITION 30
#define TALK_CHARISMA_CONDITION 50
#define ANGER_LIMIT 70
#define CHARISMA_LIMIT 20
#define COURAGE_LIMIT 50
#define FIGHT_EFFECT_CONSTANT_1 0.8
#define FIGHT_EFFECT_CONSTANT_2 5
#define TALK_EFFECT_CONSTANT_1 1
#define TALK_EFFECT_CONSTANT_2 200
#define TALK_EFFECT_CONSTANT_3 0.8

class Angry_kid : public Kid{
protected:
    void establish_boundaries();
    void fight(Kid* other_kid);
    void talk(Kid* other_kid);
    bool check_special_conditions(Kid* other_kid);
public:
    Angry_kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage)
    :Kid(_id, _type, _fragile, _posx, _posy, _vx, _vy, _radius, _anger, _charisma, _courage) {}

    void hit(Kid* other_kid, Kid* updated_other_kid);
};


#endif //AP_TA_EXAM_ANGRY_KID_H
