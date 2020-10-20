/*
 * main.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../inc/common.h"

#include "archer/Archer.h"
#include "warrior/Warrior.h"
#include "wizard/Wizard.h"

//#include "weapon/Weapon.h"

// Challenge Methods
void challenge1(); /* Crashing make the program crash on purpose. */
void challenge2(); /* Use an assert. Check if the two arrays are the same size. */
void challenge3(); /* Use an assert. Check if the two arrays are the same size. Wrapped in preprocessor. */
void challenge4(); /* Create two students to test Student.h */
void challenge5(); /* Implement a menu system */

// Other methods
void oldChallenge1();
bool fight(Warrior, Wizard);
float randomNumberGenerator();

// Main loop
int main() {
    oldChallenge1();
    //challenge2();
    //challenge3();
    //challenge4();

    // End program
    return 0;
}

void oldChallenge1() {
    Archer archer;
    archer.setName("Robbin Hood");
    archer.setHealth(100);
    archer.setCharType("Hero");
    archer.setLevel(5);

    Warrior warrior;
    warrior.setName("Finn");
    warrior.setHealth(100);
    warrior.setCharType("Hero");
    warrior.setLevel(5);

    Wizard wizard;
    wizard.setName("Harry Potter");
    wizard.setHealth(100);
    wizard.setCharType("Hero");
    wizard.setLevel(5);

    int warriorHealth = warrior.getHealth();
    int wizardHealth = wizard.getHealth();

    while(warriorHealth > 0 && wizardHealth > 0) {
        if(fight(warrior, wizard)) {
            wizard.setHealth(wizardHealth - 20);
        } else {
            warrior.setHealth(warriorHealth - 20);
        }

        warrior.printStatus();
        wizard.printStatus();

        warriorHealth = warrior.getHealth();
        wizardHealth = wizard.getHealth();
    }
}

bool fight(Warrior, Wizard) {
    float randNo = randomNumberGenerator(0.0, 1.0);

    if(randNo < 0.5)
        return true;
    else
        return false;

}

float randomNumberGenerator(float x, float y) {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_real_distribution<> distributor(x, y);

    return distributor(generator); /* Return final random number*/
}
