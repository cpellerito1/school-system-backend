#ifndef STUDENT_H
#define STUDENT_H

#include "SchoolSystem.h"

#include "Staff.h"
#include "Course.h"
#include "Section.h"

//using namespace school_types;

// Forward Declarations
class Course;

class Student : public Person {
    std::vector<std::string> major;
    std::vector<std::string> minor;
    float GPA;
    uint8_t total_credits;
    std::unordered_set<section_id_t> current_classes;
    std::unordered_map<Course*, std::pair<section_id_t, float>> all_classes;
    std::vector<Schedule*> class_schedule;
    std::vector<id_t> advisor;

    void calculate_gpa(void);
    void calculate_credits(void);


    public:
        Student(std::string, id_t, std::string, std::vector<std::string>, std::vector<std::string>, std::vector<id_t>);

        std::vector<std::string> get_major(void);
        void set_major(std::vector<std::string>);
        void add_major(std::string);
        void remove_major(int);
        void remove_major(std::string);
        std::vector<std::string> get_minor(void);
        void set_minor(std::vector<std::string>);
        void add_minor(std::string);
        void remove_minor(int);
        void remove_minor(std::string);
        float get_gpa(void);
        void set_gpa(float);
        uint8_t get_credits(void);
        void set_credits(uint8_t);
        std::unordered_set<section_id_t> get_current_classes(void);
        void add_current_class(section_id_t);
        void remove_current_class(section_id_t);
        void set_current_class(std::unordered_set<section_id_t>);
        std::unordered_map<Course*, std::pair<section_id_t, float>> get_all_classes(void);
        void add_class_to_all(std::pair<Course*, std::pair<section_id_t, float>>);
        void remove_class_from_all(Course*);
        void set_all_classes(std::unordered_map<Course*, std::pair<section_id_t, float>>);
        std::vector<Schedule*> get_class_schedule(void);
        void add_to_class_schedule(Schedule*);
        void remove_from_class_schedule(Schedule*);
        void set_class_schedule(std::vector<Schedule*>);
        std::vector<id_t> get_advisor(void);
        void add_advisor(id_t);
        void remove_advisor(id_t);
        void set_advisor(std::vector<id_t>);

        void print_registration_info(void);
    
};

#endif // STUDENT_H
