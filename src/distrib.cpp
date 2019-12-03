#include <random>
#include <iostream>
#include "user.h"
#include "distrib.h"

using namespace std;

double rewardGaussian(double mean) {
    random_device generator;
    normal_distribution<double> normal(mean,1);

    return normal(generator);
}

double rewardBernoulli(double p_a) {
    random_device generator;
    bernoulli_distribution bernoulli(p_a);

    return bernoulli(generator);
}

/* The Gaussian(Normal) distribution will return a
 * double number based on a distribution with a mean
 * 0 and standard deviation 1 for each arm. */
int initializeArms(int K, double arms[]) {
    random_device generator;
    normal_distribution<double> normal(0,1);
    double maxReward = -5;
    int maxRewardId;

    for (int i=0; i<K; i++) {
        arms[i] = normal(generator);
        if (arms[i] > maxReward) {
            maxReward = arms[i];
            maxRewardId = i;
        }
    }

    return maxRewardId;
}