#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "game.h"

class Professor : public Player {
    private:
        bool granite{1}; 
    public:
        Professor () {
            iq = 110;
            power = 90;
            role = 'p';
            items.push_back("гранит науки");
        }
        void use_ability();
};


#endif // PROFESSOR_H