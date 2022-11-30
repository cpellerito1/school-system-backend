#ifndef STUDENT_H
#define STUDENT_H

#include "Registrar.h"

class Student : public Person {
    std::vector<std::string> major;
    std::vector<std::string> minor;
    float GPA;
    int current_credits;
    std::unordered_map<Section*, float> classes;
    Class_S::schedule class_schedule;
    std::vector<Staff*> advisor;

    void calculate_gpa(void);
    void calculate_credits(void);


    public:
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
        int get_credits(void);
        void set_credits(int);
        std::unordered_map<Section*, float> get_classes(void);
        void add_class(std::pair<Section*, float>);
        void remove_class(Section*);
        void set_classes(std::unordered_map<Section*, float>);
        Class_S::schedule get_class_schedule(void);
        void add_to_class_schedule(std::pair<Class_S::Day, std::pair<Class_S::classtime, Class_S::classtime>>);
        void remove_from_class_schedule(Class_S::Day, std::pair<Class_S::classtime, Class_S::classtime>);
        void set_class_schedule(std::multimap<Class_S::Day, std::pair<Class_S::classtime, Class_S::classtime>>);
    
};

#endif // STUDENT_H
