/* This header contains the functions required to receive
 * the input from the user, to output and the parameters
 * related to the environment. */

#ifndef USER_H
#define USER_H

struct Parameters {
    int distrib;      // Distribution choice.
    int algorithm;    // Algorithm choice.
    int K_arms;      // Number of arms.
};

void initParams(Parameters *param, double *epsilon);

void printParams(Parameters param, double epsilon);

void printResults();

#endif /* USER_H */