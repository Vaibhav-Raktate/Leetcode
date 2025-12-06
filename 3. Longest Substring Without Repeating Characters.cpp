class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        int left = 0 , maxlen = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            while(seen.count(s[i])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[i]);
            maxlen = max(maxlen, i - left + 1);
        }
        return maxlen;
    }
};
