class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            // int ele=nums[i];
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>=2){
                return true;
                break;
            }
        }
        return false;
    }
};
