class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int slow=nums[0];
        // int fast=nums[0];
        // do{
        //     slow=nums[slow];
        //     fast=nums[nums[fast]];
        // }while(slow!=fast);
        // fast=nums[0];
        // while(slow!=fast){
        //     slow=nums[slow];
        //     fast=nums[fast];
        // }
        // return slow;

        unordered_set<int>seen;
        for(auto it:nums){
            if(seen.count(it)){
                return it;
            }
            seen.insert(it);
        }
        return -1;
    }
};
