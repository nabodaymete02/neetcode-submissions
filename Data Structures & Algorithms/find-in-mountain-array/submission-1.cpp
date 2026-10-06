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
    int findPeak(MountainArray &mountainArr){
        int n = mountainArr.length();
        int low = 0;
        int high = n-1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                // left edge /
                low = mid + 1;
            }
            else high = mid;
        }
        return low;
    }
    int binarySearchIncreasing(int target, int low, int high, MountainArray &mountainArr){
        while(low <= high){
            int mid = low + (high-low)/2;
            int value = mountainArr.get(mid);
            if(value == target) return mid;
            else if(value < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int binarySearchDecreasing(int target, int low, int high, MountainArray &mountainArr){
        while(low <= high){
            int mid = low + (high-low)/2;
            int value = mountainArr.get(mid);
            if(value == target) return mid;
            else if(value < target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr);
        int ans = binarySearchIncreasing(target, 0, peak, mountainArr);
        if(ans!=-1) return ans;
        return binarySearchDecreasing(target, peak+1, n-1, mountainArr);
    }
};