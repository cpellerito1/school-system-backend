#ifndef COURSE_H
#define COURSE_H

#include "SchoolSystem.h"

//using namespace school_types;


// Forward Declarations
class Section;

enum Department { ENG = 0, CMPT = 1, BUS = 2, COMM = 3, SCI = 4 };
std::ostream& operator<<(std::ostream&, const Department&);

typedef int course_id_t;

class Course {
    protected:
        std::string name;
        Department department;
        int course_id;
        u_int8_t credits;
        std::string description;
        std::vector<Course*> prerequisites;
        std::vector<Section*> sections;

    public:
        Course(std::string, Department, int, u_int8_t, std::string);
        Course(std::string, Department, int, u_int8_t, std::string, std::vector<Course*>, std::vector<Section*>);

        std::string get_name(void);
        void set_name(std::string);
        course_id_t get_course_id(void) const;
        void set_course_id(course_id_t);
        Department get_department(void);
        void set_department(Department);
        u_int8_t get_credits(void);
        void set_credits(u_int8_t);
        std::string get_desciption(void);
        void set_description(std::string);
        void print_description(void);
        std::vector<Course*> get_prerequisites(void);
        void add_prerequisite(Course*);
        void remove_prerequisite(Course*);
        void set_prerequisities(std::vector<Course*>);
        std::vector<Section*> get_sections(void);
        void add_section(Section*);
        void remove_section(Section*);
        void set_sections(std::vector<Section*>);

        bool operator==(const Course&) const;
        friend std::ostream& operator<<(std::ostream&, const Course&);


};

#endif // COURSE_H
