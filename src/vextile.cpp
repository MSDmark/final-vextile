#include <iostream>
#include <cstdlib>
#include "vextile.h"
#include "combat.h"

void initVextileState(VextileState& state)
{
    state.lastEffect = -1;
    state.playerHitStreak = 0;
    state.stolenStat = -1;
    state.stealTurnsLeft = 0;
    state.stolenValue = 0;
}

void handleVextilePassive(FighterStats& boss, FighterStats& player, VextileState& state)
{
    int effect = std::rand() % 4;
    int value = 1;

    if (effect == state.lastEffect)
    {
        value = 2;
        std::cout << "Opakovany efekt. Zmena je dvojnasobna.\n";
    }

    switch (effect)
    {
        case 0:
            boss.attack += value;
            std::cout << "Vextile zvysil utok o " << value << ".\n";
            break;
        case 1:
            boss.defense += value;
            std::cout << "Vextile zvysil obranu o " << value << ".\n";
            break;
        case 2:
            boss.regeneration += value;
            std::cout << "Vextile zvysil regeneraci o " << value << ".\n";
            break;
        case 3:
            boss.critChance += value * 5;
            std::cout << "Vextile zvysil sanci na kriticky zasah o " << value * 5 << "%.
";
            break;
    }

    state.lastEffect = effect;

    int resetRoll = std::rand() % 100;
    if (resetRoll < 10)
    {
        resetPlayerBonuses(player);
        std::cout << "Vextile resetoval hracovy bonusy.\n";
    }

    if (state.playerHitStreak >= 3 && state.stealTurnsLeft == 0)
    {
        int stolen = std::rand() % 4;
        state.stolenStat = stolen;
        state.stealTurnsLeft = 2;
        state.stolenValue = 0;

        switch (stolen)
        {
            case 0:
                state.stolenValue = 2;
                if (player.attack < state.stolenValue)
                {
                    state.stolenValue = player.attack;
                }
                player.attack -= state.stolenValue;
                boss.attack += state.stolenValue;
                std::cout << "Vextile ukradl hraci utok na 2 kola.\n";
                break;

            case 1:
                state.stolenValue = 1;
                if (player.defense < state.stolenValue)
                {
                    state.stolenValue = player.defense;
                }
                player.defense -= state.stolenValue;
                boss.defense += state.stolenValue;
                std::cout << "Vextile ukradl hraci obranu na 2 kola.\n";
                break;

            case 2:
                state.stolenValue = 1;
                if (player.regeneration < state.stolenValue)
                {
                    state.stolenValue = player.regeneration;
                }
                player.regeneration -= state.stolenValue;
                boss.regeneration += state.stolenValue;
                std::cout << "Vextile ukradl hraci regeneraci na 2 kola.\n";
                break;

            case 3:
                state.stolenValue = 5;
                if (player.critChance < state.stolenValue)
                {
                    state.stolenValue = player.critChance;
                }
                player.critChance -= state.stolenValue;
                boss.critChance += state.stolenValue;
                std::cout << "Vextile ukradl hraci kritickou sanci na 2 kola.\n";
                break;
        }

        state.playerHitStreak = 0;
    }
}

void updateHitStreak(VextileState& state, bool hitSuccess)
{
    if (hitSuccess)
    {
        state.playerHitStreak++;
    }
    else
    {
        state.playerHitStreak = 0;
    }
}

void updateStealEffect(FighterStats& player, FighterStats& boss, VextileState& state)
{
    if (state.stealTurnsLeft > 0)
    {
        state.stealTurnsLeft--;

        if (state.stealTurnsLeft == 0)
        {
            switch (state.stolenStat)
            {
                case 0:
                    player.attack += state.stolenValue;
                    boss.attack -= state.stolenValue;
                    break;
                case 1:
                    player.defense += state.stolenValue;
                    boss.defense -= state.stolenValue;
                    break;
                case 2:
                    player.regeneration += state.stolenValue;
                    boss.regeneration -= state.stolenValue;
                    break;
                case 3:
                    player.critChance += state.stolenValue;
                    boss.critChance -= state.stolenValue;
                    break;
            }

            std::cout << "Ukradena statistika byla vracena.\n";
            state.stolenStat = -1;
            state.stolenValue = 0;
        }
    }
}
