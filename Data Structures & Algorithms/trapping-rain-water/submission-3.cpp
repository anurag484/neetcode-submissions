class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        int water=0;
        for(int i=0;i<n;i++){
            int leftmax=0,rightmax=0;
            for(int j=i;j>=0;j--){
                leftmax=max(leftmax,height[j]);
            }
            for(int j=i;j<n;j++){
                rightmax=max(rightmax,height[j]);
            }
            water+=min(leftmax,rightmax)-height[i];
        }
        return water;
        /*
        int n=height.size();
        if(n==0){
            return 0;
        }
        int left=0;
        int right=n-1;
        int leftmax=0;
        int rightmax=0;
        int ans=0;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]>leftmax){
                    leftmax=height[left];
                }else{
                    ans+=leftmax-height[left];
                }
                left++;
            }else{
                if(height[right]>rightmax){
                    rightmax=height[right];
                }else{
                    ans+=rightmax-height[right];
                }
                right--;
            }
        }
        return ans;
        */
    }
};
