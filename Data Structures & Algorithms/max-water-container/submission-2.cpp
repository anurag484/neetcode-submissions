class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area=0;
        for(int i=0;i<heights.size();i++){
            for(int j=i+1;j<heights.size();j++){
                area=max(area,min(heights[i],heights[j])*(j-i));
            }
        }
        return area;
    }
};
