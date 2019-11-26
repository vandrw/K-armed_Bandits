/* K-Armed Bandits */

#include <iostream>
#include "bandit.h"
#include "user.h"
#include "distrib.h"

using namespace std;

int main() {
    Bandit bandit;
    Parameters Param;
    float epsilon;

    // initParams(&Param, &epsilon);

    // printParams(Param, epsilon);

    createGaussian();

    createBernoulli();

    return 0;
}