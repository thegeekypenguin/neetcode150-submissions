class Solution {
public:

    int binSearch(int start, int end, vector<int>& nums, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Find the pivot element (rotation point)
        int s = 0, e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e])
                s = mid + 1;
            else
                e = mid;
        }
        int idx = s;

        // Search left half
        int A = binSearch(0, idx - 1, nums, target);
        if (A != -1) return A;

        // Search right half
        int B = binSearch(idx, n - 1, nums, target);
        return B;
    }
};