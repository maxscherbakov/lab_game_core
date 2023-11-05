#include "shop.h"

void Shop:: interact_with(std:: string item_, Player * player) {
    if (player_here and player -> in_area()) {
    for (auto i : shop_list) {
        if (i == item_) {
            std:: cout << "Вы купили " << item_ << ".\n";
            player -> add_item(item_);
            return;
        }
    }
    std:: cout << "Нет такого товара.\n";
    }
}

void Shop:: add(std:: string product, int, int, std:: string) {
    shop_list.push_back(product);
}

void Shop:: scan_area() {
    std:: cout << "Вы видите " << loc_name() <<".\n";
    std:: cout << "В магазине есть: ";
    for (auto i : shop_list) {
        std:: cout << i << "; ";
    }
    std:: cout << '\n';
}

