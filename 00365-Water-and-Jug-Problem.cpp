#include <bits/stdc++.h>

using namespace std;

//365. 水壶问题
//
//        有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
//
//如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
//
//你允许：
//
//装满任意一个水壶
//        清空任意一个水壶
//从一个水壶向另外一个水壶倒水，直到装满或者倒空
//
//        示例 1: (From the famous "Die Hard" example)
//
//输入: x = 3, y = 5, z = 4
//输出: True
//
//        示例 2:
//
//输入: x = 2, y = 6, z = 5
//输出: False


//class Solution {
//public:
//    bool canMeasureWater(int x, int y, int z) {
//        unordered_map<int, unordered_set<int>> g;
//        g[0].insert(0);
//        queue<pair<int, int>> q;
//        q.emplace(0, 0);
//        while (!q.empty()) {
//            auto[a, b]=q.front();
//            q.pop();
//            if (a + b == z)
//                return true;
//            int aa = x, bb = b;
//            if (!g[aa].count(bb)) {
//                g[aa].insert(bb);
//                q.emplace(aa, bb);
//            }
//            aa = a, bb = y;
//            if (!g[aa].count(bb)) {
//                g[aa].insert(bb);
//                q.emplace(aa, bb);
//            }
//            aa = 0, bb = b;
//            if (!g[aa].count(bb)) {
//                g[aa].insert(bb);
//                q.emplace(aa, bb);
//            }
//            aa = a, bb = 0;
//            if (!g[aa].count(bb)) {
//                g[aa].insert(bb);
//                q.emplace(aa, bb);
//            }
//            if (a >= y - b) {
//                aa = a - (y - b);
//                bb = y;
//            } else {
//                aa = 0;
//                bb = b + a;
//            }
//            if (!g[aa].count(bb)) {
//                g[aa].insert(bb);
//                q.emplace(aa, bb);
//            }
//            if (b >= x - a) {
//                aa = x;
//                bb = b - (x - a);
//            } else {
//                aa = a + b;
//                bb = 0;
//            }
//            if (!g[aa].count(bb)) {
//                g[aa].insert(bb);
//                q.emplace(aa, bb);
//            }
//        }
//        return false;
//    }
//};

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        return z == 0 || z % __gcd(x, y) == 0;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

