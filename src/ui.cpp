#include <iostream>
#include <limits>
#include "ui.h"

void showIntro()
{
    std::cout << "=== Vextile ===\n";
    std::cout << "Konzolovy tahovy souboj.\n\n";
}

void showStatus(const FighterStats& player, const FighterStats& boss)
{
    std::cout << "\n--- Stav ---\n";
    std::cout << "Hrac HP: " << player.hp << "/" << player.maxHp << "\n";
    std::cout << "Hrac  ATK: " << player.attack
              << "  DEF: " << player.defense
              << "  REG: " << player.regeneration
              << "  CRIT: " << player.critChance << "%\n\n";

    std::cout << "Vextile HP: " << boss.hp << "/" << boss.maxHp << "\n";
    std::cout << "Boss    ATK: " << boss.attack
              << "  DEF: " << boss.defense
              << "  REG: " << boss.regeneration
              << "  CRIT: " << boss.critChance << "%\n";
}

void showPlayerMenu()
{
    std::cout << "\nVyber akci:\n";
    std::cout << "1. Utok\n";
    std::cout << "2. Obrana\n";
    std::cout << "3. Zvysit utok\n";
    std::cout << "4. Zvysit obranu\n";
    std::cout << "Volba: ";
}

int getPlayerChoice()
{
    int choice;

    while (true)
    {
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neplatny vstup. Zadej 1 az 4: ";
            continue;
        }

        if (choice >= 1 && choice <= 4)
        {
            return choice;
        }

        std::cout << "Neplatna volba. Zadej 1 az 4: ";
    }
}

void showEndMessage(bool playerWon)
{
    std::cout << "\n=== Konec hry ===\n";

    if (playerWon)
    {
        std::cout << "Boss byl porazen.\n";
    }
    else
    {
        std::cout << "Hrac prohral.\n";
    }
}
