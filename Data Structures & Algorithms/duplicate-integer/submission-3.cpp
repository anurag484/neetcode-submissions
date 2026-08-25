class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second>=2){
                return true;
                break;
            }
        }
        return false;
    }
};
