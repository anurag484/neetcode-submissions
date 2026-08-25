class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        
        // Count the total number of nodes
        while (temp) {
            count++;
            temp = temp->next;
        }
        
        // If the node to remove is the head
        if (count == n) {
            ListNode* newHead = head->next;
            delete head; // Properly delete the head node
            return newHead;
        }
        
        int res = count - n; // Find the position of the node before the one to remove
        temp = head;
        
        // Traverse to the node just before the one to delete
        for (int i = 1; i < res; i++) {
            temp = temp->next;
        }
        
        // Remove the target node
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete; // Properly delete the target node
        
        return head;
    }
};
