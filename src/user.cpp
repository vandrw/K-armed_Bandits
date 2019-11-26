#include <iostream>
#include "user.h"

using namespace std;

void initParams(Parameters *param, float *epsilon) {

    for (int i=0; i<=22; i++) {cout << "#";}

    cout << "\n### K-Armed Bandits ###\n";

    for (int i=0; i<=22; i++) {cout << "#";}

    cout << "\nChoose the type of distribution you want to use (1 or 2, default = Gaussian)\n";
    cout << "1. Gaussian (Normal)\n2. Bernoulli\n> ";
    if (std::cin.peek() == '\n') {
        param->distrib = 1;
        cin.clear();
        cin.ignore(256, '\n');
    } else {
        cin >> param->distrib;
        if ((param-> distrib > 2) || (param->distrib < 1)) {
            param->distrib = 1;
        }
        cin.clear();
        cin.ignore(256, '\n');
    }

    cout << "\nChoose the number of arms (K) for the problem (default = 5)";
    cout << "\n> ";
    if (std::cin.peek() == '\n') {
        param->K_arms = 5;
        cin.clear();
        cin.ignore(256, '\n');
    } else {
        cin >> param->K_arms;
        cin.clear();
        cin.ignore(256, '\n');
    }

    cout << "\nChoose an algorithm that deals with the exploration / exploitation dilemma (1-4, default = Epsilon-Greedy)\n";
    cout << "1. Epsilon-Greedy\n";
    cout << "2. Optimistic initial values\n";
    cout << "3. Reinforcement comparison\n";
    cout << "4. Boltzmann exploration\n> ";
    if (std::cin.peek() == '\n') {
        param->algorithm = 1;
        cin.clear();
        cin.ignore(256, '\n');
    } else {
        cin >> param->algorithm;
        if ((param-> distrib > 4) || (param->distrib < 1)) {
            param->distrib = 1;
        }
        cin.clear();
        cin.ignore(256, '\n');
    }

    if (param->algorithm == 1) {
        cout << "\nChoose an epsillon value between 0 and 1 (default = 0.01)\n> ";
        if (std::cin.peek() == '\n') {
            *(epsilon) = 0.01;
            cin.clear();
        } else {
            cin >> *(epsilon);
            cin.clear();
            cin.ignore(256, '\n');
        }
        while ((*(epsilon) > 1) || (*(epsilon) < 0)) {
            cout << "\nChoose an epsillon value between 0 and 1 (default = 0.01)\n> ";
            cin >> *(epsilon);
            cin.clear();
            cin.ignore(256, '\n');
        }
    } else {
        *(epsilon) = 0;
    }
}

void printParams(Parameters param, float epsilon) {
    cout << "\n   The parameters you have chosen are:\n";
    cout << "Distribution:\t";
    switch (param.distrib) {
        case 1:
            cout << "Gaussian (Normal)\n";
            break;
        case 2:
            cout << "Bernoulli\n";
            break;
    }
    cout << "Algorithm:\t";
    switch (param.algorithm) {
        case 1:
            cout << "Epsilon-Greedy\n";
            break;
        case 2:
            cout << "Optimistic initial values\n";
            break;
        case 3:
             cout << "Reinforcement comparison\n";
             break;
        case 4:
            cout << "Boltzmann exploration\n";
            break;
    }

    cout << "Number of arms:\t" << param.K_arms << "\n";
    if (param.algorithm == 1) {
        cout << "Epsilon =\t" << epsilon << "\n";
    }

    cout << "\n  Parameters for this simulation:\n";
    cout << "T =\t" << param.T << "\t| Number of action selections.\n";
    cout << "N =\t" << param.N << "\t| Number of runs.\n";
}

void printResults() {
    // TO-DO
}