#ifndef COURSE_H
#define COURSE_H

#include "Registrar.h"

class Course {
    std::string name;
    char department;
    int course_id;
    u_int8_t credits;
    std::string description;
    std::vector<Course*> prerequisites;
    std::vector<Section*> classes;

    public:
        int get_id(void);
        void set_id(int);
        char get_department(void);
        void set_department(char);
        u_int8_t get_credits(void);
        void set_credits(u_int8_t);
        std::string get_desciption(void);
        void set_description(std::string);
        std::vector<Course*> get_prerequisites(void);
        void set_prerequisities(std::vector<Course*>);
        std::vector<Section*> get_classes(void);
        void set_classes(std::vector<Section*>);

        bool operator==(const Course&) const;
        friend std::ostream& operator<<(std::ostream&, const Course&);


};

#endif // COURSE_H
