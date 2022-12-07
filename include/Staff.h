#ifndef STAFF_H
#define STAFF_H

#include "SchoolSystem.h"

#include "Person.h"
#include "Section.h"

// Forward Declarations
class Section;

class Staff : public Person {
    std::string title;
    std::vector<section_id_t> classes;
    std::vector<section_id_t> class_history;
    std::vector<id_t> advisee;

    public:
        Staff(std::string, id_t, std::string, std::string);
        Staff(std::string, id_t, std::string, std::string, std::vector<section_id_t>, std::vector<section_id_t>, std::vector<id_t>);
        
        std::string get_title(void);
        void set_title(std::string t);
        std::vector<section_id_t> get_classes(void);
        void add_class(section_id_t);
        void remove_class(section_id_t);
        void set_classes(std::vector<section_id_t>);
        std::vector<section_id_t> get_class_history(void);
        void add_class_to_history(section_id_t);
        void remove_class_from_history(section_id_t);
        void set_class_history(std::vector<section_id_t>);
        std::vector<id_t> get_advisee(void);
        void add_advisee(id_t);
        void remove_advisee(id_t);
        void set_advisee(std::vector<id_t>);

};


#endif // STAFF_H
