class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;

        int left=0, right =1;
        int profit=0;

        while(right < n){
            if(prices[left] < prices[right]){
                profit= max(profit, prices[right] - prices[left]);
            }else{
                left = right;
            }
            right++;
        }
        return profit;
    }
};
