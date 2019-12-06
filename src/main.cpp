/* K-Armed Bandits */

#include <iostream>
#include <vector>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main(int argc, char **argv) {
    Parameters Params;       // A structure that contains the parameters of the program.
    int arg1=0;
    int arg2=0;

    if (argc > 1) {
        
        for (int i = 1; i < argc; ++i) {
            if (arg1==0) {
                arg1=atoi(argv[i]);
            } else {
                arg2=atoi(argv[i]);
                break;
            }
        }
    }

    if (argc == 1) {
        initParams(&Params);
    } else {
        Params.distrib = arg1;
        Params.algorithm = arg2;
        Params.K_arms = 30;
        Params.epsilon = 0.01;
        Params.optimisticValue = 10;
        Params.exploreDegree = 2;
        Params.alpha= 1/Params.K_arms;
        Params.beta = 2;
    }

    Bandit bandit(Params);      // A class that represents the bandit.

    std::vector<double> arms(Params.K_arms);

    bandit.makeExperiment(arms);

    exportToFile(bandit.allRewards, bandit.optimalChoice, Params);

    return 0;
}