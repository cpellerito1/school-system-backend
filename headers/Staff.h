#ifndef STAFF.H
#define STAFF.H

#include "Registrar.h"

class Staff : Person {
    std::string title;
    std::vector<Section*> classes;
    std::vector<Section*> class_history;
    std::vector<Student*> advisee;

};


#endif // STAFF.H
