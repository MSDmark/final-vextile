#include <iostream>
#include "game.h"
#include "combat.h"
#include "vextile.h"
#include "ui.h"

void runGame()
{
    FighterStats player;
    player.hp = 50;
    player.maxHp = 50;
    player.attack = 10;
    player.defense = 3;
    player.regeneration = 2;
    player.critChance = 15;

    FighterStats boss;
    boss.hp = 60;
    boss.maxHp = 60;
    boss.attack = 9;
    boss.defense = 2;
    boss.regeneration = 2;
    boss.critChance = 10;

    VextileState state;
    initVextileState(state);

    showIntro();

    while (player.hp > 0 && boss.hp > 0)
    {
        bool hitSuccess = false;

        showStatus(player, boss);
        showPlayerMenu();

        int choice = getPlayerChoice();

        switch (choice)
        {
            case 1:
                playerAttack(player, boss, hitSuccess);
                break;
            case 2:
                std::cout << "You defend and prepare for the next attack.\n";
                player.defense += 1;
                break;
            case 3:
                std::cout << "You rest and recover.\n";
                applyRegeneration(player);
                break;
        }

        updateHitStreak(state, hitSuccess);

        if (boss.hp <= 0)
        {
            break;
        }

        handleVextilePassive(boss, player, state);
        applyRegeneration(boss);
        bossAttack(boss, player);
        updateStealEffect(player, state);

        if (choice == 2)
        {
            player.defense -= 1;
        }
    }

    showEndMessage(player.hp > 0);
}