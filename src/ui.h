#ifndef UI_H
#define UI_H

#include "game.h"

void showIntro();
void showStatus(const FighterStats& player, const FighterStats& boss);
void showPlayerMenu();
int getPlayerChoice();
void showEndMessage(bool playerWon);

#endif