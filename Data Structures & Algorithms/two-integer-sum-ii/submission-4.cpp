class Solution {
public:
/*  Binary Search Approach:
    for every i
        complement = target - nums[i]

        binary search in
        [i+1 ... n-1]

        if found
            return indices
*/
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        for (int i = 0; i < n; i++) {

            int need = target - numbers[i];

            int lo = i + 1;
            int hi = n - 1;

            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                if (numbers[mid] == need) {
                    return {i + 1, mid + 1};
                }

                if (numbers[mid] < need)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }

        return {};
    }
};
