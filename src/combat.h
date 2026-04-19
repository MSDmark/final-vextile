#ifndef COMBAT_H
#define COMBAT_H

#include "game.h"

int calculateDamage(int attack, int defense);
bool checkCriticalHit(int critChance);
void playerAttack(FighterStats& player, FighterStats& boss, bool& hitSuccess);
void bossAttack(FighterStats& boss, FighterStats& player);
void applyRegeneration(FighterStats& fighter);
void resetPlayerBonuses(FighterStats& player);

#endif