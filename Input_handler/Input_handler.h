//
// Created by zhivar on 8/24/19.
//

#ifndef AP_TA_EXAM_INPUT_HANDLER_H
#define AP_TA_EXAM_INPUT_HANDLER_H

#include <iostream>
#include <vector>
#include "../Kids/Kid.h"

#define ANGRY "Angry"
#define PEACEFUL "Peaceful"
#define COWARD "Coward"
#define TRUE "true"
#define FALSE "false"


class Input_handler{
protected:
    std::vector<Kid*>* kids;
public:
    std::vector<Kid*>* get_kids() { return kids; }
    void read_kids_from_input();
};

#endif //AP_TA_EXAM_INPUT_HANDLER_H
