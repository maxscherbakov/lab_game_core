#include <iostream>
#include <fstream>
#include <string>
#include "students.h"
#include "professor.h"
#include "map.h"
#include "game.h"
using namespace std;

void createBuilds(map * punk) {
    punk -> add_build("матмех", "студак");
    punk -> add_build("общага", "пропуск");
    punk -> add_build("остановка", "");
    punk -> add_shop("Андрейка", "пропуск");
    punk -> shops[0].add_product("энергетик");
    punk -> shops[0].add_product("печенье");
    
}

void createNPC(map * punk) {
    punk -> builds[0].add_npc_in("студент в коридоре", 's');
    punk -> builds[0].add_npc_in("Федер Андреевич", 'p');
    punk -> builds[0].add_npc_out("студент на перекуре", 's');
    punk -> builds[1].add_npc_out("консьерж", 'n');
}


void createEnemy(map * punk) {
    punk -> builds[0].add_enemy("Аспирант", 130, 100, "зачет1");

    punk -> builds[0].add_enemy("Препод", 150, 110, "зачет2");
}

void rools(std:: string text) {
    char text_;
    ifstream is(text, ios::binary);
    while (is) {cout << text_; is.get(text_);}
    is.close();
}

void clear_cons() {
    for (int i = 0; i < 40; ++i) cout << '\n';
}

int main() {
    map punk;
    createBuilds(&punk);
    createNPC(&punk);
    createEnemy(&punk);

    
    string move;
    cout << "Выберите класс (студент-первак, студент-гений, профессор)\n";
    while (true) {
    cin >> move;
    if (move == "студент-первак") { punk.player = new student_pervak; break; }
    else if (move == "студент-гений") { punk.player = new student_genius; break; }
    else if (move == "профессор") { punk.player = new Professor; break; }
    else { cout << "Нет такого класса.\n"; }
    }
    cout << "Введите имя персонажа:\n";
    cin >> move;
    punk.player -> rename(move);

    rools("welcome.txt");

    while (true) {
        cin >> move;
        clear_cons();
        if (move == "game_over") { break; }
        else if (move == "инвентарь") punk.player -> check_inventory();
        else if (move == "осмотреться") punk.search_area(punk.player -> get_locate()) -> scan_area();
        else if (move == "help") rools("help.txt");
        else if (move == "тренировка") punk.player -> train();
        else if (move == "ботать") punk.player -> to_study();
        else if (move == "отдых") punk.player -> relax();
        else if (move == "купить") {
            if (punk.search_shop(punk.player -> get_locate()) != 0 && \
                punk.player -> in_area()) {
                punk.search_shop(punk.player -> get_locate()) -> scan_area();
                cout << "Что хотите приобрести?\n";
                cin >> move;
                punk.search_shop(punk.player -> get_locate())->buy_item(move, punk.player);
            } else {
                cout << "Покупать можно только в магазинах.\n";
            }
        }

        else if (move == "сразиться") {
            if (punk.player -> in_area()) {
                if (punk.search_build(punk.player -> get_locate()) == 0) {
                    cout << "Здесь нельзя сражаться.\n";
                } else {
                    cout << "С кем хотите сразиться?\n";
                    punk.search_build(punk.player -> get_locate()) -> scan_Enemy();
                    cin >> move;
                    punk.player -> fight_with(punk.search_build(punk.player -> get_locate()) -> search_enemy(move));
                }
            } else {
                cout << "Сражения доступны только внутри строений.\n";
            }
            if (punk.player -> get_helth() <= 0) break;
        }


        else if (move == "идти") {
            if (punk.player -> in_area()) {
                cout << "Выйдите из здания. (выйти)\n";
                continue;
            }

            cout << "Куда хотите пойти?\n";
            cin >> move;
            if (move == punk.player -> get_locate()) {
                cout << "Вы уже здесь.\n";
            } else {
                punk.go_to(move);
                
            }
        }
        else if (move == "войти") {
            punk.go_in();
        }
        else if (move == "выйти") {
            if (punk.player -> in_area()) {
                punk.player -> reset_in_build(0);
                cout << "Вы вышли.\n";
            } else {
                cout << "Вы не в помещении.\n";
            }
        } else {
            cout << "Нет такой команды.\n";
        }
    }


}