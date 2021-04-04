#include <bits/stdc++.h>

using namespace std;

//351. 安卓系统手势解锁
//
//        我们都知道安卓有个手势解锁的界面，是一个 3 x 3 的点所绘制出来的网格。用户可以设置一个 “解锁模式” ，通过连接特定序列中的点，形成一系列彼此连接的线段，每个线段的端点都是序列中两个连续的点。如果满足以下两个条件，则 k 点序列是有效的解锁模式：
//
//解锁模式中的所有点 互不相同 。
//假如模式中两个连续点的线段需要经过其他点，那么要经过的点必须事先出现在序列中（已经经过），不能跨过任何还未被经过的点。
//
//
//
//以下是一些有效和无效解锁模式的示例：
//
//
//
//无效手势：[4,1,3,6] ，连接点 1 和点 3 时经过了未被连接过的 2 号点。
//无效手势：[4,1,9,2] ，连接点 1 和点 9 时经过了未被连接过的 5 号点。
//有效手势：[2,4,1,3,6] ，连接点 1 和点 3 是有效的，因为虽然它经过了点 2 ，但是点 2 在该手势中之前已经被连过了。
//有效手势：[6,5,4,1,9,2] ，连接点 1 和点 9 是有效的，因为虽然它经过了按键 5 ，但是点 5 在该手势中之前已经被连过了。
//
//给你两个整数，分别为 ​​m 和 n ，那么请你统计一下有多少种 不同且有效的解锁模式 ，是 至少 需要经过 m 个点，但是 不超过 n 个点的。
//
//两个解锁模式 不同 需满足：经过的点不同或者经过点的顺序不同。
//
//
//
//示例 1：
//
//输入：m = 1, n = 1
//输出：9
//
//示例 2：
//
//输入：m = 1, n = 2
//输出：65
//
//
//
//提示：
//
//1 <= m, n <= 9


class Solution {
private:
    int m, n;
    vector<bool> vis;

    bool check(int pre, int cur) {
        if (pre == -1)
            return true;
        int x = pre / 3, y = pre % 3;
        int nx = cur / 3, ny = cur % 3;
        if (y == ny) {
            if (x > nx)
                swap(x, nx);
            for (int i = x + 1; i < nx; ++i) {
                if (!vis[i * 3 + y])
                    return false;
            }
        } else if (x == nx) {
            if (y > ny)
                swap(y, ny);
            for (int i = y + 1; i < ny; ++i) {
                if (!vis[x * 3 + i])
                    return false;
            }
        } else if (abs(x - nx) == abs(y - ny)) {
            int d = (x - nx) / (y - ny);
            if (x > nx)
                swap(x, nx), swap(y, ny);
            for (int i = 1; i < nx - x; ++i) {
                int x1 = x + i;
                int y1 = y + i * d;
                if (!vis[x1 * 3 + y1])
                    return false;
            }
        }
        return true;
    }

    int dfs(int pre, int k) {
        if (k == 0)
            return 1;
        --k;
        int res = 0;
        for (int i = 0; i < 9; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                if (check(pre, i))
                    res += dfs(i, k);
                vis[i] = false;
            }
        }
        return res;
    }

public:
    int numberOfPatterns(int m, int n) {
        this->m = m;
        this->n = n;
        vis.resize(9, false);
        int res = 0;
        for (int k = m; k <= n; ++k)
            res += dfs(-1, k);
        return res;
    }
};

int main(int argc, char *argv[]){

    return 0;
}

