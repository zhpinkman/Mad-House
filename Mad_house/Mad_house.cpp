//
// Created by zhivar on 8/25/19.
//




#include "Mad_house.h"

Mad_house::Mad_house(const char *map_address, int _total_time, int _time_step, std::vector<Kid *> _kids){
    mad_house = new Map(map_address);
    kids = _kids;
    total_time = _total_time;
    time_step = _time_step;
    number_of_steps = total_time/time_step;
    std::sort(kids.begin(), kids.end());
    last_id = kids.back()->get_id();
    std::cout << "11" << std::endl;
    current_step = BEGINING_STEP;
    print_kids_situations();
    std::cout << "zhivar" << std::endl;
}

void Mad_house::execute_all_steps(){
    for (int i = 0; i <= number_of_steps; i++) {
        std::cout << HASH_SIGN << current_step << std::endl;
        execute_one_step();
        current_step ++;
    }
}

void Mad_house::execute_one_step(){
    print_kids_situations();
    simulate_walls_hits();
    simulate_kids_hits();
    check_kids_death();
    simulate_kids_move();
}

void Mad_house::print_kids_situations() {
    for (int i = 0; i < kids.size(); ++i) {
        kids[i]->print_kid_situation();
    }
}

void Mad_house::simulate_walls_hits() {
    for (int i = 0; i < kids.size(); ++i) {
        double next_state_posx = kids[i]->get_next_state_posx(time_step);
        double next_state_posy = kids[i]->get_next_state_posy(time_step);
        double radius = kids[i]->get_radius();
        Hit_type hit_type = mad_house->generate_hit_type(next_state_posx, next_state_posy, radius);
        kids[i]->hit_to_wall(hit_type);
    }
}

void Mad_house::simulate_kids_hits() {
    std::vector<std::vector<Kid*> > all_hits = find_kids_hits();
    simulate_all_kids_hits(all_hits);
    check_kids_union(all_hits);
    check_fragility(all_hits);

}

std::vector<std::vector<Kid*> > Mad_house::find_kids_hits() {
    std::vector<std::vector<Kid*> > hits;
    for (int i = 0; i < kids.size(); i++) {
        std::vector<Kid*> hits_of_i_th_kid;
        hits.push_back(hits_of_i_th_kid);
        for (int j = 0; j < kids.size(); j++){
            if(kids[i] != kids[j]) {
                if(kids[i]->has_impact_on_other(kids[j])){
                    hits[i].push_back(kids[j]);
                }
            }
        }
    }
    return hits;
}

void Mad_house::simulate_all_kids_hits(std::vector<std::vector<Kid *> > hits){
    std::vector<Kid*> old_kids = get_kids_copies();
    for (int i = 0; i < hits.size(); i++) {
        Kid* kid = kids[i];
        for (int j = 0; j < hits[i].size(); j++) {
            Kid* old_other_kid = find_old_kid( old_kids, hits[i][j]->get_id());
            kid->hit(old_other_kid, hits[i][j]);
        }
    }
    delete_kids_copies(old_kids);
}

std::vector<Kid*> Mad_house::get_kids_copies(){
    std::vector<Kid*> kids_copies(kids);
    for (int i = 0; i < kids_copies.size(); i++) {
        Kid* kid_copy = new Kid(*kids_copies[i]);
        kids_copies[i] = kid_copy;
    }
    return kids_copies;
}

Kid* Mad_house::find_old_kid(std::vector<Kid*> old_kids, int id){
    for (int i = 0; i < old_kids.size(); i++) {
        if(old_kids[i]->get_id() == id)
            return old_kids[i];
    }
    return NULL;
}
void Mad_house::delete_kids_copies(std::vector<Kid*> kids_copies) {
    for (int i = 0; i < kids_copies.size(); ++i) {
        delete(kids_copies[i]);
    }
    kids_copies.clear();
}

void Mad_house::check_kids_union(std::vector<std::vector<Kid *> > hits) {
    for (int i = 0; i < hits.size(); ++i) {
        Kid* kid = kids[i];
        int hits_count = 0;
        if(kid->get_type() == Peaceful) {
            for (int j = 0; j < hits[i].size(); ++j) {
                Kid *other_kid = hits[i][j];
                if (kid->get_type() == Peaceful)
                    hits_count++;
            }
            if(hits_count > UNITY_FRIENDS_COUNT_LIMIT)
                kid->check_peaceful_unity(hits_count);
        }
    }
}

void Mad_house::check_fragility(std::vector<std::vector<Kid *> > hits) {
    std::vector<Kid*> old_kids = get_kids_copies();
    for (int i = 0; i < hits.size(); i++) {
        Kid* kid = kids[i];
        for (int j = 0; j < hits[i].size(); j++){
            Kid* old_other_kid = find_old_kid( old_kids, hits[i][j]->get_id() );
            if( kid->check_break_condition(old_other_kid))
                break_to_six(kid);
        }
    }
    delete_kids_copies(old_kids);
}

void Mad_house::check_kids_death() {
    for (int i = 0; i < kids.size(); i++) {
        kids[i]->check_death();
    }
    delete_dead_kids();
}
void Mad_house::delete_dead_kids() {
    for (int i = 0; i < kids.size(); i++) {
        if(kids[i]->is_dead()){
            std::cout << kids[i]->get_id() << DEATH_COUT << std::endl;
            delete(kids[i]);
            kids.erase(kids.begin() + i);
        }
    }
}

void Mad_house::simulate_kids_move() {
    for (int i = 0; i < kids.size(); i++)
        kids[i]->move(time_step);
}


void Mad_house::break_to_six(Kid *kid) {
    double v_before_breaking = sqrt(pow(kid->get_vx(), 2) + pow(kid->get_vy(), 2));
    double v_after_breaking = v_before_breaking * BREAK_SPEED_CONDITION;
    double first_coefficient = cos(BREAKING_DEGREE * PI/180);
    double second_coefficient = sin(BREAKING_DEGREE * PI/180);
    const std::pair<double,double> coefficients[6] = {std::make_pair(1, 0),
        std::make_pair(-1, 0),
        std::make_pair(first_coefficient, second_coefficient),
        std::make_pair(-first_coefficient, second_coefficient),
        std::make_pair(-first_coefficient, -second_coefficient),
        std::make_pair(first_coefficient, -second_coefficient)};
    for (int i = 0; i < 6; i++) {
       kids.push_back( make_a_broken_kid_copy(kid, v_after_breaking * coefficients[i].first, v_after_breaking * coefficients[i].second));
    }
    kid->die();
}

Kid* Mad_house::make_a_broken_kid_copy(Kid* kid, double vx, double vy){
    double broken_radius = kid->get_radius() * BREAK_RADIUS_CONDITION;
    Kid* new_kid = kid->make_copy();
    last_id ++;
    new_kid->set_id(last_id);
    new_kid->set_vx(vx);
    new_kid->set_vy(vy);
    new_kid->set_radius(broken_radius);
    return new_kid;
}





