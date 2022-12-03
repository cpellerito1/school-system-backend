#include "../include/Registrar.h"

int main() {

    // Print the menu
    std::cout << "1. View registration info\n2. View schedule\n3. View classes\n4. Register for a class\n";
    std::cout << "Please select an option: ";
    // Get Valid input from user
    int option;
    std::cin >> option;
    while (option < 1 || option > 4 || !std::cin) {
        std::cin.clear();
        std::cout << "Invalid input, please try again: ";      
        std::cin >> option;
    }

    switch (option) {

    }

    return 0;
}