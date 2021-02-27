#include <bits/stdc++.h>

using namespace std;

//308. 二维区域和检索 - 可变
//
//        给你一个 2D 矩阵 matrix，请计算出从左上角 (row1, col1) 到右下角 (row2, col2) 组成的矩形中所有元素的和。
//
//Range Sum Query 2D
//上述粉色矩形框内的，该矩形由左上角 (row1, col1) = (2, 1) 和右下角 (row2, col2) = (4, 3) 确定。其中，所包括的元素总和 sum = 8。
//
//示例：
//
//给定 matrix = [
//[3, 0, 1, 4, 2],
//[5, 6, 3, 2, 1],
//[1, 2, 0, 1, 5],
//[4, 1, 0, 1, 7],
//[1, 0, 3, 0, 5]
//]
//
//sumRegion(2, 1, 4, 3) -> 8
//update(3, 2, 2)
//sumRegion(2, 1, 4, 3) -> 10
//
//
//
//注意:
//
//矩阵 matrix 的值只能通过 update 函数来进行修改
//        你可以默认 update 函数和 sumRegion 函数的调用次数是均匀分布的
//你可以默认 row1 ≤ row2，col1 ≤ col2


//class NumMatrix {
//private:
//    class segtree {
//    private:
//        int n;
//        vector<int> data, tree;
//
//        void buildSegTree(int treeIndex, int l, int r) {
//            if (l == r) {
//                tree[treeIndex] = data[l];
//                return;;
//            }
//            int mid = (l + r) / 2;
//            int leftTreeIndex = treeIndex * 2 + 1;
//            int rightTreeIndex = treeIndex * 2 + 2;
//            buildSegTree(leftTreeIndex, l, mid);
//            buildSegTree(rightTreeIndex, mid + 1, r);
//            tree[treeIndex] = tree[leftTreeIndex] + tree[rightTreeIndex];
//        }
//
//        void update(int treeIndex, int l, int r, int index, int val) {
//            if (l == r) {
//                tree[treeIndex] = val;
//                return;
//            }
//            int mid = (l + r) / 2;
//            int leftTreeIndex = treeIndex * 2 + 1;
//            int rightTreeIndex = treeIndex * 2 + 2;
//            if (mid >= index) {
//                update(leftTreeIndex, l, mid, index, val);
//            } else {
//                update(rightTreeIndex, mid + 1, r, index, val);
//            }
//            tree[treeIndex] = tree[leftTreeIndex] + tree[rightTreeIndex];
//        }
//
//        int query(int treeIndex, int l, int r, int queryL, int queryR) {
//            if (l == queryL && r == queryR) {
//                return tree[treeIndex];
//            }
//            int mid = (l + r) / 2;
//            int leftTreeIndex = treeIndex * 2 + 1;
//            int rightTreeIndex = treeIndex * 2 + 2;
//            if (mid >= queryR) {
//                return query(leftTreeIndex, l, mid, queryL, queryR);
//            } else if (mid < queryL) {
//                return query(rightTreeIndex, mid + 1, r, queryL, queryR);
//            } else {
//                return query(leftTreeIndex, l, mid, queryL, mid) + query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
//            }
//        }
//
//    public:
//        segtree(vector<int> &nums) {
//            data = nums;
//            n = data.size();
//            tree.resize(4 * n);
//            buildSegTree(0, 0, n - 1);
//        }
//
//        ~segtree() {}
//
//        void update(int index, int val) {
//            data[index] = val;
//            update(0, 0, n - 1, index, val);
//        }
//
//        int query(int queryL, int queryR) {
//            return query(0, 0, n - 1, queryL, queryR);
//        }
//    };
//
//    int m, n;
//    vector<segtree> treeVector;
//public:
//    NumMatrix(vector<vector<int>> &matrix) {
//        m = matrix.size();
//        if (m) {
//            n = matrix[0].size();
//            if (n) {
//                for (int i = 0; i < m; ++i)
//                    treeVector.emplace_back(segtree(matrix[i]));
//            }
//        }
//    }
//
//    void update(int row, int col, int val) {
//        treeVector[row].update(col, val);
//    }
//
//    int sumRegion(int row1, int col1, int row2, int col2) {
//        int res = 0;
//        for (int i = row1; i <= row2; ++i)
//            res += treeVector[i].query(col1, col2);
//        return res;
//    }
//};


//class NumMatrix {
//private:
//    vector<vector<int>> tree;
//    int m, n;
//
//    void buildSegmentTree(vector<vector<int>> &matrix, int rowIndex, int treeIndex, int l, int r) {
//        if (l == r) {
//            tree[rowIndex][treeIndex] = matrix[rowIndex][l];
//            return;;
//        }
//        int mid = (l + r) / 2;
//        int leftTreeIndex = treeIndex * 2 + 1;
//        int rightTreeIndex = treeIndex * 2 + 2;
//        buildSegmentTree(matrix, rowIndex, leftTreeIndex, l, mid);
//        buildSegmentTree(matrix, rowIndex, rightTreeIndex, mid + 1, r);
//        tree[rowIndex][treeIndex] = tree[rowIndex][leftTreeIndex] + tree[rowIndex][rightTreeIndex];
//    }
//
//    void __update(int treeIndex, int l, int r, int row, int col, int val) {
//        if (l == r) {
//            tree[row][treeIndex] = val;
//            return;
//        }
//        int mid = (l + r) / 2;
//        int leftTreeIndex = treeIndex * 2 + 1;
//        int rightTreeIndex = treeIndex * 2 + 2;
//        if (col <= mid)
//            __update(leftTreeIndex, l, mid, row, col, val);
//        else
//            __update(rightTreeIndex, mid + 1, r, row, col, val);
//        tree[row][treeIndex] = tree[row][leftTreeIndex] + tree[row][rightTreeIndex];
//    }
//
//    void change(int row, int col, int val) {
//        __update(0, 0, n - 1, row, col, val);
//    }
//
//    int __query(int row, int treeIndex, int l, int r, int queryL, int queryR) {
//        if (l == queryL && r == queryR) {
//            return tree[row][treeIndex];
//        }
//        int mid = (l + r) / 2;
//        int leftTreeIndex = treeIndex * 2 + 1;
//        int rightTreeIndex = treeIndex * 2 + 2;
//        if (mid >= queryR)
//            return __query(row, leftTreeIndex, l, mid, queryL, queryR);
//        else if (mid < queryL)
//            return __query(row, rightTreeIndex, mid + 1, r, queryL, queryR);
//        return __query(row, leftTreeIndex, l, mid, queryL, mid) +
//               __query(row, rightTreeIndex, mid + 1, r, mid + 1, queryR);
//    }
//
//    int query(int row1, int col1, int row2, int col2) {
//        int res = 0;
//        for (int i = row1; i <= row2; ++i)
//            res += __query(i, 0, 0, n - 1, col1, col2);
//        return res;
//    }
//
//public:
//    NumMatrix(vector<vector<int>> &matrix) {
//        m = matrix.size();
//        if (m) {
//            n = matrix[0].size();
//            if (n) {
//                tree.resize(m, vector<int>(n * 4));
//                for (int i = 0; i < m; ++i) {
//                    buildSegmentTree(matrix, i, 0, 0, n - 1);
//                }
//            }
//        }
//    }
//
//    void update(int row, int col, int val) {
//        change(row, col, val);
//    }
//
//    int sumRegion(int row1, int col1, int row2, int col2) {
//        return query(row1, col1, row2, col2);
//    }
//};


class NumMatrix {
private:
    vector<vector<int>> pre;

public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m=matrix.size();
        if(m){
            int n=matrix[0].size();
            pre.resize(m,vector<int>(n+1));
            for(int i=0;i<m;++i){
                for(int j=1;j<=n;++j)
                    pre[i][j]=pre[i][j-1]+matrix[i][j-1];
            }
        }
    }

    void update(int row, int col, int val) {
        int a = val - (pre[row][col + 1] - pre[row][col]);
        for (int j = col + 1; j < pre[row].size(); ++j)
            pre[row][j] += a;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i=row1;i<=row2;++i){
            res += pre[i][col2+1]-pre[i][col1];
        }
        return res;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

