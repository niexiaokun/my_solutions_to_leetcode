#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        if (m < n) {
            swap(a, b);
            swap(m, n);
        }
        int i = m - 1;
        int j = n - 1;
        string res;
        int jin = 0;
        while (i >= 0 && j >= 0) {
            int tmp = a[i] - '0' + b[j] - '0' + jin;
            jin = tmp / 2;
            res += ((tmp % 2) + '0');
            --i, --j;
        }
        while (i >= 0) {
            int tmp = a[i] - '0' + jin;
            jin = tmp / 2;
            res += ((tmp % 2) + '0');
            --i;
        }
        if (jin)
            res += jin + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char* argv[]) {



    return 0;
}

