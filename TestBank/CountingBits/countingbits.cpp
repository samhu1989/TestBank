#include "countingbits.h"

vector<int> Solution::countBits(int num)
{
    vector<int> result(num+1);
    for(uint32_t x=0;x<=num;++x)
    {
        if(x<256)result[x]=lut[x];
        else if(x&1){
            result[x] = result[ x - 1 ] + 1;
        }
        else result[x] = result[x>>1];
    }
    return result;
}
