class Solution {
public:
    bool canShip(vector<int>& weights,int capacity,int days){
        int daysUsed=1;
        int currentWeight=0;

        for(auto it:weights){
            if(currentWeight+it>capacity){
                daysUsed++;
                currentWeight=0;
            }
            currentWeight+=it;
        }

        return daysUsed<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        int sum=0;


        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }

        int left=maxi;
        int right=sum;

        int ans=left;

        while(left<=right){
            int capacity=left+(right-left)/2;
            if(canShip(weights,capacity,days)){
                ans=capacity;
                right=capacity-1;
            }else{
                left=capacity+1;
            }
        }
        return ans;
    }
};