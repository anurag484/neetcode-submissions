class Solution {
public:
bool ls(vector<int>& nums,int element){
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==element){
            return true;
        }
    }
    return false;
}
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int element=nums[i];
            int count=1;
            while(ls(nums,element+1)==true){
                element=element+1;
                count=count+1;
            }
            longest=max(longest,count);
        }
        return longest;
    }
};
