#include <iostream>
#include <string>
#include "Printer.h"
#include "Armor.h"
#include "Weapon.h"

void printHeader() {
    std::cout << "##############################################################################" << std::endl;
    std::cout << "#                                                                            #" << std::endl;
    std::cout << "#                   WELCOME TO THE SIMULATION BATTLE SYSTEM                  #" << std::endl;
    std::cout << "#                                                                            #" << std::endl;
    std::cout << "##############################################################################" << std::endl;
    std::cout << "\n\n" << std::endl;

    std::cout << "2 Characters are AVAILABLE !\n\n" << std::endl;
    std::cout << "    +---------------- - +---------------- - +" << std::endl;
    std::cout << "    | Knight            |  Orc              |" << std::endl;
    std::cout << "    +---------------- - +------------------ +" << std::endl;
    std::cout << "    | Health: 20        | Health: 60        |" << std::endl;
    std::cout << "    | Shield: 50        | Shield: 0         |" << std::endl;
    std::cout << "    | Weapon: sword     | Weapon: axe       |" << std::endl;
    std::cout << "    | Damage: 5         | Damage: 8         |" << std::endl;
    std::cout << "    | Spell: Charge     | Spell: Stun       |" << std::endl;
    std::cout << "    +---------------- - +------------------ +" << std::endl;

    std::cout << "\n\nYou can also create your own battle, with your own classes !\n\n" << std::endl;

}


void printMainMenu() {
    std::cout << "\nMain menu \n" << std::endl;
    std::cout << "\t 1 - Automatic battle simulation (Orc vs Knight)" << std::endl;
    std::cout << "\t 2 - Create your own battle simulation" << std::endl;
    std::cout << "\t 3 - Exit" << std::endl;
    std::cout << "\nChoice: ";
}

void printAutoBattleSimOrder() {
    std::cout << "\nWho starts first?" << std::endl;
    std::cout << "\t1 - Orc" << std::endl;
    std::cout << "\t2 - Knight" << std::endl;
    std::cout << "\nChoice: ";
}


void printCreationMenu() {
    std::cout << "\nCreation Menu \n" << std::endl;
    std::cout << "\t 1 - Create 1st player" << std::endl;
    std::cout << "\t 2 - Return to main menu" << std::endl;
    std::cout << "\nChoice: ";
}

void DefineInputForCharCreation(std::string& name, std::string& nick, int& health, int& armor, std::string& weapon, int& damage, std::string& spellChoice, int& successOdd) {

    std::cout << "\nname: ";
    std::cin >> name;

    std::cout << "\nnick: ";
    std::cin >> nick;

    std::cout << "\nhealth: ";
    std::cin >> health;

    std::cout << "\nshield: ";
    std::cin >> armor;

    std::cout << "\nweapon: ";
    std::cin >> weapon;

    std::cout << "\ndamage: ";
    std::cin >> damage;

    std::cout << "\nspell (stun, charge, combo): ";
    std::cin >> spellChoice;

    std::cout << "\nspell success probability in %: ";
    std::cin >> successOdd;
}
