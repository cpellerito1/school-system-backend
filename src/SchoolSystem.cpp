#include "../include/SchoolSystem.h"

/**
 * This is the entry point for the program
*/
void SchoolSystem::login() {
    // Initialize registrar
    Registrar *r;
    r->initialize();

    std::cout << "Please enter the cwid of the student you wish to access: ";
    id_t input;
    std::cin >> input;
    // Check the input to make sure it is valid then check that the student exists
    while (!std::cin) {
        std::cin.clear();
        std::cout << "Error, please enter a valid cwid: ";
        std::cin >> input;
    }



}