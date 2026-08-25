class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n=heights.size();
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int area=min(heights[i],heights[j])*(j-i);
                maxarea=max(maxarea,area);
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
