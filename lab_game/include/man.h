#ifndef MAN_H
#define MAN_H
#include <string>

enum Roles {
    STUDENT = 1, PROFESSOR_ROLE = 2, NO_ROLE = 3
};

class man {
    protected:
        int health{100};
        int iq{100};
        int power{100};
        int role{NO_ROLE};
        std:: string name;
        std:: string locate{"spawn"};
        bool alive{1};
    public:
        virtual ~man(){};
        std:: string get_locate() { return locate; }
        std:: string get_name() { return name; }
        int get_helth() { return health; }
        void reset_locate(std:: string loc) { locate = loc; }
        void rename(std:: string name_) { name = name_; }
        int get_iq() { return iq; }
        int get_power() { return power; }
        void reset_helth(int t) { health += t; }
        void death() { alive = 0; }
        bool is_alive() { return alive; }
};

#endif // MAN_H