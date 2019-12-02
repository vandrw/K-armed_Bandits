#include <random>
#include <iostream>
#include "bandit.h"

using namespace std;

Bandit::Bandit(int alg, int K_arms, double eps) {
    algorithm = alg;
    K = K_arms;

    if (alg == 1) {
        epsilon = eps;
    }

    // Initializing the frequency array with zeros.
    armChoice = new double[K]();
}

void Bandit::makeExperiment(double arms[]) {
    for (int i=0; i<N; i++) {
        makeRun(arms);
    }

    printStats(arms);
}

void Bandit::makeRun(double arms[]) {
    for (int i=0; i<T; i++) {
        totalReward += makeStep(arms);
    }

}

double Bandit::makeStep(double arms[]) {
    int rewardIndex;

    switch (algorithm) {
        case 1:         // Epsilon-Greedy
            rewardIndex = EpsilonGreedy();
            break;
        case 2:         // Optimistic initial values
            break;
        case 3:         // Reinforcement comparison
             break;
        case 4:         // Pursuit methods
            break;
    }

    if (arms[rewardIndex] > arms[indexMaxReward]) {
        indexMaxReward = rewardIndex;
    }

    armChoice[rewardIndex]++;
    return arms[rewardIndex];
}

// Exporation/Expoilation algorithms

int Bandit::EpsilonGreedy() {
    random_device generator;
    uniform_real_distribution<double> realDist(0.0, 1.0);

    double rewardIndex;

    double check = realDist(generator);


    if (check <= epsilon) {
        rewardIndex = explore();
    } else {
        rewardIndex = exploit();
    }

    return rewardIndex;
}
void Bandit::OptimisticInit() {

}
void Bandit::ReinforcementCompar() {

}
void Bandit::Pursuit() {

}

int Bandit::explore() {
    random_device generator;
    uniform_int_distribution<int> intDist(0, K);

    int choice = intDist(generator);

    return choice;
}

int Bandit::exploit() {
    return indexMaxReward;
}

void Bandit::printStats(double arms[]) { 
    cout << "The highest reward was found at position " 
         << indexMaxReward << " with a value of " << arms[indexMaxReward] << "\n";

    cout << "The total reward of the bandit is " << totalReward << "\n";

    cout << "The choices were made as follows:\n";
    for (int i=0; i<K;i++) {
        cout << "\t" << i;
    }

    cout << "\n";

    for (int i=0; i<K;i++) {
        cout << "\t" << armChoice[i];
    } 

    cout << "\n";
}
