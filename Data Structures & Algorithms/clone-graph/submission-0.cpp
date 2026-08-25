class Solution {
public:
    Node* clone(Node* node,unordered_map<Node*,Node*>& mp){
        Node* newNode=new Node(node->val);
        mp[node]=newNode;
        for(auto neighbor:node->neighbors){
            if(mp.find(neighbor)==mp.end()){
                newNode->neighbors.push_back(clone(neighbor,mp));
            }else{
                newNode->neighbors.push_back(mp[neighbor]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<Node*,Node*>mp;
        return clone(node,mp);
    }
};