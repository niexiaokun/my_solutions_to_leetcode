#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *p1 = head;
        ListNode *p2 = head;
        int cnt = 0;
        while (p1->next && p1->next->next) {
            p1 = p1->next->next;
            p2 = p2->next;
            ++cnt;
            if (p1 == p2)
                break;
        }
        if (p1 != p2 || cnt == 0)
            return NULL;
        if (p1 == head)
            return head;
        ListNode *p3 = head;
        while (p2 != p3) {
            p2 = p2->next;
            p3 = p3->next;
        }
        return p2;
    }
};

int main(int argc, char* argv[]) {



    return 0;
}

