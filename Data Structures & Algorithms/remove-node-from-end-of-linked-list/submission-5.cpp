class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
        // // Initialize two pointers: slow and fast
        // ListNode* slow = head;
        // ListNode* fast = head;

        // // Move fast pointer n steps ahead
        // for (int i = 0; i < n; i++) {
        //     fast = fast->next;
        // }

        // // If fast is NULL, we need to remove the head node
        // if (fast == NULL) {
        //     return head->next;
        // }

        // // Move both pointers until fast reaches the end
        // while (fast->next != NULL) {
        //     slow = slow->next;
        //     fast = fast->next;
        // }

        // // Remove the nth node from the end
        // slow->next = slow->next->next;

        // return head;
    }
};
