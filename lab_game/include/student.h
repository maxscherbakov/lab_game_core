#ifndef STUDENTS_H
#define STUDENTS_H
#include "player.h"
#include <iostream>

class student : public Player {
    protected:
    student () {
        role = STUDENT;
        items.push_back("студак");
        items.push_back("пропуск");
    }
    void to_relax();
};
#endif // STUDENTS_H