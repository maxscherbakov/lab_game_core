#ifndef MAP_H
#define MAP_H
#include "game.h"

class Area {
    protected:
        Area(std:: string loc_name, std:: string loc_item) {
            locate_name = loc_name;
            chekpoint_item = loc_item;
        }
        std:: string locate_name;
        std:: string chekpoint_item;
    public:
        bool player_here{0};
        std:: string chek_item() { return chekpoint_item; }
        std:: string loc_name() { return locate_name; }
        virtual void scan_area();
};


class Build : public Area{
    private:
        std:: vector <NPC> npc_in;
        std:: vector <NPC> npc_out;
        std:: vector <Enemy> enemy_in;
    public: 
        Build(std:: string loc_name, std:: string loc_item) 
            : Area(loc_name, loc_item)
        {}
        Enemy * search_enemy(std:: string);
        void add_enemy(std:: string, int, int, std:: string);
        void add_npc_in(std:: string, char);
        void add_npc_out(std:: string, char);
        void scan_npc();
        void scan_Enemy();
        void scan_area();
};


class Shop : public Area {
    public:
        Shop(std:: string loc_name, std:: string loc_item) 
            : Area(loc_name, loc_item)
        {}
        void add_product(std:: string);
        void buy_item(std:: string, Player *);
        void scan_area();

    private:
        std:: vector <std:: string> shop_list;
};

struct map {
    std:: vector <Build> builds;
    std:: vector <Shop> shops;
    Player * player;
    
    void add_build(std:: string, std:: string);

    void add_shop(std:: string, std:: string);
    Build * search_build(std::string);
    Shop * search_shop(std:: string);
    void go_in();
    void go_to(std:: string);
    Area * search_area(std:: string);


};

#endif // MAP_H