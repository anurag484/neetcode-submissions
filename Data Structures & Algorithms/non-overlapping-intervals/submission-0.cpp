class Solution {
public:
    static bool compare(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),compare);
        int cntNonOverlap=1;
        int endTime=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=endTime){
                cntNonOverlap++;
                endTime=intervals[i][1];
            }

        }

        return n-cntNonOverlap;
    }
};
