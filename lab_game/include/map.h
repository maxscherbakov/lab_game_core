#ifndef MAP_H
#define MAP_H
#include "building.h"
#include "shop.h"

struct Map {
    Player * player{0};
    
    void add_building(std:: string, std:: string);

    void add_shop(std:: string, std:: string);
    void go_in();
    void go_out();
    void go_to(std:: string);
    Area * search_area(std:: string);
    ~Map() {
        for (Area * i : map) {
            delete i;
        }
    }

    private:
    std:: vector <Area *> map;
};

#endif // MAP_H