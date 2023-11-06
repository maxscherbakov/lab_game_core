#include "map.h"

void Map:: add_building(std:: string loc_name, std:: string loc_item) {
    Area * area = new Building(loc_name, loc_item);
    map.push_back(area);
}

void Map:: add_shop(std:: string loc_name, std:: string loc_item) {
    Area * area = new Shop(loc_name, loc_item);
    map.push_back(area);
}


Area * Map:: search_area(std:: string loc_name) {
    for (int i = 0; i < map.size(); ++i) {
        if (map[i]->loc_name() == loc_name) return map[i];
    }
    return 0;
}

void Map:: go_in() {
    if (player -> in_area()) {std:: cout << "Вы уже внутри.\n";}
    else {
        std:: string item_ = search_area(player -> get_locate()) -> chek_item();
        if (item_ == "") {
        } else if (player -> search_item(item_)) { 
            std:: cout << "Использовал " << item_ << ".\n";
            player -> reset_in_building(1);
        } else {
            std:: cout << "Нужен " << item_ << ".\n";
        }
    }
}

void Map:: go_out() {
    if (player -> in_area()) {
        player -> reset_in_building(0);
        std:: cout << "Вы вышли.\n";
    } else {
        std:: cout << "Вы не в помещении.\n";
    }
}

void Map:: go_to(std:: string loc_name) {
    Area * area = search_area(loc_name);
    Area * area_old = search_area(player -> get_locate());
    if (area_old != 0) {
        area_old -> player_here = 0;
    }

    if (area == 0) { 
        std:: cout << "Нет такого здания.\n"; 
    } else {
        player -> reset_locate(area -> loc_name());
        area -> player_here = 1;
        std:: cout << "Войти внутрь?\n";
    }
}
