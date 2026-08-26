/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearchIncreasing( MountainArray &mountainArr,int target,int low,int high){
        while(low<=high){
            int mid=low+(high-low)/2;
            int value=mountainArr.get(mid);

            if(value==target){
                return mid;
            }
            else if(value<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }

    int binarySearchDecreasing( MountainArray &mountainArr,int target,int low,int high){
        while(low<=high){
            int mid=low+(high-low)/2;
            int value=mountainArr.get(mid);

            if(value==target){
                return mid;
            }

            else if(target>value){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();

        int low=0;
        int high=n-1;

        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        int peak=low;

        int leftResult=binarySearchIncreasing(mountainArr,target,0,peak);
        if(leftResult!=-1){
            return leftResult;
        }

        return binarySearchDecreasing(mountainArr,target,peak+1,n-1);
    }
};