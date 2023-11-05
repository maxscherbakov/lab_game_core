#include "student-first.h"

void student_pervak:: to_train() { 
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
