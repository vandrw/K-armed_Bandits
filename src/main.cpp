/* K-Armed Bandits */

#include <iostream>
#include <vector>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main(int argc, char **argv) {
    Parameters Params;       // A structure that contains the parameters of the program.
    double optimisticValue = 0;
    int debug = 1;

    if (debug != 1) {
        initParams(&Params);
    } else {
        Params.distrib = 2;
        Params.algorithm = 2;
        Params.K_arms = 15;
        Params.epsilon = 0.01;
        Params.optimisticValue = 5;
    }

    Bandit bandit(Params);      // A class that represents the bandit.

    std::vector<double> arms(Params.K_arms);

    bandit.makeExperiment(arms);

    exportToFile(bandit.allRewards, bandit.optimalChoice, Params);

    return 0;
}