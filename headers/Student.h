#ifndef STUDENT_H
#define STUDENT_H

#include "Registrar.h"

class Student : Person {
    std::vector<std::string> major;
    std::vector<std::string> minor;
    float GPA;
    int current_credits;
    std::map<Section*, float> classes;
    std::vector<Staff*> advisor;

    void calculate_gpa(void);
    void calculate_credits(void);


    public:
        std::vector<std::string> get_major(void);
        void set_major(std::vector<std::string>&);
        void add_major(std::string&);
        std::vector<std::string> get_minor(void);
        void set_minor(std::vector<std::string>&);
        void add_minor(std::string&);
        float get_gpa(void);
        void set_gpa(float);
        int get_credits(void);
        void set_credits(int);
    
};

#endif // STUDENT_H
