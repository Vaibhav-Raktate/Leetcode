class Solution {
public:
    int countHomogenous(string s) {
        int ans= s.size();
        const int MOD =1000000007;
        int cnt = 1;

        for(int i=1 ; i<s.size(); i++){
            if(s[i] == s[i-1]){
                ans = (ans+cnt)%MOD;
                cnt++;
            }
            else{
                cnt=1;
            }
        }
        return ans;
    }
};
