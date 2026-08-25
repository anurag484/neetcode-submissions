class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k; // Initialize K
        // Add elements from nums into the priority queue
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop(); // Maintain the size of the heap as K
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop(); // Maintain the size of the heap as K
        }
        return pq.top(); // Top element is the Kth largest
    }
};
