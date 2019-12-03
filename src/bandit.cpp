#include <random>
#include <iostream>
#include "bandit.h"
#include "distrib.h"

using namespace std;

Bandit::Bandit(int alg, int distrib, int K_arms, double eps) {
    algorithm = alg;
    K = K_arms;
    distribution = distrib;

    if (alg == 1) {
        epsilon = eps;
    }

    // Initializing the frequency array with zeros.
    armChoice = new double[K]();
}

void Bandit::makeExperiment(double arms[]) {
    double realMaxReward;

    for (int i=0; i<N; i++) {
        observedRewards = new double[K]();
        realMaxReward = initializeArms(K, arms);
        makeRun(arms);
    }

    printStats(arms);
}

void Bandit::makeRun(double arms[]) {
    for (int i=0; i<T; i++) {
        averageReward = (averageReward + makeStep(arms)) / 2;
    }

}

double Bandit::makeStep(double arms[]) {
    int rewardIndex;
    double reward;

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

    switch (distribution) {
        case 1:         // Normal
            reward = rewardGaussian(arms[rewardIndex]);
            break;
        case 2:         // Bernoulli
            reward = rewardBernoulli(arms[rewardIndex]);
            break;
    }

    armChoice[rewardIndex]++;
    
    if (observedRewards[rewardIndex] == 0) {
        observedRewards[rewardIndex] = reward;
    } else {
        observedRewards[rewardIndex] = (observedRewards[rewardIndex] + reward) / 2;
    }

    if (observedRewards[rewardIndex] > observedRewards[indexMaxReward]) {
        indexMaxReward = rewardIndex;
    }

    return reward;
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
    uniform_int_distribution<int> intDist(0, K-1);

    int choice = intDist(generator);

    return choice;
}

int Bandit::exploit() {
    return indexMaxReward;
}

void Bandit::printStats(double arms[]) { 
    cout << "The highest reward was found at position " 
         << indexMaxReward << " with a value of " << observedRewards[indexMaxReward] << "\n";

    cout << "The average reward of the bandit is " << averageReward << "\n";

    cout << "The choices were made as follows:\n\n";

    cout << "Index" << "\tNum. Choices" << "\t\tObserved" << "\tReal\n";
    for (int i=0; i<K;i++) {
        cout << " " << i << "\t" << armChoice[i] << "\t\t" << observedRewards[i] << "\t" << arms[i] << "\n";
    }
}
