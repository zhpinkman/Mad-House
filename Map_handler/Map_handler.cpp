//
// Created by zhivar on 8/25/19.
//

#include <cmath>
#include "Map_handler.h"

Map::Map(const char *file_address){
    std::string line;
    std::ifstream my_file (file_address);
    if (my_file.is_open()){
        getline (my_file,line);
        map_side_length = atoi(line.c_str());
        while ( getline (my_file,line) ) {
            map_data.push_back(line);
        }
        my_file.close();
    }else{
        std::cerr << "Unable to open file";
    }
    std::reverse(map_data.begin(), map_data.end());
}

Hit_type Map::generate_hit_type(double posx, double posy, double radius){
    Hit_type impact_type = no_impact;
    radius += IMPACT_MARGIN;
    double margin = radius/sqrt(2);
    if(is_point_in_or_on_walls(posx + margin, posy + margin))
        impact_type = top_right;
    if(is_point_in_or_on_walls(posx + margin, posy - margin))
        impact_type = right_bottom;
    if(is_point_in_or_on_walls(posx - margin, posy + margin))
        impact_type = top_left;
    if(is_point_in_or_on_walls(posx - margin, posy - margin))
        impact_type = left_bottom;

    if(is_point_in_or_on_walls(posx + radius, posy))
        impact_type = right;
    if(is_point_in_or_on_walls(posx, posy - radius))
        impact_type = bottom;
    if(is_point_in_or_on_walls(posx, posy + radius))
        impact_type = top;
    if(is_point_in_or_on_walls(posx - radius, posy))
        impact_type = left;

    if(is_point_in_or_on_walls(posx + radius, posy) && is_point_in_or_on_walls(posx, posy + radius))
        impact_type = top_right;
    if(is_point_in_or_on_walls(posx, posy - radius) && is_point_in_or_on_walls(posx + radius, posy))
        impact_type = right_bottom;
    if(is_point_in_or_on_walls(posx - radius, posy) && is_point_in_or_on_walls(posx, posy + radius))
        impact_type = top_left;
    if(is_point_in_or_on_walls(posx - radius, posy) && is_point_in_or_on_walls(posx, posy - radius))
        impact_type = left_bottom;

    return impact_type;
}

bool Map::is_point_in_or_on_walls(double posx, double posy) {
    if(posx <= WALL_POSITION_BEGINING || posx >= map_side_length || posy <= WALL_POSITION_BEGINING || posy >= map_side_length)
        return true;
    else if (map_data[int(posy)][int(posx)] == WALL_CHAR)
        return true;
    return false;
}
