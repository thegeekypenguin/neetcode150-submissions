class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;

        int i=0, j=n1-1;
        sort(s1.begin(), s1.end());
        while(j<n2){
            string str = "";
            str = s2.substr(i, j-i+1);
            sort(str.begin(), str.end());
            if(str == s1) return true;
            i++, j++;
        }
        return false;
    }
};
