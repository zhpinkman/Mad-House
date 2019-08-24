//
// Created by zhivar on 8/24/19.
//

#ifndef AP_TA_EXAM_KID_H
#define AP_TA_EXAM_KID_H

#include "../Types/Kid_type.h"
#include "../Types/Impact_type.h"

#define MAXIMUM_ANGER 100
#define MINIMUM_RADIUS 0

#define ANGRY "angry"
#define PEACEFUL "Peaceful"
#define COWARD "Coward"
#define BREAK_SUM_LIMIT 20
#define BREAK_DEATH_LIMIT 6
#define PEACEFUL_UNION_COEFFICIENT 5

class Kid {
protected:
    int id;
    Kid_type type;
    bool fragile;
    double posx, posy;
    double vx, vy;
    double radius;
    int anger, charisma, courage;
    bool is_dead;
    virtual void establish_boundaries() {}
    virtual void hit(Kid* other_kid, Kid* some_kid) {}
public:
    Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage);
    int get_id() { return id; }
    Kid_type get_type() { return type; }
    bool is_fragile() { return fragile; }
    double get_posx() { return posx; }
    double get_posy() { return posy; }
    double get_vx() { return vx; }
    double get_vy() { return vy; }
    double get_radius() { return radius; }
    int get_anger() { return anger; }
    int get_charisma() { return charisma; }
    int get_courage() { return courage; }
    void print_kid_situation();
    void move(int time_step);
    void change_speed_by_others_impact(Kid* other_kid);
    int get_next_state_posx(int time_step);
    int get_next_state_posy(int time_step);
    bool has_impact_on_other(Kid* other_kid);
    void generate_impact_on_wall(Impact_type impact_type);
    void check_death();

    void set_vx(double _vx) { vx = _vx; }
    void set_vy(double _vy) { vy = _vy; }

    void die() { is_dead = true; }
    bool check_break_condition(Kid* other_kid);
    void check_peaceful_unity(int num_of_others);

};
#endif //AP_TA_EXAM_KID_H
