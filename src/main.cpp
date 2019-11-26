/* K-Armed Bandits */

#include <iostream>
#include "bandit.h"
#include "user.h"

using namespace std;

int main() {
    Bandit bandit;
    Parameters Param;
    float epsilon;

    initParams(&Param, &epsilon);

    printParams(Param, epsilon);

    return 0;
}