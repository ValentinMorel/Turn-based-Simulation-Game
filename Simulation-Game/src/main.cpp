// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <thread>

#include "Game.h"
#include "Unit.h"
#include "Orc.h"
#include "Knight.h"
#include "Custom.h"
#include "Printer.h"
#include "Weapon.h"
#include "Sword.h"
#include "Axe.h"

int main()
{
    // welcome + intro message :)
    printHeader();

    while (true) {
        
        printMainMenu();
        int choice;
        std::cin >> choice;

        bool shouldExit = false;
        switch (choice) {
        case 1:
            printAutoBattleSimOrder();
            int fightOrder;
            std::cin >> fightOrder;


            switch (fightOrder) {
            case 1:
            {
                Weapon* orcWeapon = new Axe();
                Armor* orcShield = new Armor(0);
                Unit* player1 = new Orc("player 1", orcWeapon, orcShield);
                
                Weapon* knightWeapon = new Sword();
                Armor* knightShield = new Armor(50);
                Unit* player2 = new Knight("player 2", knightWeapon, knightShield);

                std::unique_ptr<Game> game(new Game(player1, player2));
                game->Run();
            }
            break;
            case 2:
            {
                Weapon* knightWeapon = new Sword();
                Armor* knightShield = new Armor(50);
                Unit* player1 = new Knight("player 1", knightWeapon, knightShield);
                
                Weapon* orcWeapon = new Axe();
                Armor* orcShield = new Armor(0);
                Unit* player2 = new Orc("player 2", orcWeapon, orcShield);
                
                std::unique_ptr<Game> game(new Game(player1, player2));
                game->Run();
            }
            break;
            default:
                std::cout << "Unknown choice, try again !" << std::endl;
                break;
            }
            break;

        case 2: 
            while (true)
            {
                printCreationMenu();
                int choice;
                std::cin >> choice;

                switch (choice) {
                case 1:
                {
                    //const std::string& name, const std::string& nick, int health, int shield, const std::string& weapon, int damage, const std::string& spellChoice
                    std::string player1Name;
                    std::string player1Nick;
                    int player1Health;
                    int player1Shield;
                    std::string player1WeaponName;
                    int player1Damage;
                    std::string player1SpellChoice;
                    int player1SuccessOdd;

                    std::cout << "\nCREATING THE 1ST PLAYER:" << std::endl;
                    DefineInputForCharCreation(player1Name, player1Nick, player1Health, player1Shield, player1WeaponName, player1Damage, player1SpellChoice, player1SuccessOdd);

                    std::string player2Name;
                    std::string player2Nick;
                    int player2Health;
                    int player2Shield;
                    std::string player2WeaponName;
                    int player2Damage;
                    std::string player2SpellChoice;
                    int player2SuccessOdd;

                    std::cout << "\nCREATING THE 2ND PLAYER:" << std::endl;
                    DefineInputForCharCreation(player2Name, player2Nick, player2Health, player2Shield, player2WeaponName, player2Damage, player2SpellChoice, player2SuccessOdd);
                    
                    
                    Weapon* player1Weapon = new Weapon(player1WeaponName, player1Damage);
                    Armor* player1Armor = new Armor(player1Shield);
                    Custom* player1 = new Custom(player1Name, player1Nick, player1Health, player1Armor, player1Weapon, player1SpellChoice, player1SuccessOdd);

                    Weapon* player2Weapon = new Weapon(player2WeaponName, player2Damage);
                    Armor* player2Armor = new Armor(player2Shield);
                    Custom* player2 = new Custom(player2Name, player2Nick, player2Health, player2Armor, player2Weapon, player2SpellChoice, player2SuccessOdd);
                    
                    std::unique_ptr<Game> game(new Game(player1, player2));
                    game->Run();

                }
                break;
                default:
                    std::cout << "Unknown choice, try again" << std::endl;
                    break;
                }
                if (choice == 2) {
                    break;
                }
            }
            break;
            
        case 3:
            exit(0);
        }
    }
}


