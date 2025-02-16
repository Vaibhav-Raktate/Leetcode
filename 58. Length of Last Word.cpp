class Solution {
    public:
        int lengthOfLastWord(string s) {
            int ans=0;
            int rev=s.size()-1;
    
            while(rev>=0 && s[rev]==' '){
                rev--;  
            }
            while(rev>=0 && s[rev]!=' '){
                    rev--;
                    ans++;
                }
            return ans;
        }
    };