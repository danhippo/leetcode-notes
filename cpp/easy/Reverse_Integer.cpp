#include<stdio.h>
#include<stdint.h>
#include<string>

using namespace std;
/// --- note --- ///
//pop operation:
//pop = x % 10;
//x /= 10;

//push operation:
//temp = rev * 10 + pop;
//rev = temp;
class Solution {
public:
    int reverse(int x) {
        int64_t temp=0;
        while (x!=0)
        {
            temp=temp*10+(x%10);
            x/=10;
        }
        return temp==(int32_t)temp?temp:0;
    }
};