#ifndef SECTION_H
#define SECTION_H

#include "SchoolSystem.h"

#include "Course.h"
#include "Staff.h"

// Forward Declarations
class Staff;

class Section : public Course {
    Course* course;
    int section_id;
    Class_S::schedule class_schedue;
    id_t instructor;
    std::vector<id_t> roster;
    int crn;

    public:
        int get_section_id(void);
        void set_section_id(int);
        Class_S::schedule get_class_schedule(void);
        void set_class_schedule(Class_S::schedule);
        void print_schedule(void);
        id_t get_instructor(void);
        void set_instructor(id_t);
        std::vector<id_t> get_roster(void);
        void add_student(id_t);
        void remove_student(id_t);
        void set_roster(std::vector<id_t>);
        int get_crn(void);
        void set_crn(int);

        bool operator==(const Section&);
        friend std::ostream& operator<<(std::ostream&, const Section&);

};

#endif // SECTION_H
