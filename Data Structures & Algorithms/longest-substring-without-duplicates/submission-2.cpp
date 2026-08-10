class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> freq(128, 0);

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            freq[s[right]]++;

            // Duplicate found → shrink window
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            // Current window has unique characters
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};