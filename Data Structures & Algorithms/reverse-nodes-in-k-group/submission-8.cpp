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
    ListNode* getKthNode(ListNode* temp,int k){
        k--;
        while(k>0 && temp){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* newHead=NULL;
        ListNode* prevLast=NULL;

        if(!head || k==1){
            return head;
        }
        while(temp){
            ListNode* kthNode=getKthNode(temp,k);
        if(!kthNode){
            if(prevLast){
                prevLast->next=temp;
            }
            break;
        }
        ListNode* nextNode=kthNode->next;
        kthNode->next=NULL;
        ListNode* reverseHead=reverse(temp);

        

        if(newHead==NULL){
            newHead=reverseHead;
        }else{
            prevLast->next=reverseHead;
        }
        prevLast=temp;
        temp=nextNode;

        }
        return newHead;

        


    }
};
