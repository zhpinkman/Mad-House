//
// Created by zhivar on 8/24/19.
//

#ifndef AP_TA_EXAM_PEACEFUL_KID_H
#define AP_TA_EXAM_PEACEFUL_KID_H

#include "Kid.h"

#define TALK_ANGER_CONDITION 70
#define TALK_COURAGE_CONDITION 50
#define UNITY_COURAGE_CONDITION 30
#define UNITY_CHARISMA_CONDITION 50
#define ANGER_LIMIT 30
#define CHARISMA_LIMIT 50
#define COURAGE_LIMIT 30
#define TALK_EFFECT_CONSTANT_1 1
#define TALK_EFFECT_CONSTANT_2 200
#define TALK_EFFECT_CONSTANT_3 0.8
#define TALK_EFFECT_CONSTANT_4 10
#define UNITY_EFFECT_CONSTANTS_1 2
#define UNITY_EFFECT_CONSTANTS_2 2

class Peaceful_kid : public Kid {
protected:
    void establish_boundaries();
    void talk(Kid* other_kid);
    void unity(Kid* other_kid, Kid* updated_other_kid);
    bool check_special_conditions(Kid* other_kid, Kid* updated_other_kid);
public:

    Peaceful_kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage)
    :Kid(_id, _type, _fragile, _posx, _posy, _vx, _vy, _radius, _anger, _charisma, _courage) {}

    void hit(Kid* other_kid, Kid* copy_kid);
};

#endif //AP_TA_EXAM_PEACEFUL_KID_H
