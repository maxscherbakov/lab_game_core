#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "player.h"

class Professor : public Player {
    private:
        bool granite{1}; 
    public:
        Professor () {
            iq = 110;
            power = 90;
            role = PROFESSOR_ROLE;
            items.push_back("гранит науки");
        }
        void use_ability();
        void to_train();
        void to_study();
        void to_relax();
};

#endif // PROFESSOR_H