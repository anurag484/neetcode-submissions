class Solution {
public:
    void combination(int index,int target,vector<int>& candidates,vector<int>& ds,vector<vector<int>>& ans){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            combination(index+1,target-candidates[index],candidates,ds,ans);
            ds.pop_back();
        }
        int ind=index+1;
        while(ind<candidates.size() && candidates[ind]==candidates[index]){
            ind++;
        }
        combination(ind,target,candidates,ds,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        combination(0,target,candidates,ds,ans);
        return ans;
    }
};
