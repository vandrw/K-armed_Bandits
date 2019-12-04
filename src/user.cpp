#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "user.h"

using namespace std;

void initParams(Parameters *param) {

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
    cout << "4. Pursuit methods\n> ";
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
            param->epsilon = 0.01;
            cin.clear();
        } else {
            cin >> param->epsilon;
            cin.clear();
            cin.ignore(256, '\n');
        }
        while ((param->epsilon > 1) || (param->epsilon < 0)) {
            cout << "\nChoose an epsillon value between 0 and 1 (default = 0.01)\n> ";
            cin >> param->epsilon;
            cin.clear();
            cin.ignore(256, '\n');
        }
    } else if (param->algorithm == 2) {
         cout << "\nChoose an optimistic value (default = 5)\n> ";
        if (std::cin.peek() == '\n') {
            param->optimisticValue = 5;
            cin.clear();
        } else {
            cin >> param->optimisticValue;
            cin.clear();
            cin.ignore(256, '\n');
        }
    } else {
        param->epsilon = 0;
        param->optimisticValue = 0;
    }
}

void exportToFile(std::vector<double> allRewards, std::vector<int> optimalChoice, Parameters param) {
    ofstream fileReward;
    ofstream fileOptimal;

    string filename;

    filename.append("data/");
    filename.append(to_string(param.K_arms));

    switch(param.distrib) {
        case 1:
            {
                filename.append("_Gaussian_");
                break;
            }
        case 2:
            {
                filename.append("_Bernoulli_");
                break;
            }
    }

    switch (param.algorithm) {
        case 1:
            {
                filename.append("EpsilonGreedy_");
                filename.append(to_string(param.epsilon));
                break;
            }
        case 2:
            {
                filename.append("OptimisticInit_");
                filename.append(to_string(param.optimisticValue));
                break;
            }
        case 3:
            {
                filename.append("ReinfCompar");
                break;
            }
        case 4:
            {
                filename.append("Pursuit");
            }
    }

    fileReward.open(filename + "_Rewards.csv", std::ofstream::out);
    fileOptimal.open(filename + "_Optimal.csv", std::ofstream::out);

    fileReward.close();
    fileOptimal.close();
}