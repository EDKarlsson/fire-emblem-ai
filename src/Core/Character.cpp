//
// Created by Erik Karlsson on 5/30/17.
//

#include "Character.h"

Character::Character(const string &name, int totalHealth, int remainingHealth, int attack, int speed, int defense,
                     int resistance, MovementType moveType, WeaponColor weaponColor, WeaponType weaponType)
        : totalHealth(totalHealth), remainingHealth(remainingHealth), attack(attack),
          speed(speed), defense(defense), resistance(resistance), moveType(moveType),
          weaponColor(weaponColor), weaponType(weaponType), name(name),
          specialCounter(0)
{}

int Character::getTotalHealth() const
{
    return totalHealth;
}

void Character::setTotalHealth(int totalHealth)
{
    Character::totalHealth = totalHealth;
}

int Character::getRemainingHealth() const
{
    return remainingHealth;
}

void Character::setRemainingHealth(int remainingHealth)
{
    Character::remainingHealth = remainingHealth;
}

int Character::getAttack() const
{
    return attack;
}

void Character::setAttack(int attack)
{
    Character::attack = attack;
}

int Character::getSpeed() const
{
    return speed;
}

void Character::setSpeed(int speed)
{
    Character::speed = speed;
}

int Character::getDefense() const
{
    return defense;
}

void Character::setDefense(int defense)
{
    Character::defense = defense;
}

int Character::getResistance() const
{
    return resistance;
}

void Character::setResistance(int resistance)
{
    Character::resistance = resistance;
}

const string &Character::getName() const
{
    return name;
}

void Character::setName(const string &name)
{
    Character::name = name;
}

bool Character::rangedAttackAllowed()
{
    bool canAttack = false;
    switch (this->weaponType)
    {
        case weapon::SWORD:
        case weapon::AXE:
        case weapon::LANCE:
        case weapon::DAGGERS:
        case weapon::BREATH:
            break;
        case weapon::TOME:
        case weapon::BOWS:
        case weapon::STAVES:
            canAttack = true;
    }
    return canAttack;
}

bool Character::canCounter()
{
   return false;
}
/*
 * Need to decide if this method will handle the range check.
 * I wonder if I should assume that it
 */
void Character::attackCharacter(Character &opponent)
{
    cout << name << " attacks " << opponent.getName() << endl;
    /*
     * Things to check during combat
     * 1. Color triangle
     * 2. Speed
     *  - if 5 greater than opponent, attack twice.
     * 3. Skills
     * 4. Defense
     * 5. Attack
     * 6. Special
     * 7. Range
     */


}

