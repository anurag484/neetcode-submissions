/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        map<Node*,Node*>mp;
        while(temp){
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(temp){
            mp[temp]->next=temp->next?mp[temp->next]:NULL;
            mp[temp]->random=temp->random?mp[temp->random]:NULL;

            temp=temp->next;
        }
        return mp[head];
    }
};
