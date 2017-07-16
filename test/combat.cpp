//
// Created by Erik Karlsson on 6/2/17.
//

#include "combat.h"

void combat::test_attack_01()
{

    Character azura("Azura", 37, 37, 44, 34, 18, 32, INFANTRY, BLUE, LANCE);
    Character ryoma("Ryoma", 42, 42, 50, 36, 23, 24, INFANTRY, RED, SWORD);

    azura.attackCharacter(ryoma);
}
