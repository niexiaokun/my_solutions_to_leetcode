#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        if (a > b)
            swap(a, b);
        if (a + b <= c)
            return a + b;
        return (a + b + c) / 2;
    }
};




int main(int argc, char* argv[]) {

    return 0;
}

