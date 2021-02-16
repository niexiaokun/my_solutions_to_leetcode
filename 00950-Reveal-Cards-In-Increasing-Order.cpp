#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq;
        dq.push_back(deck.back());
        for (int i = n - 2; i >= 0; --i) {
            int x = dq.back();
            dq.pop_back();
            dq.push_front(x);
            dq.push_front(deck[i]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};



int main(int argc, char* argv[]) {


    return 0;
}

