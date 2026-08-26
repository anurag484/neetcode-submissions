class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        int low = 0;
        int high = n;

        while(low <= high) {

            int cut1 = low + (high - low) / 2;

            int cut2 = (n + m + 1) / 2 - cut1;

            int left1;
            int right1;

            int left2;
            int right2;

            if(cut1 == 0) {
                left1 = INT_MIN;
            }
            else {
                left1 = nums1[cut1 - 1];
            }

            if(cut1 == n) {
                right1 = INT_MAX;
            }
            else {
                right1 = nums1[cut1];
            }

            if(cut2 == 0) {
                left2 = INT_MIN;
            }
            else {
                left2 = nums2[cut2 - 1];
            }

            if(cut2 == m) {
                right2 = INT_MAX;
            }
            else {
                right2 = nums2[cut2];
            }

            if(left1 <= right2 && left2 <= right1) {

                if((n + m) % 2 == 1) {
                    return max(left1, left2);
                }

                int leftMax = max(left1, left2);
                int rightMin = min(right1, right2);

                return (leftMax + rightMin) / 2.0;
            }

            else if(left1 > right2) {
                high = cut1 - 1;
            }

            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};