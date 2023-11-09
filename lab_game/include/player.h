#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "man.h"

class Player : public man {
    protected:
        int energy{100};
        bool in_building{0};
        bool in_fight{0};
        std:: vector <std:: string> items;
    public: 
        virtual ~Player(){};
        virtual void to_train() = 0;
        virtual void to_study() = 0;
        virtual void to_relax() = 0;
        virtual void use_ability() = 0;
        void check_inventory();
        bool search_item(std:: string item_);
        bool in_area() { return in_building; }
        bool get_in_fight() { return in_fight; }
        void reset_in_fight(bool t) { in_fight = t; }
        void reset_in_building(bool t) { in_building = t; }
        int get_energy() { return energy; }
        void add_item (std:: string item_) { items.push_back(item_); }
};


#endif // PLAYER_H