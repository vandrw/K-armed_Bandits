/* K-Armed Bandits */

#include <iostream>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main(int argc, char **argv) {
    Parameters Params;       // A structure that contains the parameters of the program.
    double epsilon = 0;      // Epsilon value for the Epsilon-Greedy Algorithm.
    int debug = 1;

    if (debug != 1) {
        initParams(&Params, &epsilon);
    } else {
        Params.distrib = 1;
        Params.algorithm = 1;
        Params.K_arms = 10;
        epsilon = 0.01;
    }

    Bandit bandit(Params.algorithm, Params.distrib, Params.K_arms, epsilon);      // A class that represents the bandit.

    double *arms = new double[Params.K_arms];

    bandit.makeExperiment(arms);

    delete[] arms;

    return 0;
}