class Solution {
public:
    bool ls(vector<int>& nums,int key){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
       int longest=0;
       for(int i=0;i<nums.size();i++){
        int ele=nums[i];
        int count=1;
        while(ls(nums,ele+1)){
            ele=ele+1;
            count++;
        }
        longest=max(longest,count);
       }
       return longest; 
    }
};
