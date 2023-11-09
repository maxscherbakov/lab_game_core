#ifndef AREA_H
#define AREA_H
#include "player.h"
#include "NPC.h"

class Area {
    protected:
        Area(std:: string loc_name, std:: string loc_item) {
            locate_name = loc_name;
            chekpoint_item = loc_item;
        }

        std:: vector <NPC> npc_in;
        std:: vector <NPC> npc_out;
        std:: string locate_name;
        std:: string chekpoint_item;
        void scan_npc();
    public:
        virtual ~Area(){};
        bool player_here{0};
        std:: string chek_item() { return chekpoint_item; }
        std:: string loc_name() { return locate_name; }
        virtual void scan_area();
        virtual void interact_with(std:: string, Player *) = 0;
        virtual void add(std:: string, int, int, std:: string) = 0;
        void add_npc_in(std:: string, int);
        void add_npc_out(std:: string, int);
};
#endif // AREA_H