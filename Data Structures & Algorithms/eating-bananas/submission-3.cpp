class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        int ans=high;
        while(low<=high){
            int mid=low+((high-low)/2);

            int total_hours=0;
            for(int i=0;i<piles.size();i++){
                // total_hours+=(piles[i]+mid-1)/mid;
                // #include <cmath> // for ceil
                total_hours += (int)ceil((double)piles[i] / mid);

            }
            if(total_hours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
