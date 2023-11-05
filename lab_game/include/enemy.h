#ifndef ENEMY_H
#define ENEMY_H
#include "man.h"

class Enemy : public man {
    public:
        Enemy(std:: string enemyname, int iq_, int power_, std:: string item) {
            name = enemyname;
            artefact = item;
            iq = iq_;
            power = power_;
            role = PROFESSOR_ROLE;
        }
        std:: string artefact;
};

#endif // ENEMY_H
