class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // Handle edge case: empty list

        // Step 1: Create a mapping of original nodes to new nodes
        unordered_map<Node*, Node*> mp;
        Node* current = head;

        while (current) {
            Node* newNode = new Node(current->val); // Create a new node
            mp[current] = newNode; // Map original node to new node
            current = current->next; // Move to the next node
        }

        // Step 2: Set the next and random pointers for the new nodes
        current = head;
        while (current) {
            Node* newNode = mp[current];
            newNode->next = mp[current->next]; // Set the next pointer
            newNode->random = mp[current->random]; // Set the random pointer
            current = current->next; // Move to the next node
        }

        // Return the head of the new list
        return mp[head];
    }
};
