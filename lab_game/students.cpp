#include "students.h"
#include <iostream>


void student:: relax() {
    if (locate == "общага" && in_build) {
        std:: cout << "Отдых это хорошо... =>\n\tenergy: +30\n\thelth: +30\n";
        energy = (100 < energy + 30) ? 100 : energy + 30; helth += 30;
    } else {
        std:: cout << "Отдых доступен только в общаге.\n";
    }
}



void student_pervak:: train() { 
    if (iq < 5) {
        std:: cout << "Нужно ботать.\n";
    } else if (energy < 10) {
        std:: cout << "Нужен отдых.\n";
    } else {
        std:: cout << "Сходил на спорт площадку и потренировался. =>\n\tiq: -5\n\tenergy: -10\n\tpower: +15\n";
        iq -= 5; energy -= 10; power += 15;
    }
}

void student_pervak:: to_study() { 
    if (energy >= 30) {
    std:: cout << "Время проведено с пользой (или нет). =>\n\tiq: +15\n\tenergy: -30\n";
    iq += 15; energy -= 30;
    } else {
        std:: cout << "Нужен отдых.\n";
    }
}

void student_pervak:: use_ability() {
    if (old_students > 0 && in_fight) { 
        std:: cout << "Посоветоваться со старшекурсником. =>\n\tiq: +30\n"; 
        iq += 30; 
        old_students -= 1;
    } else if (in_fight) {
        std:: cout << "Знакомых больше нет.";
    } else {
        iq -= (3 - old_students) * 30;
    }
}



void student_genius:: train() {
    if (energy < 40) {
        std:: cout << "Нужен отдых.\n";
    } else {
        std:: cout << "Этот класс не создан для такого но все по науке. =>\n\tiq: +1\n\tenergy: -40\n\tpower: +5\n";
        iq += 1; energy -= 40; power += 5;
    }
}

void student_genius:: to_study() { 
    if (energy < 30) {
        std:: cout << "Нужен отдых.\n";
    } else {
        std:: cout << "Тяжело стать еще умнее... =>\n\tiq: +4\n\tenergy: -30\n\tpower: -0\n";
        iq += 4; energy -= 30; power -= 0;
    }
}

void student_genius:: use_ability() {
    if (book == 1) {
        std:: cout << "Вы использовали книгу. =>\n\tpower: +50\n";
        power += 50;
        book = 0;
    } else {
        if (in_fight) { std:: cout << "Книга уже была использована ранее.\n"; } 
        else { power -= 50; }
    }
}


