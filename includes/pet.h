#ifndef PET_H
#define PET_H

#include <iostream>

struct Pet {
    std::string name;
    std::string type;
    int happiness{5};
    int fullness{5};
};

void create_pet(struct Pet& pet);
void feed_pet(struct Pet& pet);

#endif