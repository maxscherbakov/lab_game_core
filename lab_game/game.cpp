#include "students.h"
#include <iostream>
#include <string>



void Player:: fight_with(Enemy * enemy) {
    if (enemy == 0) { std:: cout << "Здесь нет таких!\n"; }
    else {
        int my_damage = 0;
        int enemy_damage = 0;
        in_fight = 1;
        bool flag_ability = 0;
        std:: string move;
        while (true) {
            std:: cout << "\n\n";
            if (move == "способность") { use_ability(); flag_ability = 1; }
            if (move == "сбежать") { std:: cout << "Вы сбежали от " << enemy -> get_name() << '\n'; }
            int my_iq_damage = iq - enemy -> get_iq();
            int my_power_damage = power - enemy -> get_power();
            if (my_iq_damage <= 0 && my_power_damage <= 0) { 
                my_damage = 0;
            } else {
                my_damage = (my_iq_damage > my_power_damage) ? my_iq_damage : my_power_damage;
                enemy -> reset_helth((-my_damage));
            }

            int enemy_iq_damage =  -iq + enemy -> get_iq();
            int enemy_power_damage =  -power + enemy -> get_power();
            if (enemy_iq_damage <= 0 && enemy_power_damage <= 0) { 
                std:: cout << "Враг просто уничтожен!\n";
                enemy -> reset_helth(-(enemy -> get_helth()));
            } else {
                enemy_damage = (enemy_iq_damage > enemy_power_damage) ? enemy_iq_damage : enemy_power_damage;
                helth -= enemy_damage;
            }
            
            if (enemy -> get_helth() <= 0) {
                enemy -> alive = 0;
                std:: cout << "Вы победили!\n";
                items.push_back(enemy -> artefact);
                in_fight = 0;
                break;
            } else if (helth <= 0) {
                std:: cout << "Вы проиграли...\n";
                alive = 0;
                in_fight = 0;
                break;
            } else {
                std:: cout << "Вы нанесли " << my_damage << " урона.\n";
                std:: cout << "Вам нанесли " << enemy_damage << " урона.\n";
                std:: cout << name << ":: helth: " << helth << " | iq: " << iq << " | power: " << power << '\n';
                std:: cout << enemy -> get_name() << ":: helth: " << enemy -> get_helth() \
                    << " | iq: " << enemy -> get_iq() << " | power: " << enemy -> get_power() << '\n';
                std:: cout << "\"сбежать\", \"способность\" или дальше...\n";
                std:: cin >> move;
            }
        }
        if (flag_ability) use_ability();
    }
}

void Player:: use_ability() {
    std:: cout << "у вас нет способоностей :(";
}

void Player:: check_inventory() {
    std:: cout << "player name:   " << name << '\n';
    std:: cout << "player helth:  " << helth << '\n';
    std:: cout << "Player iq      " << iq << '\n';
    std:: cout << "Player power:  " << power << '\n';
    std:: cout << "Player energy: " << energy << '\n';
    std:: cout << "player locate: " << locate;
    if (in_build) std:: cout << "(внутри)";
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

void Player:: train() { std:: cout << "Этот навык недоступен\n"; }
void Player:: to_study() { std:: cout << "Этот навык недоступен\n"; }
void Player:: relax() { std:: cout << "Этот навык недоступен\n"; }

