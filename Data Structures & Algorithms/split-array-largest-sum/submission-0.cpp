class Solution {
public:
    bool canSplit(vector<int>& nums,int k,long long maxSum){
        int parts=1;
        long long currentSum=0;

        for(int num:nums){
            if(currentSum+num>maxSum){
                parts++;
                currentSum=num;
            }else{
                currentSum+=num;
            }
        }
        return parts<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);

        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canSplit(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};