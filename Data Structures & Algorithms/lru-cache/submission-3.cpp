class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
            next=NULL;
            prev=NULL;
        }
    };
    int cap;
    unordered_map<int,Node*>mp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->next;    
    }

    void addNode(Node* newNode){
        Node* front=head->next;
        newNode->next=front;
        newNode->prev=head;
        head->next=newNode;
        front->prev=newNode;
    }

    void deleteNode(Node* delNode){
        Node* delprev=delNode->prev;
        Node* delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode=mp[key];
            int res=resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key]=resNode;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* existingNode=mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }

        if(mp.size()==cap){
            Node* lru=tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }

        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};
