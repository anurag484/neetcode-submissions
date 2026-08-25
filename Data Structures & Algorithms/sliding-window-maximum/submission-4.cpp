class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<int>ans;
        // for(int i=0;i<=n-k;i++){
        //     int maxi=nums[i];
        //     for(int j=i;j<=i+k-1;j++){
        //         maxi=max(maxi,nums[j]);
        //     }
        //     ans.push_back(maxi);
        // }
        // return ans;

           vector<int>ans;
           deque<int>dq;
           int i=0,j=0;
           int n=nums.size();

           while(j<n){
            while(dq.size()>0 && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[i]){
                    dq.pop_front();
                }
                i++;

            }
            j++;
           }
           return ans;

        // vector<int>ans;
        // deque<int>dq;
        // int n=nums.size();
        // int i=0;
        // int j=0;
        // while(j<n){
        //     while(dq.size()>0 && dq.back()<nums[j]){
        //         dq.pop_back();
        //     }
        //     dq.push_back(nums[j]);
        //     if(j-i+1==k){
        //         ans.push_back(dq.front());
        //         if(dq.front()==nums[i]){
        //             dq.pop_front();
        //         }
        //         i++;
        //     }
        //     j++;
        // }
        // return ans;


    }
};
