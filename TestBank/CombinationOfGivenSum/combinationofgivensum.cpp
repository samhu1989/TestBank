#include "combinationofgivensum.h"

int Solution::CombinationOfGivenSum(const std::vector<double>& list, double sum)
{
    return compute(list.cbegin(),list.cend(),sum);
}

int Solution::compute(std::vector<double>::const_iterator s,std::vector<double>::const_iterator e,double sum)
{
    if( s == e )return 0;
    else if( *s  > sum ) return compute( s+1 , e , sum );
    else if( *s == sum ) return 1 + compute( s+1 , e , sum );
    else return compute( s+1 , e , sum ) + compute( s+1 , e , sum - *s );
}
