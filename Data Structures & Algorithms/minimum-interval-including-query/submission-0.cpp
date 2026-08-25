class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Sort queries but keep track of their original indices
        vector<pair<int, int>> sorted_queries;
        int q_size = queries.size();
        for (int i = 0; i < q_size; i++) {
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        // Min-heap to store intervals (interval_length, interval_end)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        
        vector<int> result(q_size, -1);  // Initialize result with -1
        
        int i = 0, n = intervals.size();
        
        // Process each query in sorted order
        for (auto& q : sorted_queries) {
            int query = q.first, index = q.second;
            
            // Add all intervals that start before or at query
            while (i < n && intervals[i][0] <= query) {
                int left = intervals[i][0], right = intervals[i][1];
                int length = right - left + 1;
                min_heap.push({length, right});
                i++;
            }
            
            // Remove intervals from heap that are no longer valid (i.e., end < query)
            while (!min_heap.empty() && min_heap.top().second < query) {
                min_heap.pop();
            }
            
            // The top of the heap gives the smallest valid interval
            if (!min_heap.empty()) {
                result[index] = min_heap.top().first;
            }
        }
        
        return result;
    }
};
