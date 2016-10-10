#include <iostream>
//#include "countingbits.h"
//#include "combinationofgivensum.h"
#include "countms.h"
using namespace std;
int main(int argc, char *argv[])
{
//    Solution solution;
//    std::vector<int> r = solution.countBits(3000);
//    if( ( solution.popcount_hakmem(137)!=r[137] ) || ( solution.popcount_lut(137)!=r[137] ) )
//    {
//        std::cerr<<"count all:"<<r[137]<<std::endl;
//        std::cerr<<"hakmem:"<<solution.popcount_hakmem(137)<<std::endl;
//        std::cerr<<"lut:"<<solution.popcount_lut(137)<<std::endl;
//    }
//    std::cerr<<std::endl;
//    std::vector<double> list = {1.0 , 2.0 , 3.0 , 4.0, 5.0};
//    Solution solution;
//    std::cerr<<solution.CombinationOfGivenSum(list,6.0)<<std::endl;
    Solution solution;
    std::string name = "./data/CountMS.txt";
    solution.count(name);
    return 0;
}
