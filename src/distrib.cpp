#include <random>
#include <iostream>

using namespace std;

/* The Gaussian(Normal) distribution will return a
 * float number based on a distribution with a mean
 * 0 and standard deviation 1. */
float createGaussian() {
    random_device generator;
    normal_distribution<double> normal(0,1);

    //continue
    float num = normal(generator);

    cout << "\nRandom num Gaus: " << num << "\n";
    
    return 1;
}

/* The Bernoulli distribution will return an integer
 * (either 0 or 1). [CONTINUE]*/
int createBernoulli() {
    random_device generator;
    uniform_real_distribution<float> realDist(0.0, 1.0);

    // Initializing a random p_a.
    float p_a = realDist(generator);

    cout << "p_a = " << p_a << "\n";

    bernoulli_distribution bernoulli(p_a);

    cout << "Random num Bernoulli: " << bernoulli(generator) << "\n";

    return 1;

    //continue
}