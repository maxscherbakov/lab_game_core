#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>

class man {
    protected:
        int helth{100};
        int iq{100};
        int power{100};
        char role;
        std:: string name;
        std:: string locate{"spawn"};
    public:
        std:: string get_locate() { return locate; }
        std:: string get_name() { return name; }
        int get_helth() { return helth; }
        void reset_locate(std:: string loc) { locate = loc; }
        void rename(std:: string name_) { name = name_; }
        int get_iq() { return iq; };
        int get_power() { return power; }

};

class NPC : public man {
    public:
        NPC (std:: string NPCname, char NPCrole) {
            name = NPCname;
            role = NPCrole;
            iq = 50;
            power = 50;
        }
        bool quest_active{0};
};

class Enemy : public man {
    public:
        Enemy(std:: string enemyname, int iq_, int power_, std:: string item) {
            name = enemyname;
            artefact = item;
            iq = iq_;
            power = power_;
            role = 'p';
        }
        bool alive{1};
        std:: string artefact;
        void reset_helth(int t) { helth += t; };

};


class Player : public man {
    protected:
        int energy{100};
        bool in_build{0};
        bool in_fight{0};
        bool alive{1};
        std:: vector <std:: string> items;
    public: 
        virtual void train();
        virtual void to_study();
        virtual void relax();
        virtual void use_ability();
        void check_inventory();
        bool search_item(std:: string item_);
        void fight_with(Enemy * enemy); 
        bool in_area() { return in_build; }
        void reset_in_build(bool t) { in_build = t; }
        int get_energy() { return energy; }
        void add_item (std:: string item_) { items.push_back(item_); }
};


#endif // GAME_H