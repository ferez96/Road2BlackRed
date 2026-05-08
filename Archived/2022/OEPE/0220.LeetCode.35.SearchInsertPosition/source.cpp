class Solution {
    int binarySearch(const vector<int>& arr, int value, int left, int right) {
        if (right < left) return left;
        
        int mid = (left+right)/2;
        if (arr[mid] == value) return mid;
        if (arr[mid] > value) return binarySearch(arr, value, left, mid-1);
        return binarySearch(arr, value, mid+1, right);        
    }
    
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};