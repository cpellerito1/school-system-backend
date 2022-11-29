#ifndef STAFF.H
#define STAFF.H

#include "Registrar.h"

class Staff : public Person {
    std::string title;
    std::vector<Section*> classes;
    std::vector<Section*> class_history;
    std::vector<Student*> advisee;

    public:
        std::string get_title(void);
        void set_title(std::string t);
        std::vector<Section*> get_classes(void);
        void add_class(Section*);
        void remove_class(Section*);
        void set_classes(std::vector<Section*>&);
        std::vector<Section*> get_class_history(void);
        void add_class_to_history(Section*);
        void remove_class_from_history(Section*);
        void set_class_history(std::vector<Section*>&);
        std::vector<Student*> get_advisee(void);
        void add_advisee(Student*);
        void remove_advisee(Student*);
        void set_advisee(std::vector<Student*>&);

};


#endif // STAFF.H
