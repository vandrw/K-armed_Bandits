#ifndef BANDIT_H
#define BANDIT_H

#include "user.h"

class Bandit {
    public:

    // Simulation Parameters
    int           simCounter = 0;
    int                    T = 10000;      // Number of action selections.
    int                    N = 1000;       // Number of runs.

    // User Parameters
    int           algorithm;
    int                   K;
    int        distribution;
    double          epsilon = 0;
    double  optimisticValue = 0;
    double    exploreDegree = 0;
    double            alpha = 0;
    double            betav = 0;

    // Observed Parameters
    int             counter = 0;            // Counter used in the UCB algorithm.
    int      indexMaxReward = 0;            // Index of the action with the highest reward.
    double  referenceReward = 0;            // Average of the accumulated rewards ().
    std::vector<double> observedRewards;    // Vector with the average rewards observed by the bandit.
    std::vector<int> armChoice;             // Vector with the arm frequency (how often each was chosen).
    std::vector<double> armPreference;      // Vector containing the preference of each arm (Reinforcement Comparison).

    // Arm Parameters
    double realMaxIndex;                    // Not used by the bandit.
    std::vector<double> allRewards;
    std::vector<int> optimalChoice;

    Bandit(Parameters param);

    void reinitBandit();

    void makeExperiment(std::vector<double> &arms);
    void makeRun(std::vector<double> &arms);
    double makeStep(std::vector<double> &arms);

    // Exporation/Expoilation algorithms

    int EpsilonGreedy();
    int OptimisticInit();
    int ReinforcementCompar();
    int UCB();

    int explore();
    int exploit();

    void printStats(std::vector<double> &arms);
};

#endif /* BANDIT_H */