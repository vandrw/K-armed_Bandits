/* K-Armed Bandits */

#include <iostream>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main(int argc, char **argv) {
    Bandit bandit;      // A class that represents the bandit.
    Parameters Param;   // A structure that contains the parameters of the program.
    float epsilon;      // Epsilon value for the Epsilon-Greedy Algorithm.
    int debug = 1;

    if (debug != 1) {
        initParams(&Param, &epsilon);
        printParams(Param, epsilon);
    } else {
        Param.distrib = 1;
        Param.algorithm = 1;
        Param.K_arms = 10;
        epsilon = 0.01;
    }

    float *arms = new float[Param.K_arms];

    if (Param.distrib == 1) {
        createGaussian(Param.K_arms, arms);
    } else {
        createBernoulli(Param.K_arms, arms);
    }

    if (debug == 1)  {
        cout << "\nReward values found in the arms:\n";
        for (int i=0; i<Param.K_arms; i++) {
            cout << arms[i] << " ";
        }
        cout << "\n";
    }

    delete[] arms;

    return 0;
}