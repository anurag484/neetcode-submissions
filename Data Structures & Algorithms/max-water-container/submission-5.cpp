class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left=0;
        int right=heights.size()-1;
        int maxarea=0;
        while(left<right){
            int area=min(heights[left],heights[right])*(right-left);
            maxarea=max(maxarea,area);

            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
        // int maxarea=0;
        // int n=heights.size();
        // int l=0;
        // int r=n-1;
        // while(l<r){
        //     int area=min(heights[l],heights[r])*(r-l);
        //     maxarea=max(area,maxarea);

        //     if(heights[l]<=heights[r]){
        //         l++;
        //     }else{
        //         r--;
        //     }
        // }
        // return maxarea;
    }
};
