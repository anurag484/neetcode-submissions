class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;  // max-heap

        for (auto it : points) {
            int x = it[0];
            int y = it[1];
            int squared = (x * x) + (y * y);

            pq.push({squared, {x, y}});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
