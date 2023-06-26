#include "../includes/pet.h"

void create_pet(struct Pet& pet) {
    std::cout << "*** Virtual Pet Simulator ***\n\n";
    
    std::cout << "Please enter your pet's type: ";
    std::string pet_type;
    std::getline(std::cin, pet_type);
    
    std::cout << "Please enter your pet's name: ";
    std::string pet_name;
    std::getline(std::cin, pet_name);

    pet = {pet_name, pet_type};

    std::cout << "\nA new pet created! Name: " << pet.name 
              << " and type: " << pet.type << "\n";
    std::cout << "Your pet's happiness is now " << pet.happiness 
              << " and fullness: " << pet.fullness << "\n";
    std::cout << "Keep the happiness and fullness above zero to " 
                 "make your pet feel satisfied!\n\n";
}

void feed_pet(struct Pet& pet) {
    pet.happiness += 1;
    pet.fullness += 1;
    std::cout << "\n";
    std::cout << pet.name << ": 'Yum, yum!'\n";
    std::cout << "Now your pet's happiness is " << pet.happiness 
              << " and fullness is " << pet.fullness << ".\n";
}