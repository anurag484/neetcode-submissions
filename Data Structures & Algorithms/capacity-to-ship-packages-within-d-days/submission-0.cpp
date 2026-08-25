class Solution {
public:
    bool canShip(vector<int>& weights,int days,int capacity){
        int dayUsed=1;
        int currentWeight=0;

        for(int weight:weights){
            if(currentWeight+weight>capacity){
                dayUsed++;
                currentWeight=0;
            }
            currentWeight+=weight;
        }

        return dayUsed<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        int sum=0;

        for(auto it:weights){
            maxi=max(maxi,it);
            sum+=it;
        }

        int left=maxi;
        int right=sum;
        int ans=left;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(canShip(weights,days,mid)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};