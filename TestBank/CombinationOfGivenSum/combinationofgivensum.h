#ifndef COMBINATIONOFGIVENSUM_H
#define COMBINATIONOFGIVENSUM_H
#include "combinationofgivensum_global.h"
#include <vector>
using namespace std;
class COMBINATIONOFGIVENSUMSHARED_EXPORT Solution
{
public:
    int CombinationOfGivenSum(const std::vector<double>& list, double sum);
protected:
    int compute(std::vector<double>::const_iterator s,std::vector<double>::const_iterator e,double sum);
};

#endif // COMBINATIONOFGIVENSUM_H
