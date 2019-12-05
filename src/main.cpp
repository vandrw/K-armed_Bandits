/* K-Armed Bandits */

#include <iostream>
#include <vector>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main(int argc, char **argv) {
    Parameters Params;       // A structure that contains the parameters of the program.
    int debug = 1;

    if (debug != 1) {
        initParams(&Params);
    } else {
        Params.distrib = 1;
        Params.algorithm = 4;
        Params.K_arms = 10;
        Params.epsilon = 0.01;
        Params.optimisticValue = 0;
        Params.exploreDegree = 1;
    }

    Bandit bandit(Params);      // A class that represents the bandit.

    std::vector<double> arms(Params.K_arms);

    bandit.makeExperiment(arms);

    exportToFile(bandit.allRewards, bandit.optimalChoice, Params);

    return 0;
}