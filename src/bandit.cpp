#include <random>
#include <iostream>
#include <vector>
#include <cmath>
#include "bandit.h"
#include "distrib.h"
#include "user.h"

using namespace std;

Bandit::Bandit(Parameters param) {
    algorithm = param.algorithm;
    K = param.K_arms;
    distribution = param.distrib;

    switch (algorithm) {
        case 1:
            epsilon = param.epsilon;
            break;
        case 2:
            optimisticValue = param.optimisticValue;
            break;
        case 3:
            exploreDegree = param.exploreDegree;
            break;
        default:
            break;
    }

    // If the algorithm chosen is not Optimistic Initial Values,
    // the optimisticValue variable will be set to 0, thus
    // initializing the observed rewards realistically.
    observedRewards.resize(K, optimisticValue);
    // Initializing the frequency array with zeros.
    armChoice.resize(K, 0);

    allRewards.resize(T*N, 0.0);
    optimalChoice.resize(T*N, 0);
}

void Bandit::reinitBandit() {
    std::fill(observedRewards.begin(), observedRewards.end(), optimisticValue);
    std::fill(armChoice.begin(), armChoice.end(), 0);
    counter = 0;
}

void Bandit::makeExperiment(std::vector<double> &arms) {
    for (int i=0; i<N; i++) {
        
        reinitBandit();

        realMaxIndex = initializeArms(K, distribution, arms);
        makeRun(arms);
    }

    printStats(arms);
}

void Bandit::makeRun(std::vector<double> &arms) {
    for (int i=0; i<T; i++) {
        averageReward = (averageReward + makeStep(arms)) / 2;
    }

}

double Bandit::makeStep(std::vector<double> &arms) {
    int rewardIndex;
    double reward;

    switch (algorithm) {
        case 1:         // Epsilon-Greedy
            rewardIndex = EpsilonGreedy();
            break;
        case 2:         // Optimistic initial values
            rewardIndex = OptimisticInit();
            break;
        case 3:         // Reinforcement comparison
             break;
        case 4:         // UCB
            rewardIndex = UCB();
            break;
        default:
            break;
    }

    switch (distribution) {
        case 1:         // Normal
            {
            reward = rewardGaussian(arms[rewardIndex]);
            break;
            }
        case 2:         // Bernoulli
            {
            reward = rewardBernoulli(arms[rewardIndex]);
            break;
            }
        default:
            {
            break;
            }
    }

    armChoice[rewardIndex]++;

    if (rewardIndex == realMaxIndex) {
        optimalChoice[counter] = 1;
    } else {
        optimalChoice[counter] = 0;
    }

    allRewards[counter] = reward;

    counter++;
    
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
int Bandit::OptimisticInit() {
    return exploit();
}
void Bandit::ReinforcementCompar() {
    
}
int Bandit::UCB() {
    int maxReward=-10;
    int rewardUCB;

    for (int i=0; i<K; i++) {
        if (armChoice[i] == 0) {
            return i;
        }
        rewardUCB = observedRewards[i] 
                  + exploreDegree 
                  * sqrt(log(counter) / armChoice[i]); 
        if (rewardUCB > maxReward) {
            maxReward = rewardUCB;
            indexMaxReward = i;
        }
    }

    return indexMaxReward;
}

int Bandit::explore() {
    random_device generator;
    uniform_int_distribution<int> intDist(0, K-1);

    int choice = intDist(generator);

    return choice;
}

int Bandit::exploit() {
    int maxReward=-10;

    for (int i=0; i<K; i++) {
        if (observedRewards[i] > maxReward) {
            maxReward = observedRewards[i];
            indexMaxReward = i;
        }
    }

    return indexMaxReward;
}

void Bandit::printStats(std::vector<double> &arms) {

    cout << "The average reward of the bandit is " << averageReward << "\n";

    cout << "The choices were made as follows:\n\n";

    cout << "Index" << "\tNum. Choices" << "\tObserved" << "\tReal\n";
    for (int i=0; i<K;i++) {
        cout << " " << i << "\t" << armChoice[i] << "\t\t" << observedRewards[i] << "\t" << arms[i] << "\n";
    }
}
