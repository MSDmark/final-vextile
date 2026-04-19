#include <iostream>
#include <cstdlib>
#include "combat.h"

int calculateDamage(int attack, int defense)
{
    int damage = attack - defense;

    if (damage < 1)
    {
        damage = 1;
    }

    return damage;
}

bool checkCriticalHit(int critChance)
{
    int roll = std::rand() % 100;
    return roll < critChance;
}

void playerAttack(FighterStats& player, FighterStats& boss, bool& hitSuccess)
{
    int damage = calculateDamage(player.attack, boss.defense);

    if (checkCriticalHit(player.critChance))
    {
        damage *= 2;
        std::cout << "Kriticky zasah.\n";
    }

    boss.hp -= damage;

    if (boss.hp < 0)
    {
        boss.hp = 0;
    }

    std::cout << "Hrac udelil " << damage << " poskozeni.\n";
    hitSuccess = true;
}

void bossAttack(FighterStats& boss, FighterStats& player)
{
    int damage = calculateDamage(boss.attack, player.defense);

    if (checkCriticalHit(boss.critChance))
    {
        damage *= 2;
        std::cout << "Boss zasahl kriticky.\n";
    }

    player.hp -= damage;

    if (player.hp < 0)
    {
        player.hp = 0;
    }

    std::cout << "Boss udelil " << damage << " poskozeni.\n";
}