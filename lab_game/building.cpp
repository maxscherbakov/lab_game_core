#include "building.h"


Enemy * Building:: search_enemy(std:: string enemy_name) {
    for (int i = 0; i < enemy_in.size(); ++i) {
        if (enemy_in[i].get_name() == enemy_name) return &enemy_in[i];
    }
    return 0;
}

void Building:: add(std:: string enemyname, int iq_, int power_, std:: string item) {
    Enemy new_enemy(enemyname, iq_, power_, item);
    enemy_in.push_back(new_enemy);
}

void Building:: scan_Enemy() {
    std:: cout << "Enemy: ";
    for (auto i : enemy_in) {
        if (i.is_alive()) std:: cout << i.get_name()<< "(iq: " << i.get_iq() << ", power: " << i.get_power() <<\
         ", helth: " << i.get_helth() <<"); ";
    }
    std:: cout << '\n';
}

void Building:: scan_area() {
    Area:: scan_area();
    scan_Enemy();
}

void Building:: interact_with(std:: string name_enemy, Player * player) {
    Enemy * enemy = search_enemy(name_enemy);
    if (enemy == 0) { std:: cout << "Здесь нет таких!\n"; }
    else {
        int my_damage = 0;
        int enemy_damage = 0;
        player->reset_in_fight(1);
        bool flag_ability = 0;
        std:: string action;
        while (true) {
            std:: cout << "\n\n";
            if (action == "способность") { player->use_ability(); flag_ability = 1; }
            if (action == "сбежать") { std:: cout << "Вы сбежали от " << enemy -> get_name() << '\n'; }
            int my_iq_damage = player->get_iq() - enemy -> get_iq();
            int my_power_damage = player->get_power() - enemy -> get_power();
            if (my_iq_damage <= 0 && my_power_damage <= 0) { 
                my_damage = 0;
            } else {
                my_damage = (my_iq_damage > my_power_damage) ? my_iq_damage : my_power_damage;
                enemy -> reset_helth((-my_damage));
            }

            int enemy_iq_damage =  -player->get_iq() + enemy -> get_iq();
            int enemy_power_damage =  -player->get_power() + enemy -> get_power();
            if (enemy_iq_damage <= 0 && enemy_power_damage <= 0) { 
                std:: cout << "Враг просто уничтожен!\n";
                enemy -> reset_helth(-(enemy -> get_helth()));
            } else {
                enemy_damage = (enemy_iq_damage > enemy_power_damage) ? enemy_iq_damage : enemy_power_damage;
                player->reset_helth(-enemy_damage);
            }
            
            if (enemy -> get_helth() <= 0) {
                enemy -> death();
                std:: cout << "Вы победили!\n";
                player->add_item(enemy -> artefact);
                player->reset_in_fight(0);
                break;
            } else if (player->get_helth() <= 0) {
                std:: cout << "Вы проиграли...\n";
                player->death();
                player->reset_in_fight(0);
                break;
            } else {
                std:: cout << "Вы нанесли " << my_damage << " урона.\n";
                std:: cout << "Вам нанесли " << enemy_damage << " урона.\n";
                std:: cout << player->get_name() << ":: helth: " << player->get_helth() \
                    << " | iq: " << player->get_iq() << " | power: " << player->get_power() << '\n';
                std:: cout << enemy -> get_name() << ":: helth: " << enemy -> get_helth() \
                    << " | iq: " << enemy -> get_iq() << " | power: " << enemy -> get_power() << '\n';
                std:: cout << "\"сбежать\", \"способность\" или дальше...\n";
                std:: cin >> action;
            }
        }
        if (flag_ability) player->use_ability();
    }
}
