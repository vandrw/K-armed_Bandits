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
            armPreference.resize(K, 0.0);
            alpha = param.alpha;
            betav = param.beta;
            break;
        case 4:
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
    counter = 0;

    std::fill(observedRewards.begin(), observedRewards.end(), optimisticValue);
    std::fill(armChoice.begin(), armChoice.end(), 0);

    if (algorithm == 3) {
        std::fill(armPreference.begin(), armPreference.end(), 0.0);
        referenceReward = 1.5;
    }
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
        makeStep(arms);
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
            rewardIndex = ReinforcementCompar();
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
        optimalChoice[simCounter] = 1;
    } else {
        optimalChoice[simCounter] = 0;
    }

    allRewards[simCounter] = reward;

    simCounter++;
    counter++;

    if (observedRewards[rewardIndex] == 0) {
        observedRewards[rewardIndex] = reward;
    } else {
        observedRewards[rewardIndex] = (observedRewards[rewardIndex] + reward) / 2;
    }

    if ((algorithm != 4) && (algorithm != 3)) {
        if (observedRewards[rewardIndex] > observedRewards[indexMaxReward]) {
            indexMaxReward = rewardIndex;
        }
    }
    if (algorithm == 3) {
        armPreference[indexMaxReward] += betav * (reward - referenceReward);
        referenceReward = referenceReward +  alpha * (reward - referenceReward);
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

int Bandit::ReinforcementCompar() {
    random_device generator;
    uniform_real_distribution<double> realDist(0.0, 1.0);

    double sumExp=0.0;
    double prob, maxProb=-10.0;

    int rewardIndex;
    double check = realDist(generator);

    for (int i=0; i<K; i++) {
        sumExp += exp(armPreference[i]);
    }

    for (int i=0; i<K; i++) {
        prob = exp(armPreference[i])/ sumExp;
        if ( prob > maxProb ) {
            maxProb = prob;
            indexMaxReward = i;
        }
    }

    if (check <= armPreference[indexMaxReward]) {
        rewardIndex = explore();
    } else {
        rewardIndex = indexMaxReward;
    }

    return rewardIndex;
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

    cout << "The choices were made as follows:\n\n";

    cout << "Index" << "\tNum. Choices" << "\tObserved" << "\tReal\n";
    for (int i=0; i<K;i++) {
        cout << " " << i << "\t" << armChoice[i] << "\t\t" << observedRewards[i] << "\t" << arms[i] << "\n";
    }
}
