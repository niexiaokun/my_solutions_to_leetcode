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




__attribute__((constructor))
void f3(){
    printf("__attribute__((constructor))\n");
}

__attribute__((destructor))
void f2(){
    cout << "__attribute__((destructor))" << endl;
}

template <typename T>
void printFun(T a){
    cout << a << endl;
}

template <typename T, typename... V>
void printFun(T& a, V&... b){
    cout << a << " ";
    printFun(b...);
}








int main(int argc, char* argv[]){


    printf("\n");


    printf("\n");

    return 0;
}