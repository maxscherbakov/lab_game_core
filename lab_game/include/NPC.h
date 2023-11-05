#ifndef NPC_H
#define NPC_H
#include "man.h"
class NPC : public man {
    public:
        NPC (std:: string NPCname, int NPCrole) {
            name = NPCname;
            role = NPCrole;
            iq = 50;
            power = 50;
        }
        bool quest_active{0};
};
#endif // NPC_H