class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int> freq(26,0);

        for(char &ch : s){
            freq[ch-'a']++;
        }
        int maxodd = 0;
        int mineven = n+1;

        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;

            if(freq[i]%2 == 0){
                mineven = min(mineven,freq[i]);
            }else{
                maxodd = max(maxodd, freq[i]);
            }
        }
        return maxodd - mineven;
    }
};
