class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>>pq;
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            int squared=(x*x)+(y*y);
            pq.push({squared,it});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
