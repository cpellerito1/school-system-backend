#include "../headers/Registrar.h"

std::vector<Student*> Registrar::get_undergrad_students() { return undergrad_students; }

void Registrar::add_undergrad_student(Student* s) { undergrad_students.push_back(s); }

void Registrar::remove_undergrad_student(Student* s) { undergrad_students.erase(std::find(undergrad_students.begin(), undergrad_students.end(), s)); }

void Registrar::set_undergrad_students(std::vector<Student*> s) { undergrad_students = s; }

std::vector<Student*> Registrar::get_grad_students() { return grad_students; }

void Registrar::add_grad_student(Student*s ) { grad_students.push_back(s); }

void Registrar::remove_grad_student(Student* s) { grad_students.erase(std::find(grad_students.begin(), grad_students.end(), s)); }

void Registrar::set_grad_students(std::vector<Student*> s) { grad_students = s; }

std::vector<Staff*> Registrar::get_staff() { return staff; }

void Registrar::add_staff(Staff* s) { staff.push_back(s); }

void Registrar::remove_staff(Staff* s) { staff.erase(std::find(staff.begin(), staff.end(), s)); }

void Registrar::set_staff(std::vector<Staff*> s) { staff = s; }

std::vector<Course*> Registrar::get_all_courses() { return all_courses; }

void Registrar::add_course(Course* c) {
    all_courses.push_back(c);
    // After adding the course to the vector, you need to add all of the sections to the crn_section hashmap
    for (auto section: c->get_sections())
        crn_section.insert(std::pair(section->get_crn(), section));
}

void Registrar::remove_course(Course* c) {
    all_courses.erase(std::find(all_courses.begin(), all_courses.end(), c));
    // After removing the course from the vector, remove all the sections from the crn_section hashmap
    for (auto section: c->get_sections())
        crn_section.erase(section->get_crn());
}

void Registrar::set_all_courses(std::vector<Course*> ac) {
    all_courses = ac;
    // After getting all the courses, add all of the sections to the crn_section hashmap
    for (auto course: ac)
        for (auto section : course->get_sections())
            crn_section.insert(std::pair(section->get_crn(), section));
}


/**
 * This method checks if a student is able to register for a class.
 * The CRN and Student have already been verified so no checks need to be done for that. All that needs to be 
 * checked is: if there is room in the students schedule for it (no conflicts with other classes), if adding this
 * class would put them over the credits per semester limit, finally, if they have all of the proper prereqs
*/
bool Registrar::check_registration(Student &s, int crn) {
    Section* section = crn_section.find(crn)->second;
    // Iterate through the students current schedule to see if there any conflicts
    for (auto metting_times: section->get_class_schedule()) {
        for (auto schedule: s.get_schedule()) {

        }
    }
}

/**
 * This method prints all the courses and all of the sections for all of the courses in a formatted way
*/
void Registrar::print_all_courses() {
    std::string day;
    for (auto c: all_courses) {
        std::cout << c->get_name() << " Credits: " << c->get_credits() << "\nDescription: ";
        // Print the description in a nice formatted way so it isn't too large
        c->print_description();
        std::cout << "Sections:\n";
        for (auto s: c->get_sections()) {
            std::cout << "CRN: " << s->get_crn() << "Section ID: " << s->get_section_id() << " Instructor: " << s->get_instructor() << "Meeting Times:\n";
            // Print the sections schedule in a nice formatted way
            s->print_schedule();
        }

    }
}

void Registrar::start_registration(Student& s) {
    std::cout << "Registration for " << s << " started\nClasses: \n";
    print_all_courses();
    // Get the users input on which class they would like to select
    std::cout << "To register for a class, type in the CRN number of the section you would like to register for" << std::endl;
    int crn;
    std::cin >> crn;
    // Make sure its is a valid CRN
    while (!std::cin || crn_section.find(crn) == crn_section.end()) {
        std::cin.clear();
        std::cout << "Invalid CRN, pleae try again: ";
        std::cin >> crn;
    }

    // After getting a valid crn check if the user is allowed/able to join the class
    // Reasons they might not be able include: it would put them over the credits limit, there is a conflict with another class,
    // or they done have the proper prereqs
    if (!check_registration(s, crn)) {

    }


    
}