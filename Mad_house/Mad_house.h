//
// Created by zhivar on 8/25/19.
//

#ifndef AP_TA_EXAM_MAD_HOUSE_H
#define AP_TA_EXAM_MAD_HOUSE_H


#include "vector"
#include <algorithm>
#include <cmath>
#include "../Map_handler/Map_handler.h"

#define HASH_SIGN '#'
#define DEATH_NOTIFICATION ", KIA"
#define BEGINING_STEP 0

#define BREAK_RADIUS_CONDITION 1/3
#define BREAK_SPEED_CONDITION 1/6
#define BREAKING_DEGREE 60
#define PI 3.14159265
#define UNITY_FRIENDS_COUNT_LIMIT 2
#define STRAIGHT_ANGLE 180


class Mad_house {
protected:
    Map* mad_house;
    int time_step;
    int total_time;
    int number_of_steps;
    int current_step;
    std::vector<Kid*>* kids;
    void print_kids_situations();
    void simulate_walls_hits();
    void simulate_kids_hits();
    std::vector<std::vector<Kid*> > find_kids_hits();
    void simulate_all_kids_hits(std::vector<std::vector<Kid *> > collisions);
    std::vector<Kid *> get_kids_copies();
    Kid *find_old_kid(std::vector<Kid *> &old_kids, int id);
    void delete_kids_copies(std::vector<Kid *> &kids_copies);
    void check_kids_union(std::vector<std::vector<Kid *> > hits);
    void check_fragility(std::vector<std::vector<Kid *> > hits);
    void delete_dead_kids();
    bool compare_kid_id();
    int last_id;
    void simulate_kids_move();
    void break_to_six(Kid *kid);
    Kid *make_a_broken_kid_copy(Kid *kid, double vx, double vy);

    void check_kids_death();


public:
    Mad_house(const char* map_address, int _total_time, int _time_step, std::vector<Kid*>* _kids);
    void execute_all_steps();
    void execute_one_step();

};



#endif //AP_TA_EXAM_MAD_HOUSE_H
