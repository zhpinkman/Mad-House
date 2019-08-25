//
// Created by zhivar on 8/25/19.
//

#ifndef AP_TA_EXAM_MAP_HANDLER_H
#define AP_TA_EXAM_MAP_HANDLER_H



#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "../Kids/Kid.h"

#define WALL_CHAR 'b'
#define IMPACT_MARGIN .1
#define WALL_POSITION_BEGINING 1

class Map {
private:
    int map_side_length;
    std::vector<std::string> map_data;
public:
    explicit Map(const char *file_address);

    Hit_type generate_hit_type(double posx, double posy, double radius);
    bool is_point_in_or_on_walls(double posx, double posy);


};


#endif //AP_TA_EXAM_MAP_HANDLER_H
