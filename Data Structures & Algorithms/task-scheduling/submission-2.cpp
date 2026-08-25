class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqMap;
        for (char task : tasks) {
            freqMap[task]++;
        }

        // Max-heap to store task frequencies
        priority_queue<int> pq;
        for (auto it : freqMap) {
            pq.push(it.second);
        }

        int time = 0;

        // Process tasks
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = 0;

            // Execute tasks in the current cycle
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top() - 1); // Decrease frequency for completed task
                    pq.pop();
                    cycle++;
                }
            }

            // Push remaining tasks back into the heap
            for (int remainingFreq : temp) {
                if (remainingFreq > 0) {
                    pq.push(remainingFreq);
                }
            }

            // Add time for the current cycle
            time += (!pq.empty() ? n + 1 : cycle);
        }

        return time;
    }
};
