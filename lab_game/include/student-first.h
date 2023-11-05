#ifndef STUDENT_FIRST_H
#define STUDENT_FIRST_H
#include "student.h"

class student_pervak : public student {
    private: 
        int old_students{3};
    public:
        student_pervak () {
            iq = 85;
            power = 100;
        }
        void use_ability();
        void to_train(); 
        void to_study();
};
#endif // STUDENT_FIRST_H