#include <iostream>
#include "map.h"
#include "students.h"



void Area:: scan_area() {
    std:: cout << "Вы видите " << loc_name() <<".\n";
}



Enemy * Build:: search_enemy(std:: string enemy_name) {
    for (int i = 0; i < enemy_in.size(); ++i) {
        if (enemy_in[i].get_name() == enemy_name) return &enemy_in[i];
    }
    return 0;
}

void Build:: add_npc_in(std:: string NPCname, char NPCrole) {
    NPC new_npc(NPCname, NPCrole);
    new_npc.reset_locate(locate_name);
    npc_in.push_back(new_npc);
}  

void Build:: add_npc_out(std:: string NPCname, char NPCrole) {
    NPC new_npc(NPCname, NPCrole);
    new_npc.reset_locate(locate_name);
    npc_out.push_back(new_npc);
}  

void Build:: add_enemy(std:: string enemyname, int iq_, int power_, std:: string item) {
    Enemy new_enemy(enemyname, iq_, power_, item);
    enemy_in.push_back(new_enemy);
}

void Build:: scan_npc() {
    std:: cout << "NPC внутри: ";
    for (auto i : npc_in) {
        std:: cout << i.get_name() << "; ";
    }
    std:: cout << "\nNPC снаружи: ";
    for (auto i : npc_out) {
        std:: cout << i.get_name()<< "; ";
    }
    std:: cout << '\n';
}

void Build:: scan_Enemy() {
    std:: cout << "Enemy: ";
    for (auto i : enemy_in) {
        if (i.alive) std:: cout << i.get_name()<< "(iq: " << i.get_iq() << ", power: " << i.get_power() <<\
         ", helth: " << i.get_helth() <<"); ";
    }
    std:: cout << '\n';
}

void Build:: scan_area() {
    std:: cout << "Вы видите " << loc_name() <<".\n";
    scan_npc();
    scan_Enemy();
}




void Shop:: buy_item(std:: string item_, Player * player) {
    if (player_here and player -> in_area()) {
    for (auto i : shop_list) {
        if (i == item_) {
            std:: cout << "Вы купили " << item_ << ".\n";
            player -> add_item(item_);
            return;
        }
    }
    std:: cout << "Нет такого товара.\n";
    }
}

void Shop:: add_product(std:: string product) {
    shop_list.push_back(product);
}

void Shop:: scan_area() {
    std:: cout << "Вы видите " << loc_name() <<".\n";
    std:: cout << "В магазине есть: ";
    for (auto i : shop_list) {
        std:: cout << i << "; ";
    }
    std:: cout << '\n';
}



void map:: add_build(std:: string loc_name, std:: string loc_item) {
    Build new_build(loc_name, loc_item);
    builds.push_back(new_build);
}

void map:: add_shop(std:: string loc_name, std:: string loc_item) {
    Shop new_build(loc_name, loc_item);
    shops.push_back(new_build);
}

Shop * map:: search_shop(std:: string loc_name) {
    for (int i = 0; i < shops.size(); ++i) {
        if (shops[i].loc_name() == loc_name) return &(shops[i]);
    }
    return 0;
}

Build * map:: search_build(std:: string loc_name) {
    for (int i = 0; i < builds.size(); ++i) {
        if (builds[i].loc_name() == loc_name) return &(builds[i]);
    }
    return 0;
}

Area * map:: search_area(std:: string locate) {
    Build * build = search_build(locate);
    Shop * shop = search_shop(locate);
    if (build != 0) {
        return build;
    } else if (shop!= 0) {
        return shop;
    }
    return 0;
}

void map:: go_in() {
    if (player -> in_area()) {std:: cout << "Вы уже внутри.\n";}
    else {
        std:: string item_ = search_area(player -> get_locate()) -> chek_item();
        if (item_ == "") {
        } else if (player -> search_item(item_)) { 
            std:: cout << "Использовал " << item_ << ".\n";
            player -> reset_in_build(1);
        } else {
            std:: cout << "Нужен " << item_ << ".\n";
        }
    }
}

void map:: go_out() {
    if (player -> in_area()) {
        player -> reset_in_build(0);
        std:: cout << "Вы вышли.\n";
    } else {
        std:: cout << "Вы не в помещении.\n";
    }
}

void map:: go_to(std:: string loc_name) {
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
