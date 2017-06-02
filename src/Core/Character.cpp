//
// Created by Erik Karlsson on 5/30/17.
//

#include "Character.h"

Character::Character(int totalHealth, int remainingHealth, int attack, int speed, int defense, int resistance,
                     const string &name) : totalHealth(totalHealth), remainingHealth(remainingHealth), attack(attack),
                                           speed(speed), defense(defense), resistance(resistance), name(name)
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

void Character::attackCharacter(Character &opponent)
{

}
