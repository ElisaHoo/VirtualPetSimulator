#include "includes/pet.h"

int main() {
    std::cout << "*** Virtual Pet Simulator ***\n\n";
    std::cout << "Would you like to download the previous pet's information "
                 "and statistics (1) or create a new pet (2)? ";
    std::string option_str{};
    std::getline(std::cin, option_str);
    struct Pet pet;
    bool stay_in_loop{true};
    while (stay_in_loop) {
        switch (std::stoi(option_str))
        {
        case 1:
            {
                std::vector<std::string> pet_data{load_previous_pet()};
                if (pet_data.size() == 0) {
                    std::cout << "\nNo previous pet's data was found!\n\n";
                    create_pet(pet);
                    stay_in_loop = false;
                    break;
                }
                pet = {pet_data[0], pet_data[1], std::stoi(pet_data[2]), std::stoi(pet_data[3]), std::stoi(pet_data[4])};
                stay_in_loop = false;
            }
            break;
        
        case 2:
            {
                create_pet(pet);
                stay_in_loop = false;
            }
            break;
        
        default:
            {
                std::cout << "\nInvalid input! Please choose the number from options.\n";
            }
            break;
        }
    }
    
    while (true) {
    std::cout << "\nWhat would you like to do next?\n";
    std::cout << "(1) Feed " << pet.name << " (increases happiness and fullness)\n";
    std::cout << "(2) Play " << pet.name << " (increases happiness and decreases energy)\n";
    std::cout << "(3) Put " << pet.name << " sleep (increases energy)\n";
    std::cout << "(4) View statistics\n";
    std::cout << "(5) Save and exit\n";
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
                view_statistics(pet);
            }
            break;
        
        case 5:
            {
                save_state(pet);
                std::cout << "Goodbye!\n";
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