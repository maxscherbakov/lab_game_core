#ifndef STUDENTS_H
#define STUDENTS_H
#include "game.h"

class student : public Player {
    protected:
    student () {
        role = 's';
        items.push_back("студак");
        items.push_back("пропуск");
    }

    void relax();
};

class student_pervak : public student {
    private: 
        int old_students{3};
    public:
        student_pervak () {
            iq = 85;
            power = 100;
        }
        void use_ability();
        void train(); 
        void to_study();
};

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
        void train(); 
        void to_study(); 
};

#endif // STUDENTS_H