class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int temp=nums[0];
        nums.push_back(1e9);
        for( int i=1; i< n; i++ ){
            if( nums[i]<nums[i+1] && nums[i] <nums[i-1])
                temp= nums[i];
        }

        return temp;
    }
};