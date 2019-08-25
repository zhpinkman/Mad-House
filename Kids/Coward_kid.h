//
// Created by zhivar on 8/24/19.
//

#ifndef AP_TA_EXAM_COWARD_KID_H
#define AP_TA_EXAM_COWARD_KID_H

#include "Kid.h"

#define SURREND_ANGER_CONDITION 70
#define HIT_INC_ANGER_RATE 5
#define ANGER_LIMIT 0
#define CHARISMA_LIMIT 0
#define COURAGE_LIMIT 0

class Coward_kid : public Kid {
protected:
    void establish_boundaries();
    bool check_special_conditions(Kid* other_kid);
public:
    Coward_kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage)
        :Kid(_id, _type, _fragile, _posx, _posy, _vx, _vy, _radius, _anger, _charisma, _courage) {}

    void hit(Kid* other_kid, Kid* updated_other_kid);
};
#endif //AP_TA_EXAM_COWARD_KID_H
