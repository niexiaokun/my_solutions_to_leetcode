#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//793. 阶乘函数后K个零
//
//f(x) 是 x! 末尾是0的数量。（回想一下 x! = 1 * 2 * 3 * ... * x，且0! = 1）
//
//例如， f(3) = 0 ，因为3! = 6的末尾没有0；而 f(11) = 2 ，因为11!= 39916800末端有2个0。给定 K，找出多少个非负整数x ，有 f(x) = K 的性质。
//
//示例 1:
//输入:K = 0
//输出:5
//解释: 0!, 1!, 2!, 3!, and 4! 均符合 K = 0 的条件。
//
//示例 2:
//输入:K = 5
//输出:0
//解释:没有匹配到这样的 x!，符合K = 5 的条件。
//
//注意：
//
//K是范围在 [0, 10^9] 的整数。


class Solution {
private:
    long long trailingZeroes(long long n) {
        // int res=0;
        // while(n){
        //     res+=n/5;
        //     n/=5;
        // }
        // return res;
        if(n==0)
            return 0;
        return n/5+trailingZeroes(n/5);
    }
public:
    int preimageSizeFZF(long long K) {
        long long l=K,r=10*K+1;
        long long mid,m;
        while(l<r){
            mid=(r-l)/2+l;
            m=trailingZeroes(mid);
            if(m==K)
                return 5;
            else if(m<K)
                l=mid+1;
            else
                r=mid;
        }
        return 0;
    }
};




int main(int argc, char *argv[]){

    int K = 1000000000;
    cout<<Solution().preimageSizeFZF(K)<<endl;

    return 0;
}