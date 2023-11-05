#include "student-genious.h"

void student_genius:: to_train() {
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

