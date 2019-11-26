/* This header contains the functions required to receive
 * the input from the user, to output and the parameters
 * related to the environment. */

#ifndef USER_H
#define USER_H

struct Parameters {
    int distrib;      // Distribution choice.
    int algorithm;    // Algorithm choice.
    int K_arms;      // Number of arms.
    int T = 10000;      // Number of action selections.
    int N = 1000;       // Number of runs.
};

void initParams(Parameters *param, float *epsilon);

void printParams(Parameters param, float epsilon);

void printResults();

#endif /* USER_H */