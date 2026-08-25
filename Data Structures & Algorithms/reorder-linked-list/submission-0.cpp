/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
   ListNode* findMid(ListNode* head){
    ListNode* prev=NULL;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    return slow;
   }
   ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* front=head;
    while(curr!=NULL){
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
   }
   void merge(ListNode* l1,ListNode* l2){
    while(l2){
        ListNode* front=l1->next;
        l1->next=l2;
        l1=l2;
        l2=front;
    }
   }
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return ;
        }
        ListNode* mid=findMid(head);
        ListNode* reversed=reverse(mid);
        merge(head,reversed);
    }
};
