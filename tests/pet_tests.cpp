#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h"
#include "../includes/pet.h"

TEST_CASE("Tests for pet.cpp") {
    Pet test_pet = {.name = "testSpot", .type = "testDog", .happiness = 10, .fullness = 20, .energy = 30};
    SUBCASE("increases/decreases -functions are working") {
        CHECK(increase_happiness(3) == 4);
        CHECK(increase_fullness(0) == 1);
        CHECK(decrease_energy(-2) == -3);
        CHECK(increase_energy(64) == 65);
    }
    SUBCASE("After using feed_pet -function, happiness and fullness increases") {
        feed_pet(test_pet);
        CHECK(test_pet.happiness == 11);
        CHECK(test_pet.fullness == 21);
        CHECK(test_pet.energy == 30);
    }
    SUBCASE("After using play_pet -function, happiness increases and energy decreases") {
        play_pet(test_pet);
        CHECK(test_pet.happiness == 11);
        CHECK(test_pet.energy == 29);
        CHECK(test_pet.fullness == 20);
    }
    SUBCASE("After using put_sleep -function, energy increases") {
        put_sleep(test_pet);
        CHECK(test_pet.energy == 31);
        CHECK(test_pet.happiness == 10);
        CHECK(test_pet.fullness == 20);
    }
    SUBCASE("view_statistics -function is showing values from the Pet-struct") {
        CHECK(test_pet.happiness == 10);
        CHECK(test_pet.energy == 30);
        CHECK(test_pet.fullness == 20);
    }
    SUBCASE("save_state -function is writing a file with correct values and load_previos_pet is reading them") {
        save_state(test_pet);
        std::vector<std::string> file_contents{load_previous_pet()};
        CHECK(test_pet.name == file_contents[0]);
        CHECK(test_pet.type == file_contents[1]);
        CHECK(test_pet.happiness == std::stoi(file_contents[2]));
        CHECK(test_pet.fullness == std::stoi(file_contents[3]));
        CHECK(test_pet.energy == std::stoi(file_contents[4]));
    }
}