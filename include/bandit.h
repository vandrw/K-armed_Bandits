#ifndef BANDIT_H
#define BANDIT_H

#include "user.h"

class Bandit {
    public:

    // Simulation Parameters
    int counter = 0;
    int       T = 10000;                    // Number of action selections.
    int       N = 1000;                     // Number of runs.

    // User Parameters
    int     algorithm;
    int     K;
    int     distribution;
    double  epsilon=0;
    double  optimisticValue=0;

    // Observed Parameters
    int    indexMaxReward = 0;              // Index of the action with the highest reward.
    double averageReward = 0;               // Average of the accumulated rewards.
    std::vector<double> observedRewards;
    std::vector<int> armChoice;             // Array with the arm frequency (how often each was chosen).

    // Arm Parameters
    double realMaxIndex;                    // Not used by the bandit.
    std::vector<double> allRewards;
    std::vector<int> optimalChoice;

    Bandit(Parameters param);

    void makeExperiment(std::vector<double> &arms);
    void makeRun(std::vector<double> &arms);
    double makeStep(std::vector<double> &arms);

    // Exporation/Expoilation algorithms

    int EpsilonGreedy();
    int OptimisticInit();
    void ReinforcementCompar();
    void Pursuit();

    int explore();
    int exploit();

    void printStats(std::vector<double> &arms);
};

#endif /* BANDIT_H */