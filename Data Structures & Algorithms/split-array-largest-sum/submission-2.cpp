class Solution {
public:
    bool canSplit(vector<int>& nums,int maxi,int k){
        int parts=1;
        int currSum=0;
        for(auto it:nums){
            if(currSum+it>maxi){
                parts++;
                currSum=it;
            }else{
                currSum+=it;
            }
            
        }
        return parts<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        int high=sum;

        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSplit(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};