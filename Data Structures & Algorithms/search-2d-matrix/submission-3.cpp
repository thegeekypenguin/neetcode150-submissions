class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = m*n-1;

        while (start <= end){
            int mid = start + (end - start)/2;
            // trick to find the mid element in 2d matrix: matrix [mid/n][mid%n]
            if( matrix[mid/n][mid%n] > target){
                end = mid-1;
            }else if( matrix[mid/n][mid%n] < target){
                start = mid + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};
