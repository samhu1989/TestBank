#include <iostream>
#include "countingbits.h"
using namespace std;

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> r = solution.countBits(3000);
    if( ( solution.popcount_hakmem(137)!=r[137] ) || ( solution.popcount_lut(137)!=r[137] ) )
    {
        std::cerr<<"count all:"<<r[137]<<std::endl;
        std::cerr<<"hakmem:"<<solution.popcount_hakmem(137)<<std::endl;
        std::cerr<<"lut:"<<solution.popcount_lut(137)<<std::endl;
    }
    std::cerr<<std::endl;
    return 0;
}
