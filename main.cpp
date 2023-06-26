#include "includes/pet.h"

int main() {
    struct Pet pet;
    create_pet(pet);
    while (true) {
    std::cout << "\nWhat would you like to do next?\n";
    std::cout << "(1) Feed " << pet.name << " (increases happiness and fullness)\n";
    std::cout << "(2) Play " << pet.name << " (increases happiness and decreases energy)\n";
    std::cout << "(3) Put " << pet.name << " sleep (increases energy)\n";
    std::cout << "(4) exit\n";
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
                play_pet(pet);
            }
            break;

        case 3:
            {
                pet.energy = put_sleep(pet.energy);
                std::cout << "\n";
                std::cout << pet.name << ": 'Zzzzz...'\n";
                std::cout << "Now your pet's energy is " << pet.energy << ".\n";
            }
            break;
        
        case 4:
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