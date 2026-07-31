class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        /* WITHPUT USING BIT MANIPULATION
        while (n>0){
            if(n%2 == 1){
                cnt++;
            }
            n= n/2;
        }
        return cnt;
        */

        // USING BIT MANIPULATION
        while(n){
            cnt = cnt + (n&1);
            n >>=1;
        }
        return cnt;
    }
};
