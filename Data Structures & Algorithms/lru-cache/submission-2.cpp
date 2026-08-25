class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if (mp.size() == capacity) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};
