#include <iostream>
#include "bandit.h"

using namespace std;

Bandit::Bandit() {
    setStrategy(1);    
}

Bandit::Bandit(int inpStrat) {
        setStrategy(inpStrat);
}

void Bandit::printMax() {
    cout << "Max reward is: " << MaxReward << "\n";
}

void Bandit::setStrategy(int strat) {
    strategy = strat;
}