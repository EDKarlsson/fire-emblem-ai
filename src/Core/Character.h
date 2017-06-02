//
// Created by Erik Karlsson on 5/30/17.
//

#ifndef FIRE_EMBLEM_AI_CHARACTER_H
#define FIRE_EMBLEM_AI_CHARACTER_H

#include <string>

using namespace std;

enum WeaponColor
{
    RED,
    BLUE,
    GREEN,
    NEUTRAL
};

enum WeaponType
{
    SWORD,
    TOME,
    AXE,
    LANCE,
    BOWS,
    STAVES,
    DAGGERS,
    BREATH
};

enum MovementType
{
    INFANTRY,
    CAVALRY,
    FLYING,
    ARMORED
};

class Character
{
    public:
        Character(int totalHealth, int remainingHealth, int attack, int speed, int defense, int resistance,
                  const string &name);

        void attackCharacter(Character &opponent);

        /* Getters */
        int getTotalHealth() const;

        int getRemainingHealth() const;

        int getAttack() const;

        int getSpeed() const;

        int getDefense() const;

        int getResistance() const;

        const string &getName() const;

        /* Setters */
        void setName(const string &name);

        void setResistance(int resistance);

        void setDefense(int defense);

        void setSpeed(int speed);

        void setAttack(int attack);

        void setRemainingHealth(int remainingHealth);

        void setTotalHealth(int totalHealth);

    private:
        int          totalHealth,
                     remainingHealth,
                     attack,
                     speed,
                     defense,
                     resistance;
        MovementType moveType;
        WeaponColor  weaponColor;
        WeaponType   weaponType;
        string       name;
        int          specialCounter;
};

#endif //FIRE_EMBLEM_AI_CHARACTER_H
