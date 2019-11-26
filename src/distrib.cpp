#include <random>
#include <iostream>

using namespace std;

/* The Gaussian(Normal) distribution will return a
 * float number based on a distribution with a mean
 * 0 and standard deviation 1. */
void createGaussian(int K, float arms[]) {
    random_device generator;
    normal_distribution<double> normal(0,1);

    for (int i=0; i<K; i++) {
        arms[i] = normal(generator);
    }

    for (int i=0; i<K; i++) {
        cout << arms[i] << " ";
    }
    cout << "\n";
}

/* The Bernoulli distribution will return an integer
 * (either 0 or 1). [CONTINUE]*/
void createBernoulli(int K, float arms[]) {
    random_device generator;
    uniform_real_distribution<float> realDist(0.0, 1.0);

    // Initializing a random p_a.
    float p_a = realDist(generator);

    cout << "p_a = " << p_a << "\n";

    bernoulli_distribution bernoulli(p_a);

    for (int i=0; i<K; i++) {
        arms[i] = bernoulli(generator);
    }
}