#include "includes/pet.h"

int main() {
    struct Pet pet;
    create_pet(pet);
    while (true) {
    std::cout << "\nWhat would you like to do next?\n";
    std::cout << "(1) Feed " << pet.name << "\n";
    std::cout << "(2) exit\n";
    std::string choice_str{};
    std::getline(std::cin, choice_str);

        switch (std::stoi(choice_str))
        {
        case 1:
            {
                feed_pet(pet);
            }
            break;
        
        case 2:
            {
                std::cout << "\nGoodbye!\n";
                return 0;
            }
        
        default:
            {
                std::cout << "\nInvalid input! Please choose the number from options.\n";
            }
            break;
        }
    }
}