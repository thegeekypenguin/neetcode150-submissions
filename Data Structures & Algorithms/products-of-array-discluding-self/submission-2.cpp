class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans(n);

        for(int i=0; i<n; i++){
            int temp=1;
            for(int j =0; j<n; j++){
                if(i != j)
                    temp*= nums[j];
            }
            ans[i] = temp;
        }
        return ans;
    }
};
