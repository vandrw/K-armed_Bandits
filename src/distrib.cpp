#include <random>
#include <iostream>
#include "user.h"
#include "distrib.h"

using namespace std;

void initializeArms(int K, int dist, double arms[]) {
    if (dist == 1) {
        createGaussian(K, arms);
    } else {
        createBernoulli(K, arms);
    }
}

/* The Gaussian(Normal) distribution will return a
 * double number based on a distribution with a mean
 * 0 and standard deviation 1. */
void createGaussian(int K, double arms[]) {
    random_device generator;
    normal_distribution<double> normal(0,1);

    for (int i=0; i<K; i++) {
        arms[i] = normal(generator);
    }
}

/* The Bernoulli distribution will return an integer
 * (either 0 or 1). [CONTINUE]*/
void createBernoulli(int K, double arms[]) {
    random_device generator;
    uniform_real_distribution<double> realDist(0.0, 1.0);

    // Initializing a random p_a.
    double p_a = realDist(generator);

    cout << "p_a = " << p_a << "\n";

    bernoulli_distribution bernoulli(p_a);

    for (int i=0; i<K; i++) {
        arms[i] = bernoulli(generator);
    }
}