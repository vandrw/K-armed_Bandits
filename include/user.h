/* This header contains the functions required to receive
 * the input from the user, to output and the parameters
 * related to the environment. */

#ifndef USER_H
#define USER_H

struct Parameters {
    int distrib;            // Distribution choice.
    int algorithm;          // Algorithm choice.
    int K_arms;             // Number of arms.
    double epsilon;         // Epsilon value for the Epsilon-Greedy algorithm.
    double optimisticValue; // Optimistic value for the Optimistic Initial Values algorithm.
    double alpha;           // Value that determines how much an action is weakened in Reinfocement Comparison.
    double beta;            // A positive step-size parameter in the Reinforcement Comparison algorithm.
    double exploreDegree;   // Number > 0, which controls the degree of exploration in UCB.
};

void initParams(Parameters *param);

void exportToFile(std::vector<double> allRewards, std::vector<int> optimalChoice, Parameters param);

#endif /* USER_H */