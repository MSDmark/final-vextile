#ifndef VEXTILE_H
#define VEXTILE_H

#include "game.h"

void initVextileState(VextileState& state);
void handleVextilePassive(FighterStats& boss, FighterStats& player, VextileState& state);
void updateHitStreak(VextileState& state, bool hitSuccess);
void updateStealEffect(FighterStats& player, FighterStats& boss, VextileState& state);

#endif
