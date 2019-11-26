/* K-Armed Bandits */

#include <iostream>
#include <cstring>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main(int argc, char **argv) {
    Bandit bandit;      // A class that represents the bandit.
    Parameters Param;   // A structure that contains the parameters of the program.
    float epsilon;      // Epsilon value for the Epsilon-Greedy Algorithm.

    if (strcmp(argv[1], "--debug") != 0) {
        initParams(&Param, &epsilon);
        printParams(Param, epsilon);
    } else {
        Param.distrib = 2;
        Param.algorithm = 1;
        Param.K_arms = 40;
        epsilon = 0.01;
    }

    float *arms = new float[Param.K_arms];

    if (Param.distrib == 1) {
        createGaussian(Param.K_arms, arms);
    } else {
        createBernoulli(Param.K_arms, arms);
    }

    if (strcmp(argv[1], "--debug") == 0) {
        cout << "\nReward values found in the arms:\n";
        for (int i=0; i<Param.K_arms; i++) {
            cout << arms[i] << " ";
        }
        cout << "\n";
    }

    delete[] arms;

    return 0;
}