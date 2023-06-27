#include "includes/pet.h"

int main() {
    std::cout << "*** Virtual Pet Simulator ***\n\n";
    struct Pet pet;
    bool stay_in_loop{true};
    while (stay_in_loop) {
        std::cout << "Would you like to download the previous pet's information "
                     "and statistics (1) or create a new pet (2)? ";
        int option{};
        std::cin >> option;
        clear_failed_cin();  // Handles if user inputs alphabet etc invalid (excludind ctrl+D)
        switch (option)
        {
        case 1:
            {
                // Downloading the data of previously saved pet and placed it to vector
                std::vector<std::string> pet_data{load_previous_pet()};
                if (pet_data.size() == 0) {  // If there is no previous data, a new pet will be created
                    std::cout << "\nNo previous pet's data was found!\n\n";
                    create_pet(pet);
                    std::cout << "\nA new pet created! Name: " << pet.name 
                              << " and type: " << pet.type << "\n";
                    stay_in_loop = false;
                    break;
                }
                // Pet-struct-values are initialized with the previously saved data (from the vector)
                pet = {
                    pet_data[0], 
                    pet_data[1], 
                    std::stoi(pet_data[2]), 
                    std::stoi(pet_data[3]), 
                    std::stoi(pet_data[4])
                    };
                stay_in_loop = false;  // break out from while-loop
            }
            break;
        
        case 2:
            {
                // Creating a new pet and printing the status
                create_pet(pet);
                std::cout << "\nA new pet created! Name: " << pet.name 
                << " and type: " << pet.type << "\n";
                stay_in_loop = false;
            }
            break;
        
        default:
            {
                std::cout << "\nInvalid input! Please choose the number from options.\n\n";
            }
            break;
        }
    }
    
    while (true) {  // Second "menu" after getting the pet data
    std::cout << "\nWhat would you like to do next?\n";
    std::cout << "(1) Feed " << pet.name << " (increases happiness and fullness)\n";
    std::cout << "(2) Play " << pet.name << " (increases happiness and decreases energy)\n";
    std::cout << "(3) Put " << pet.name << " sleep (increases energy)\n";
    std::cout << "(4) View statistics\n";
    std::cout << "(5) Save and exit\n";
    int choice{};
    std::cin >> choice;
    clear_failed_cin();

        switch (choice)
        {
        case 1:  // Feeding and printing the status
            {
                feed_pet(pet);
                std::cout << "\n";
                std::cout << pet.name << ": \"Yum, yum!\"\n";
                std::cout << "Now your pet's happiness is " << pet.happiness
                          << " and fullness is " << pet.fullness << ".\n";
            }
            break;
        
        case 2:  // Playing and printing the status
            {
                play_pet(pet);
                std::cout << "\n";
                std::cout << pet.name << ": 'Yippee!'\n";
                std::cout << "Now your pet's happiness is " << pet.happiness 
                          << " and energy is " << pet.energy << ".\n";
            }
            break;

        case 3:  // Sleeping and printing the status
            {
                put_sleep(pet);
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
                save_state(pet);  // Before exiting, save the current pet data to a file
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