#include "../include/SchoolSystem.h"

id_t get_valid_input() {
    id_t input;
    std::cin >> input;
    while (!std::cin) {
        std::cin.clear();
        std::cout << "Error, please enter a valid cwid: ";
        std::cin >> input;
    }

    return input;
}

namespace SchoolSystem {
/**
 * This is the entry point for the program
*/
void login() {
    // Initialize registrar
    Registrar *r;
    r->initialize();
    
    // Get input from the user
    std::cout << "Please enter the cwid of the student you wish to access: ";
    id_t student_id = get_valid_input();
    // Since student objects are compared for equaity using their cwids, create a temp student object and search for it
    Student * temp_student;
    temp_student->set_cwid(student_id);
    auto student_itr = r->find_student(*temp_student);
    while (student_itr == r->get_grad_students().end()) {
        std::cout << "Error, student doesn't exist. Please enter a valid cwid: ";
        temp_student->set_cwid(get_valid_input());
        student_itr = r->find_student(*temp_student);
    }
    // After the student was verified create a reference to that student
    Student &student = **student_itr;

    // Now print the menu
    std::cout << "1. View registration info\n2. View schedule\n3. View classes\n4. Register for a class\n";
    std::cout << "Please select an option: ";
    int option;
    std::cin >> option;
    while (true) {
        switch (option) {
            case 1:
                // View registration info
                student.print_registration_info();
                break;
            case 2:
                // View students schedule
                for (auto class_time: student.get_class_schedule())
                    std::cout << class_time << std::endl;
                break;
            case 3:
                // View a list of all the classes
                for (auto course: r->get_all_courses()) {
                    std::cout << course << std::endl;
                    for (auto section: course->get_sections()) {
                        std::cout << " - " << section << std::endl;
                        std::cout << "meeting times: " << "\n";
                        section->print_schedule();
                    }
                }
                break;
            case 4:
                r->start_registration(student);
                break;
            default:
                std::cout << "Error: please enter a valid option: ";
                std::cin >> option;
                break;
        }
    }
}
}