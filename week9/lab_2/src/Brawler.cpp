#include "Brawler.h"

Brawler::Brawler() {

}

Brawler::Brawler(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int punchDamage, int strength) : GameCharacter(name, health, weightLimit, weapon, armour, food, state), punchDamage_{punchDamage}, strength_{strength} {
}

void Brawler::SetPunchDamage(int damage) {
    punchDamage_ = punchDamage;
}

int Brawler::GetPunchDamage() const {
    return punchDamage_;
}

void Brawler::SetStrength(int strength) {
    strength_ = strength;
}

int Brawler::GetStrength() const {
    return strength_;
}

bool Brawler::Attack(GameCharacter& character) {
    std::cout << "Brawler ";
    return GameCharacter::Attack(character);

}

bool Brawler::Brawl(GameCharacter& character) {
    std::cout << "Brawler " << GameCharacter::GetCharacterName() << " is brawling" << character.getCharacterName() << std::endl;
    return true;

}

void Brawler::Sleep() {
    float currHealth = GameCharacter::getCharacterHealth();
    GameCharater::SetCharacterHealth(currHealth + (currHealth * 0.15));
    GameCharacter::SetCharacterState(CharacterState::Sleeping);
}
