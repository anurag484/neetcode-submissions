class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int rem=target-num;
            if(mp.find(rem)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[rem]);
            }
            mp[num]=i;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
