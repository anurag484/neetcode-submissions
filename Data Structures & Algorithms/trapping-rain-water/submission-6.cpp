class Solution {
public:
    int trap(vector<int>& height) {
        /*
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
        */

        /*
        int n=height.size();
        int water=0;
        if(n==0){
            return 0;
        }
        vector<int>left_max(n),right_max(n);
        left_max[0]=height[0];
        right_max[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left_max[i]=max(left_max[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right_max[i]=max(right_max[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            water+=min(left_max[i],right_max[i])-height[i];
        }
        return water;
        */

        /*
        int n=height.size();
        if(n==0){
            return 0;
        }
        int left=0;
        int right=n-1;
        int leftmax=0;
        int rightmax=0;
        int water=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>leftmax){
                    leftmax=height[left];
                }else{
                    water+=leftmax-height[left];
                }
                left++;
            }else{
                if(height[right]>rightmax){
                    rightmax=height[right];
                }else{
                    water+=rightmax-height[right];
                }
                right--;
            }
        }
        return water;
        */

        int n=height.size();
        int water=0;
        if(n==0){
            return 0;
        }
        vector<int>leftmax(n),rightmax(n);
        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            water+=min(leftmax[i],rightmax[i])-height[i];
        }
        return water;
        
    }
};
