#ifndef SHOP_H
#define SHOP_H
#include "area.h"

class Shop : public Area {
    public:
        Shop(std:: string loc_name, std:: string loc_item) 
            : Area(loc_name, loc_item)
        {}
        void add(std:: string, int, int, std:: string);
        void interact_with(std:: string, Player *);
        void scan_area();

    private:
        std:: vector <std:: string> shop_list;
};

#endif // SHOP_H