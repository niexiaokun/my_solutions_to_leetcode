#include <bits/stdc++.h>
#include <semaphore.h>
#include <thread>

using namespace std;

namespace utils {
    template<typename T>
    void printVec(const vector<T> &nums) {
        if (nums.empty()) {
            cout << "[]" << endl;
            return;
        }
        cout << "[ ";
        for (const T &u:nums)
            cout << u << " ";
        cout << "]" << endl;
    }

    template<typename T>
    void printVec(const vector<T> &nums, int l, int r) {
        if (l > r)
            return;
        cout << "[ ";
        for (int i = l; i <= r; i++)
            cout << nums[i] << " ";
        cout << "]" << endl;
    }

    template<typename T>
    void printVvec(const vector<vector<T>> &nums) {
        if (nums.empty())
            return;
        cout << "[" << endl;
        for (const vector<T> &v:nums) {
            cout << "[ ";
            for (const T &u:v)
                cout << u << " ";
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
}




int main(int argc, char* argv[]) {


    return 0;
}