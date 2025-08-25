#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


class Weapon {
private:
    string name;
    int damage;
    double accuracy;   // chance to hit 

public:
    Weapon(string n, int d, double a) : name(n), damage(d), accuracy(a) {}

    string getName() {
         return name; 
        }

    int getDamage() {
         return damage;
         }

    double getAccuracy() {
         return accuracy;
         }

    pair<int,bool> use() {
        double roll = (double) rand() / RAND_MAX;
        if (roll <= accuracy) {
            return {damage, true};   // HIT
        }
        return {0, false};           // MISS
    }
};
