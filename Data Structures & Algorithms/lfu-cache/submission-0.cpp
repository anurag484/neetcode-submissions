class LFUCache {
public:

    struct Node {
        int key;
        int value;
        int freq;

        list<Node*>::iterator it;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyMap;
    unordered_map<int, list<Node*>> freqMap;


    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }


    void increaseFreq(Node* node) {

        int oldFreq = node->freq;

        // Remove node from old frequency list
        freqMap[oldFreq].erase(node->it);

        // If old frequency becomes empty
        // and it was the minimum frequency
        if(freqMap[oldFreq].empty() &&
           minFreq == oldFreq) {

            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Put node at front of new frequency list
        freqMap[node->freq].push_front(node);

        // Save its new position
        node->it = freqMap[node->freq].begin();
    }


    int get(int key) {

        // Key doesn't exist
        if(keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        Node* node = keyMap[key];

        // Using it increases frequency
        increaseFreq(node);

        return node->value;
    }


    void put(int key, int value) {

        // Capacity 0
        if(capacity == 0) {
            return;
        }


        // Key already exists
        if(keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];

            // Update value
            node->value = value;

            // put() also counts as use
            increaseFreq(node);

            return;
        }


        // Cache is full
        if(keyMap.size() == capacity) {

            // Find LFU frequency
            int freq = minFreq;

            // Last node = LRU among this frequency
            Node* lru = freqMap[freq].back();

            // Remove from frequency list
            freqMap[freq].pop_back();

            // Remove from hashmap
            keyMap.erase(lru->key);

            delete lru;
        }


        // Create new node
        Node* node = new Node(key, value);

        // New nodes always have frequency 1
        minFreq = 1;

        // Insert at front of frequency 1
        freqMap[1].push_front(node);

        // Save iterator
        node->it = freqMap[1].begin();

        // Store in hashmap
        keyMap[key] = node;
    }
};