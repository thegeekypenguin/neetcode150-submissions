class Solution {
public:
    int characterReplacement(string s, int k) {
        vector <int> freq(26, 0);
        int left=0;
        int maxFreq=0;
        int maxWindow=0;

        for (int right=0; right < s.length(); right++){
            // Update frequency of current character
            freq[s[right] - 'A']++;

            // Update maximum frequency
            maxFreq = max(maxFreq, freq[s[right]-'A']);

            int windowLen = right - left + 1;

            // If characters that need replacement > k, shrink the window
            if(windowLen - maxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            
            windowLen = right - left +1;
            maxWindow = max(maxWindow, windowLen);
        }
        return maxWindow;
    }
};
