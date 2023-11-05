#include "professor.h"
#include <iostream>

void Professor:: use_ability() {
    if (granite) {
        std:: cout << "Гранитом науки к слову и по лбу можно дать. =>\n\tiq: +15\n\tpower: +20\n";
        iq += 15;
        power += 20;
        granite = 0;
    } else {
        if (in_fight) {std:: cout << "Гранит уже использовался\n"; }
        else { iq -= 15; power -= 20;}
    }
}

void Professor:: to_train() { std:: cout << "Этот навык недоступен\n"; }
void Professor:: to_study() { std:: cout << "Этот навык недоступен\n"; }
void Professor:: to_relax() { std:: cout << "Этот навык недоступен\n"; }
