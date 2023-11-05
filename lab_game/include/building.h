#ifndef BUILDING_H
#define BUILDING_H
#include "area.h"
#include "enemy.h"

class Building : public Area{
    private:
        std:: vector <Enemy> enemy_in;
    public: 
        Building(std:: string loc_name, std:: string loc_item) 
            : Area(loc_name, loc_item)
        {}
        Enemy * search_enemy(std:: string);
        void interact_with(std:: string, Player *);
        void add(std:: string, int, int, std:: string);
        void scan_Enemy();
        void scan_area();
};

#endif //BUILDING_H