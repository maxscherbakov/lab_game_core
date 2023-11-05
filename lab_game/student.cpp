#include "student.h"


void student:: to_relax() {
    if (locate == "общага" && in_build) {
        std:: cout << "Отдых это хорошо... =>\n\tenergy: +30\n\thelth: +30\n";
        energy = (100 < energy + 30) ? 100 : energy + 30; helth += 30;
    } else {
        std:: cout << "Отдых доступен только в общаге.\n";
    }
}
