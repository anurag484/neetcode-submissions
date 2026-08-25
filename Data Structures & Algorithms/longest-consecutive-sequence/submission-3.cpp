class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=0;
        int count=0;
        int last_smaller=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==last_smaller){
                count=count+1;
                last_smaller=nums[i];
            }
            else if(nums[i]!=last_smaller){
                count=1;
                last_smaller=nums[i];
            }
            longest=max(longest,count);
        }
        return longest;
    }
};
