#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "character.cpp"
using namespace std;



int main() {
    srand(time(0));  // so rand() doesn't use same sequence

    OptimusPrime optimus;
    Megatron megatron;

    Character* attacker = &optimus;
    Character* opponent = &megatron;

    cout << "The battle begins: Optimus Prime vs Megatron! \n";

    while (optimus.isAlive() && megatron.isAlive()) {
        attacker->attack(*opponent);

        if (!opponent->isAlive()) {
            cout << "\n" << attacker->getName() << " Wins the battle! \n";
            break;
        }

        // Switch turns
        if (attacker == &optimus) {
            attacker = &megatron;
            opponent = &optimus;
        } else {
            attacker = &optimus;
            opponent = &megatron;
        }

        cout << "<<<<<<<<<.....>>>>>>>>>>\n";
    }
}
