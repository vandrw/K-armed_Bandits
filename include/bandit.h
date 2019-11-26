#ifndef BANDIT_H
#define BANDIT_H

class Bandit {
    public:

    int MaxReward = 0;
    int strategy;

    Bandit();

    Bandit(int inpStrat);

    void printMax();

    void setStrategy(int strat);
};

#endif /* BANDIT_H */