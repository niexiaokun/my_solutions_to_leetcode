#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//86. 分隔链表
//
//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
//你应当保留两个分区中每个节点的初始相对位置。
//
//
//
//示例:
//
//输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkList(vector<int>& v){
    if(v.empty())
        return NULL;
    ListNode* head=new ListNode(v[0]);
    ListNode* p=head;
    for(int i=1;i<v.size();i++){
        p->next=new ListNode(v[i]);
        p=p->next;
    }
    p->next=NULL;
    return head;
}

void printLinkList(ListNode* head){
    ListNode* p=head;
    while(p){
        cout<<p->val<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        if(head==NULL||head->next==NULL)
//            return head;
//        ListNode* dummyhead=new ListNode(0);
//        dummyhead->next=head;
//        ListNode* tail=head;
//        while(tail->next) tail=tail->next;
//        ListNode* p1=dummyhead, *p2=tail, *p;
//        while(p1->next!=tail){
//            if(p1->next->val>=x){
//                p=p1->next;
//                p1->next=p->next;
//                p->next=NULL;
//                p2->next=p;
//                p2=p2->next;
//            }
//            else
//                p1=p1->next;
//        }
//        return dummyhead->next;
//    }
//};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* dummyhead1=new ListNode(0);
        ListNode* dummyhead2=new ListNode(0);
        dummyhead1->next=head;
        ListNode* p1=dummyhead1, *p2=dummyhead2, *p;
        while(p1->next){
            if(p1->next->val>=x){
                p=p1->next;
                p1->next=p->next;
                p2->next=p;
                p2=p2->next;
            }else
                p1=p1->next;
        }
        p2->next=NULL;
        p1->next=dummyhead2->next;
        return dummyhead1->next;
    }
};




int main(int argc, char *argv[]){

    vector<int> nums{3,5,8,5,10,2,1};
    int x=5;
    ListNode* head=createLinkList(nums);
    printLinkList(head);

    printLinkList(Solution().partition(head,x));

    return 0;
}