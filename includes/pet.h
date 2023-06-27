#ifndef PET_H
#define PET_H

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

struct Pet {
    std::string name;
    std::string type;
    int happiness{0};
    int fullness{0};
    int energy{2};
};

void clear_failed_cin();
std::string get_pet_name();
std::string get_pet_type();
void create_pet(Pet& pet);
int increase_happiness(int happiness);
int increase_fullness(int fullness);
int decrease_energy(int energy);
int increase_energy (int energy);
void feed_pet(Pet& pet);
void play_pet(Pet& pet);
void put_sleep(Pet& pet);
void view_statistics(Pet pet);
void save_state(Pet pet);
std::vector<std::string> load_previous_pet();

#endif