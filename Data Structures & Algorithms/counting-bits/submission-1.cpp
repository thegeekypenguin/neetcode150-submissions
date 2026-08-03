class Solution {
public:
    vector<int> countBits(int n) {
        vector<string> s;
        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            s.push_back(bitset<32>(i).to_string());
        }

        for (int i = 0; i < s.size(); i++) {
            int temp = 0;
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == '1')
                    temp++;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};