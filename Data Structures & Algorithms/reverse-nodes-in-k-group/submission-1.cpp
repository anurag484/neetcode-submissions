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
    // Function to reverse a linked list and return the new head.
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to get the k-th node from the current node.
    ListNode* getkthNode(ListNode* temp, int k) {
        while (temp != nullptr && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr; // Last node of the previous reversed group.
        ListNode* newHead = nullptr; // New head of the final reversed list.

        while (temp != nullptr) {
            // Get the k-th node from the current node.
            ListNode* kthNode = getkthNode(temp, k);
            if (kthNode == nullptr) {
                // If fewer than k nodes remain, connect the remaining nodes.
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            // Store the node after the k-th node for the next group.
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr; // Disconnect the group to reverse.

            // Reverse the current group.
            ListNode* reversedHead = reverse(temp);

            // Update the new head for the first group.
            if (newHead == nullptr) {
                newHead = reversedHead;
            } else {
                prevLast->next = reversedHead; // Connect the previous group's tail.
            }

            // Update the previous group's tail and move to the next group.
            prevLast = temp; // `temp` becomes the tail of the current reversed group.
            temp = nextNode; // Move to the next group.
        }

        return newHead;
    }
};
