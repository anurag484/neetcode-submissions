class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2; // Total number of elements in both arrays
        int ind2 = n / 2; // Middle index
        int ind1 = ind2 - 1; // Index before middle for even cases
        int cnt = 0; // Counter to track merged indices
        int ind1el = -1, ind2el = -1; // To store median elements

        int i = 0, j = 0; // Pointers for nums1 and nums2

        // Merging arrays until we find the required indices
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (cnt == ind1) ind1el = nums1[i];
                if (cnt == ind2) ind2el = nums1[i];
                i++;
            } else {
                if (cnt == ind1) ind1el = nums2[j];
                if (cnt == ind2) ind2el = nums2[j];
                j++;
            }
            cnt++;
        }

        // Add remaining elements from nums1
        while (i < n1) {
            if (cnt == ind1) ind1el = nums1[i];
            if (cnt == ind2) ind2el = nums1[i];
            i++;
            cnt++;
        }

        // Add remaining elements from nums2
        while (j < n2) {
            if (cnt == ind1) ind1el = nums2[j];
            if (cnt == ind2) ind2el = nums2[j];
            j++;
            cnt++;
        }

        // Calculate median
        if (n % 2 == 1) {
            return ind2el; // Odd number of elements
        }
        return double(ind1el + ind2el) / 2.0; // Even number of elements
    }
};
