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
        /* Это довольно скользкая тема относительно сеттеров. Потому что
         * они делают так, будто поля просто публичные. То есть инкапсуляция
         * нарушается. Иногда, с этим можно справиться с использованием слова
         * friend, который тоже не слишком гуд, но только расширяет границы
         * инкапсуляции, а не полностью убирает ее. */
        /* Но в твоем конкретном случае можно было немного иначе. Можно реализовать
         * как во втором ответе: https://stackoverflow.com/questions/17934310/need-help-implementing-health-in-basic-c-attack-game */
        void reset_helth(int t) { health += t; }
        void death() { alive = 0; }
        bool is_alive() { return alive; }
};

#endif // MAN_H