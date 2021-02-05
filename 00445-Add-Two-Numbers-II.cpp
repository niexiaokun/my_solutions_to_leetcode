#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//private:
//    struct Node{
//        ListNode* head;
//        int val;
//        Node(){
//            head=NULL;
//            val=0;
//        }
//        Node(ListNode* h, int v):head(h),val(v){}
//    };
//    Node* help(ListNode* p1, ListNode* p2){
//        if(p1==NULL)
//            return new Node();
//        Node* node=help(p1->next,p2->next);
//        int a=p1->val+p2->val+node->val;
//        ListNode* q=new ListNode(a%10);
//        q->next=node->head;
//        return new Node(q,a/10);
//    }
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        int m=0;
//        int n=0;
//        ListNode* p=l1;
//        while(p){
//            ++m;
//            p=p->next;
//        }
//        p=l2;
//        while(p){
//            ++n;
//            p=p->next;
//        }
//        if(m<n){
//            swap(l1,l2);
//            swap(m,n);
//        }
//        p=l1;
//        vector<int> tmp;
//        for(int i=0;i<m-n;++i){
//            tmp.emplace_back(p->val);
//            p=p->next;
//        }
//        Node* node=help(p,l2);
//        int a=node->val;
//        for(int i=m-n-1;i>=0;--i){
//            a=tmp[i]+a;
//            tmp[i]=a%10;
//            a/=10;
//        }
//        ListNode* res=new ListNode(a);
//        ListNode* pp=res;
//        for(int i=0;i<m-n;++i){
//            pp->next=new ListNode(tmp[i]);
//            pp=pp->next;
//        }
//        pp->next=node->head;
//        return a?res:res->next;
//    }
//};

class Solution {
private:
    ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* next;
        while(cur){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=reverseList(l1);
        ListNode* p2=reverseList(l2);
        int a=p1->val+p2->val;
        ListNode* res=new ListNode(a%10);
        ListNode* q=res;
        a/=10;
        p1=p1->next;
        p2=p2->next;
        while(p1&&p2){
            a+=p1->val+p2->val;
            q->next=new ListNode(a%10);
            q=q->next;
            p1=p1->next;
            p2=p2->next;
            a/=10;
        }
        if(p1==NULL)
            swap(p1,p2);
        while(p1){
            a+=p1->val;
            q->next=new ListNode(a%10);
            q=q->next;
            p1=p1->next;
            a/=10;
        }
        if(a)
            q->next=new ListNode(a);
        return reverseList(res);
    }
};

int main(int argc, char* argv[]){

    return 0;
}
