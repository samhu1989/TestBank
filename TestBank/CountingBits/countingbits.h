#ifndef COUNTINGBITS_H
#define COUNTINGBITS_H
#include "countingbits_global.h"
#include <vector>
using namespace std;
/*338. Counting Bits
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 * Follow up:
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 * Hint:
 * 1.You should make use of what you have produced already.
 * 2.Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
 * 3.Or does the odd/even status of the number help you in calculating the number of 1s?
 */
class COUNTINGBITSSHARED_EXPORT Solution
{
public:
    vector<int> countBits(int num);
    inline int popcount_lut(uint32_t x){
        int i, ret = 0;
        for (i = 0; i < 32; i += 8)
            ret += lut[(x >> i) & 0xff];
        return ret;
    }
    inline int popcount_hakmem(uint32_t x) {
        unsigned int n;
        n = (x >> 1) & m1;
        x = x - n;
        n = (n >> 1) & m1;
        x = x - n;
        x = (x + (x >> 3)) & m3;
        return x%63;
    }
private:
    const uint32_t h01 = 0x01010101;
    const uint32_t m1  = 033333333333;
    const uint32_t m2  = 011111111111;
    const uint32_t m3  = 030707070707;
    const int lut[256] =
    {
        0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
        1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
        1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
        2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
        1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
        2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
        2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
        3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8
    };
};

#endif // COUNTINGBITS_H
