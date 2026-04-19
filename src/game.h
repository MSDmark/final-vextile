#ifndef GAME_H
#define GAME_H

struct FighterStats
{
    int hp;
    int maxHp;
    int attack;
    int defense;
    int regeneration;
    int critChance;
};

struct VextileState
{
    int lastEffect;
    int playerHitStreak;
    int stolenStat;
    int stealTurnsLeft;
};

void runGame();

#endif