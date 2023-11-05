#ifndef STUDENTS_GENIOUS_H
#define STUDENTS_GENIOUS_H
#include "student.h"
class student_genius : public student {
    private:
        bool book{1};
    public:
        student_genius() {
            iq = 140;
            power = 60;
            items.push_back("книга");
        }
        void use_ability();
        void to_train(); 
        void to_study(); 
};

#endif // STUDENT_GENIOUS_H