class Solution {
    public:
        string firstPalindrome(vector<string>& words) {
            for(int i=0;i<words.size();i++){
                if(ispalindrome(words[i])) return words[i];
            }
            return "";
        }
    
    public:
            bool ispalindrome(string s){
                int start=0;
                int end=s.size()-1;
                while(start<end){
                    if(s[start]==s[end]){
                        start++;
                        end--;
                    }
                    else{
                        return false;
                    }
                }
                return true;
            }
    };