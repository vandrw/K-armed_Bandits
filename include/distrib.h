#ifndef DISTRIB_H
#define DISTRIB_H

int initializeArms(int K, int distrib, std::vector<double> &arms);

double rewardGaussian(double mean);
double rewardBernoulli(double p_a);

#endif