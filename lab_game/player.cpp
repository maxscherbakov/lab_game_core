#include "player.h"

void Player:: use_ability() {
    std:: cout << "у вас нет способоностей :(";
}

void Player:: check_inventory() {
    std:: cout << "player name:   " << name << '\n';
    std:: cout << "player health:  " << health << '\n';
    std:: cout << "Player iq      " << iq << '\n';
    std:: cout << "Player power:  " << power << '\n';
    std:: cout << "Player energy: " << energy << '\n';
    std:: cout << "player locate: " << locate;
    if (in_building) std:: cout << "(внутри)";
    std:: cout << '\n';
    std:: cout << "Inventory:     ";
    for (auto i : items) std:: cout << i << "; ";
    std:: cout << '\n';
}

bool Player:: search_item(std:: string item_) {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i] == item_) return true;
    }
    return false;
}

