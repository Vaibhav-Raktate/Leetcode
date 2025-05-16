class Solution {
public:

        bool checkhammingdistanceone(string &s1 , string &s2){
            int diff = 0;
            for(int i=0; i<s1.length();i++){
                if(s1[i]!= s2[i]){
                    diff++;
                }
                if(diff > 1){
                    return false;
                }
            }
            return diff ==1;
        }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int longestsub =1;
        int longestsubidx = 0;
        vector<string>result;

        for(int i=0; i<n; i++){
            for(int j=0;j<= i-1;j++){
                if(groups[j] != groups[i] && words[i].length() == words[j].length() && checkhammingdistanceone(words[i], words[j])){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;

                        if(longestsub < dp[i]){
                            longestsub = dp[i];
                            longestsubidx = i;
                        }
                    }
                }
            }      
        }
        while(longestsubidx != -1){
            result.push_back(words[longestsubidx]);
            longestsubidx = parent[longestsubidx];
        }
        reverse(begin(result), end(result));
        return result;
    }
};
