/* K-Armed Bandits */

#include <iostream>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main(int argc, char **argv) {
    Parameters Params;   // A structure that contains the parameters of the program.
    double epsilon = 0;      // Epsilon value for the Epsilon-Greedy Algorithm.
    int debug = 1;

    if (debug != 1) {
        initParams(&Params, &epsilon);
        printParams(Params, epsilon);
    } else {
        Params.distrib = 2;
        Params.algorithm = 1;
        Params.K_arms = 10;
        epsilon = 0.01;
    }

    Bandit bandit(Params.algorithm, Params.K_arms, epsilon);      // A class that represents the bandit.

    double *arms = new double[Params.K_arms];

    initializeArms(Params.K_arms, Params.distrib, arms);

    if (debug == 1)  {
        cout << "\nReward values found in the arms:\n";
        for (int i=0; i<Params.K_arms; i++) {
            cout << arms[i] << " ";
        }
        cout << "\n\n";
    }

    bandit.makeExperiment(arms);

    delete[] arms;

    return 0;
}