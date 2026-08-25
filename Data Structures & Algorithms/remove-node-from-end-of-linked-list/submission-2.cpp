class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count the total number of nodes
        int count = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        
        // Step 2: Calculate the position to remove from the start
        int position = count - n;
        
        // Step 3: Handle edge case where the head needs to be removed
        if (position == 0) {
            return head->next;
        }
        
        // Step 4: Traverse to the node just before the one to be removed
        curr = head;
        for (int i = 1; i < position; i++) {
            curr = curr->next;
        }
        
        // Step 5: Remove the nth node from the end
        curr->next = curr->next->next;
        
        // Step 6: Return the modified head
        return head;
    }
};
