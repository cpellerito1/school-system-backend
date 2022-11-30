#ifndef SECTION_H
#define SECTION_H

#include "Registrar.h"

class Section : public Course {
    int section_id;
    Class_S::schedule class_schedue;
    Staff* instructor;
    std::vector<Student*> roster;
    int crn;

    public:
        int get_section_id(void);
        void set_section_id(int);
        Class_S::schedule get_class_schedule(void);
        void set_class_schedule(Class_S::schedule);
        void print_schedule(void);
        Staff* get_instructor(void);
        void get_instructor(Staff*);
        std::vector<Student*> get_roster(void);
        void add_student(Student*);
        void remove_student(int);
        void remove_student(Student*);
        void set_roster(std::vector<Student*>);
        int get_crn(void);
        void set_crn(int);

        bool operator==(const Section&);
        friend std::ostream& operator<<(std::ostream&, const Section&);

};

#endif // SECTION_H
