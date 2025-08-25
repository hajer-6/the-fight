#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "weapon.cpp"
using namespace std;



class Character {
protected:
    string name;
    int health;
    vector<Weapon> weapons;

public:
    Character(string n, vector<Weapon> w) : name(n), health(100), weapons(w) {}

    string getName() { 
        return name; 
    }
    int getHealth() {
         return health; 
        }
    bool isAlive() {
         return health > 0; 
        }

    void takeDamage(int dmg) { //to calculate damage
        health -= dmg;
        if (health < 0) health = 0;
    }

    // choose the weapon to attack
     void attack(Character &opponent) {
        cout << "\n" << name << "'s turn!\n";
        cout << "Choose a weapon:\n";

        for (int i = 0; i < weapons.size(); i++) {
            cout << i+1 << ". " << weapons[i].getName()
                 << " (Damage: " << weapons[i].getDamage()
                 << ", Accuracy: " << weapons[i].getAccuracy()*100 << "%)\n";
        }

        int choice;
        cout << "Enter choice (1-" << weapons.size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > weapons.size()) {
            cout << "Invalid choice! You missed your turn.\n";
            return;
        }

        Weapon &weapon = weapons[choice-1];
        pair<int,bool> result = weapon.use();
        int damage = result.first;
        bool hit = result.second;

        if (hit) {
            opponent.takeDamage(damage);
            cout << name << " hits " << opponent.getName()
                 << " with " << weapon.getName()
                 << " for " << damage << " damage!\n";
        } else {
            cout << name << "'s " << weapon.getName() << " missed!\n";
        }

        cout << opponent.getName() << " health: " << opponent.getHealth() << endl;
    }
};
//optimus prime inherites from character class

class OptimusPrime : public Character {
public:                  // the constructer 
    OptimusPrime() : Character("Optimus Prime", {
        Weapon("Ion Rifle", 6, 1.0),
        Weapon("Energon Swords", 12, 0.8),
        Weapon("Shoulder Cannon", 45, 0.25)
    }) {}
};
  

//megatron inherites from character class

class Megatron : public Character {
public:   // the constructor
    Megatron() : Character("Megatron", {
        Weapon("Fusion Cannon", 9, 0.9),
        Weapon("Fusion Sword", 18, 0.7),
        Weapon("Tank Mode", 60, 0.15)
    }) {}
};
