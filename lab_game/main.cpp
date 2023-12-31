#include "map.h"
#include "student-first.h"
#include "student-genious.h"
#include "professor.h"
#include <fstream>

void createBuilds(Map * punk) {
    punk -> add_building("матмех", "студак");
    punk -> add_building("общага", "пропуск");
    punk -> add_building("остановка", "");
    punk -> add_shop("Андрейка", "пропуск");
    punk -> search_area("Андрейка")->add("энергетик", 0, 0, "");
    punk -> search_area("Андрейка")->add("печенье", 0, 0, "");
}

void createNPC(Map * punk) {
    punk -> search_area("матмех")->add_npc_in("студент в коридоре", STUDENT);
    punk -> search_area("Андрейка")->add_npc_in("Федер Андреевич", PROFESSOR_ROLE);
    punk -> search_area("матмех")->add_npc_out("студент на перекуре", STUDENT);
    punk -> search_area("общага")->add_npc_out("консьерж", NO_ROLE);
}

void createEnemy(Map * punk) {
    punk -> search_area("матмех")->add("Аспирант", 130, 100, "зачет1");
    punk -> search_area("матмех")->add("Препод", 150, 110, "зачет2");
}

void clear_cons() {
    for (int i = 0; i < 40; ++i) std:: cout << std:: endl;
}

void help() {

    std:: string fname = "help.txt";
    std:: ifstream inp(fname);

    if (inp.is_open()) {
        std:: string str(std:: istreambuf_iterator<char>{inp}, {});
        inp.close();
        std:: cout << str;
    } else {
        std:: cout << "File not open\n";
    }
}

enum Actions {
    GO_TO = 1, ACTION = 2, GO_IN = 3, GO_OUT = 4, INVENTORY = 5,
    LOOK_AROUND = 6, RELAX = 7, STUDY = 8, TRAIN = 9, HELP = 10
};

enum Classes {
    STUDENT_FIRST = 1, STUDENT_GENIOUS = 2, PROFESSOR = 3
};

int main() {
    Map punk;
    createBuilds(&punk);
    createNPC(&punk);
    createEnemy(&punk);

    
    int action;
    std::cout << "Выберите класс:\n1. Студент-первак\n2. Студент-гений\n3. Профессор\n";
    while (true) {
        std::cin >> action;
        switch (action) {
            case STUDENT_FIRST:
                punk.player = new student_pervak; 
                break;
            case STUDENT_GENIOUS:
                punk.player = new student_genius; 
                break;
            case PROFESSOR:
                punk.player = new Professor; 
                break;
            default:
                std::cout << "Нет такого класса.\n";
        }
        if (punk.player != 0) break;
    }
    std::cout << "Введите имя персонажа:" << std::endl;
    std::string name;
    std::cin >> name;
    punk.player -> rename(name);
    std:: cout << "Добро пожаловать в Петродворцовый учебно-научный комплекс (ПУНК).\n";
    std:: cout << "Как играть? Введите \"10\".\n";
    bool next = 1;
    while (next) {
        std::cin >> action;
        clear_cons();
        switch (action) {
        case GO_TO:
            if (punk.player -> in_area()) {
                std::cout << "Выйдите из здания. (выйти)\n";
                continue;
            }

            std::cout << "Куда хотите пойти?\n";
            std::cin >> name;
            if (name == punk.player -> get_locate()) {
                std::cout << "Вы уже здесь.\n";
            } else {
                punk.go_to(name);
                
            }
            break;
        
        case ACTION:
            if (punk.search_area(punk.player -> get_locate()) == 0) break;
            punk.search_area(punk.player -> get_locate()) -> scan_area();
            std::cout << "Выберите объект.\n";
            std::cin >> name;
            punk.search_area(punk.player->get_locate())->interact_with(name, punk.player);
            break;
        
        case GO_IN:
            punk.go_in();
            break;
        case GO_OUT:
            punk.go_out();
            break;
        case INVENTORY:
            punk.player -> check_inventory();
            break;
        case LOOK_AROUND:
            punk.search_area(punk.player -> get_locate()) -> scan_area();
            break;
        case RELAX:
            punk.player->to_relax();
            break;
        case STUDY:
            punk.player->to_study();
            break;
        case TRAIN:
            punk.player->to_train();
            break;
        case HELP:
            help();
            break;
        default:
            std::cout << "Нет такой команды.\n";
            next = 0;
        }        
    }
}