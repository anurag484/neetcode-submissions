class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int area=min(heights[i],heights[j])*(j-i);
                maxi=max(maxi,area);
            }
        }
        return maxi;
    }
};
