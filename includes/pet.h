#ifndef PET_H
#define PET_H

#include <iostream>

struct Pet {
    std::string name;
    std::string type;
    int happiness{5}; //Initial values are 5
    int fullness{5};
    int energy{5};
};

void create_pet(struct Pet& pet);
void feed_pet(struct Pet& pet);
void play_pet(struct Pet& pet);
int put_sleep(int energy);

#endif