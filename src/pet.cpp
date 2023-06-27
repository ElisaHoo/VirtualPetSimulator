#include "../includes/pet.h"

void clear_failed_cin() {
    if(!std::cin) { // User didn't input number -> cin fails
        std::cin.clear();  // clear cin's failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}

std::string get_pet_name() {
    std::cout << "Please enter your pet's name: ";
    std::string pet_name;
    std::cin >> std::ws;
    std::getline(std::cin, pet_name);
    return pet_name;
}

std::string get_pet_type() {
    std::cout << "Please enter your pet's type: ";
    std::string pet_type;
    std::cin >> std::ws; // to get rid of the possible white spaces before input
    std::getline(std::cin, pet_type);
    return pet_type;
}

void create_pet(Pet& pet) {
    pet.name = get_pet_name();
    pet.type = get_pet_type();
}

int increase_happiness(int happiness) {
    happiness += 1;
    return happiness;
}

int increase_fullness(int fullness) {
    fullness += 1;
    return fullness;
}

int decrease_energy(int energy) {
    energy -= 1;
    return energy;
}

int increase_energy (int energy) {
    energy += 1;
    return energy;
}

void feed_pet(Pet& pet) {
    // Use "increasing -functions" to update values, give base value as argument
    pet.happiness = increase_happiness(pet.happiness);
    pet.fullness = increase_fullness(pet.fullness);
}

void play_pet(Pet& pet) {
    pet.happiness = increase_happiness(pet.happiness);
    pet.energy = decrease_energy(pet.energy);
}

void put_sleep(Pet& pet) {
    pet.energy = increase_energy(pet.energy);
}

void view_statistics(Pet pet) {
    std::cout << "\nYour pet's happiness is " << pet.happiness 
              << ", fullness is " << pet.fullness 
              << " and energy is " << pet.energy 
              << ".\n";
    if (pet.energy <= 0) {
        std::cout << "\nWARNING! Your pet is exhausted, you should put it to sleep.\n";
    }
}

void save_state(Pet pet) {
    std::ofstream write_file{"pet.csv"};
    if (!write_file.is_open()) {
        throw std::runtime_error("Couldn't open the file!");
    }
    // Writing struct values to file, each to their own line
    write_file << pet.name << "\n" 
               << pet.type << "\n"
               << pet.happiness << "\n" 
               << pet.fullness << "\n" 
               << pet.energy;
    std::cout << "\nPet's current state is saved to a csv-file!\n";
    write_file.close();
}

std::vector<std::string> load_previous_pet() {
    std::vector<std::string> file_contents{};
    std::ifstream read_file{"pet.csv"};
    if (!read_file.is_open()) {
        throw std::runtime_error("Couldn't opet the file!");
    }
    std::string line{};
    // Reading and pushing the data to a vector from a file (as string)
    while (read_file >> line) {
        file_contents.push_back(line);
    }
    read_file.close();
    // Returning the file data to the main along with the vector
    return file_contents;
}