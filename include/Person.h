#ifndef PERSON_H
#define PERSON_H

#include "SchoolSystem.h"

class Person {
    protected:
        std::string first_name;
        std::string last_name;
        char middle_i;
        id_t cwid;
        std::string address;

    public:
        std::string get_first_name(void);
        void set_first_name(std::string);
        std::string get_last_name(void);
        void set_last_name(std::string);
        char get_middle_i(void);
        void set_middle_i(char);
        std::string get_name();
        void set_name(std::string, std::string, char);
        id_t get_cwid(void);
        void set_cwid(id_t);
        std::string get_address(void);
        void set_address(std::string);
        bool operator==(const Person &rhs) const;
        friend std::ostream& operator<<(std::ostream &out, const Person &p);


};

#endif // PERSON_H
