# Vextile

Školní projekt v C++.

Jde o jednoduchou konzolovou tahovou hru proti bossovi jménem Vextile. Hráč a boss se střídají po kolech, průběžně se počítá poškození, obrana, regenerace a další efekty.

Hlavní zvláštnost bosse je práce se statistikami. Vextile si každé kolo náhodně upraví jednu statistiku. Pokud padne stejný efekt jako v minulém kole, změna se zesílí. Kromě toho má malou šanci zrušit hráčovy bonusy a po sérii zásahů dokáže na omezenou dobu převzít jednu hráčovu statistiku.

Projekt je zatím řešený jednoduše přes funkce a více souborů, bez tříd. Cílem je mít přehlednou a postupně rozšiřitelnou verzi, která odpovídá zadání.

## Aktuální stav

- základní herní smyčka,
- tah hráče,
- tah bosse,
- výpis statistik,
- náhodné změny boss statů,
- opakovaný efekt se zesílením,
- reset hráčových bonusů,
- dočasné kradení statistik,
- základní systém hráčských bonusů.

## Překlad

```bash
g++ src/*.cpp -o vextile
```

## Spuštění

```bash
./vextile
```

## Poznámka

Některé části se ještě můžou upravit podle dalšího vývoje projektu.
