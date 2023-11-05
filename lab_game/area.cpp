#include "area.h"

void Area:: add_npc_in(std:: string NPCname, int NPCrole) {
    NPC new_npc(NPCname, NPCrole);
    new_npc.reset_locate(locate_name);
    npc_in.push_back(new_npc);
}  

void Area:: add_npc_out(std:: string NPCname, int NPCrole) {
    NPC new_npc(NPCname, NPCrole);
    new_npc.reset_locate(locate_name);
    npc_out.push_back(new_npc);
}

void Area:: scan_npc() {
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

void Area:: scan_area() {
    std:: cout << "Вы видите " << loc_name() <<".\n";
    scan_npc();
}
