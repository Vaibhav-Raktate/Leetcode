class Solution {
    public:
        bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
            string s1,s2;
            for(int s=0;s<word1.size();s++){
                s1=s1+word1[s];
            }
            for(auto &s : word2){
                s2=s2+s;
            }
            return s1==s2;
        }
    };