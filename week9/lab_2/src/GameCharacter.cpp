#include "GameCharacter.h"

GameCharacter::GameCharacter() {
	characterName_ = "Default character";
    health_ = 100;
    weightLimit_ = 50.0f;
    food_ = 100;
    state_ = CharacterState::Idle;

    Weapon defaultWeapon("Stick", 5, 1.0f, 5, 100);
    weapon_ = defaultWeapon;

    Armour defaultArmour("Inner", 5, 1.0f, 5, 100, ArmourType::Cardboard);
    armour_ = defaultArmour;

    std::cout << "A game character called " << characterName_ << " has been born\n";
}

GameCharacter::GameCharacter(std::string name, float health, float weight, Weapon weapon, Armour armour, int food, CharacterState state) : charactername_{name}, health_{health}, weightLimit_{weight}, weapon_(weapon}, armour_{armour}, food_{food}, state_{state} {
    std::cout << "A game character called " << characterName_ << " has been born\n";
}

void GameCharacter::SetCharacterName(std::string name) {
    characterName_ = name;
}

std::string GameCharacter::GetCharacterName() const {
    return characterName_;
}

void GameCharacter::SetCharacterHealth(float health) {
    health_ = health;
}

float GameCharacter::GetCharacterHealth() const {
    return health_;
}

void GameCharacter::SetCharacterWeightLimit(float weightLimit) {
    weightLimit_ = weightLimit;
}

float GameCharacter::GetCharacterWeightLimit() const {
    return weightLimit_;
}

void GameCharacter::SetCharacterWeapon(Weapon weapon) {
    weapon_ = weapon;
}

Weapon GameCharacter::GetCharacterWeapon() const {
    return weapon_;
}

void GameCharacter::SetCharacterArmour(Armour armour) {
    armour_ = armour;
}

Armour GameCharacter::GetCharacterArmour() const {
    return armour_;
}

void GameCharacter::SetCharacterFood(int food) {
    food_ = food;
}

int GameCharacter::GetCharacterFood() const {
    return food_;
}

void GameCharacter::SetCharacterState(CharacterState state) {
    state_ = state;
}

CharacterState GameCharacter::GetCharacterState() const {
    return state_;
}

void GameCharacter::AddFood(int amount) {
    food_ =+ amount;
}

void GameCharacter::Eat() {
    if(food_ >= 4) {
        health_ += 1;
        food_ -= 4;
    } else if(food_ > 0) {
        health_ += (food_ * 0.25);
        food_ -= food_;
    }
}

bool GameCharacter::Attack(GameCharacter& character) {
    std::cout << characterName_ << " is attacking " << character.GetCharacterName() << " with a " << weapon_.getWeapon();
    state_ = characterState::Attacking;
    return true;
}

void GameCharacter::Defend() {
    std::cout <<  characterName_ << " is defending themselves with a " << armour_.ToString() << std::endl;
    state_ = characterState::Defending;
}

void GameCharacter::Walk() {
    state_ = characterState::Walking;
}

void GameCharacter::Run() {
    state_ = characterState::Running;
}

void GameCharacter::Sleep() {
    state_ = characterState::Sleeping;
}
