#include <random>
#include <iostream>
#include <vector>
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
int initializeArms(int K, int distrib, std::vector<double> &arms) {
    random_device generator;
    double maxReward = -5;
    int maxRewardId;
    
    normal_distribution<double> normal(0,1);
    uniform_real_distribution<double> real(0.0, 1.0);

    switch (distrib) {
        case 1: {       // Normal
            for (int i=0; i<K; i++) {
                arms[i] = normal(generator);
                if (arms[i] > maxReward) {
                    maxReward = arms[i];
                    maxRewardId = i;
                }
            }
            break;
        }
        case 2: {
            for (int i=0; i<K; i++) {
                arms[i] = real(generator);
                if (arms[i] > maxReward) {
                    maxReward = arms[i];
                    maxRewardId = i;
                }
            }
            break;
        }
    }

    return maxRewardId;
}