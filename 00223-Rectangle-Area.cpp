#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = max(A, E);
        int y1 = min(D, H);
        int x2 = min(C, G);
        int y2 = max(B, F);
        long long sum = (long long) (C - A) * (D - B) + (long long) (G - E) * (H - F);
        if (x1 < x2 && y1 > y2)
            return sum - (x2 - x1) * (y1 - y2);
        return sum;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
