#ifndef BANDIT_H
#define BANDIT_H

class Bandit {
    public:

    // Simulation Parameters
    int counter = 0;
    int       T = 10000;      // Number of action selections.
    int       N = 1000;       // Number of runs.

    // User Parameters
    int     algorithm;
    int     K;
    int     distribution;
    double  epsilon=0;

    // Observed Parameters
    int    indexMaxReward = 0;      // Index of the action with the highest reward.
    double averageReward = 0;      // Total of the accumulated rewards.
    double *observedRewards;
    double *armChoice;           // Array with the arm frequency (how often each was chosen).

    // Arm Parameters
    double realMaxIndex;        // Not used by the bandit.
    double *totalRewards;
    int    *optimalChoice;

    Bandit(int algorithm, int K, int distribution, double epsilon);

    void makeExperiment(double arms[]);
    void makeRun(double arms[]);
    double makeStep(double arms[]);

    // Exporation/Expoilation algorithms

    int EpsilonGreedy();
    void OptimisticInit();
    void ReinforcementCompar();
    void Pursuit();

    int explore();
    int exploit();

    void printStats(double arms[]);
};

#endif /* BANDIT_H */