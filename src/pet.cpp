#include "../includes/pet.h"

void create_pet() {
    std::cout << "*** Virtual Pet Simulator ***\n\n";
    
    std::cout << "Please enter your pet's type: ";
    std::string pet_type;
    std::getline(std::cin, pet_type);
    
    std::cout << "Please enter your pet's name: ";
    std::string pet_name;
    std::getline(std::cin, pet_name);

    struct Pet pet {.name = pet_name, .type = pet_type};

    std::cout << "A new pet created! Name: " << pet.name << " and type: " << pet.type << "\n";
}