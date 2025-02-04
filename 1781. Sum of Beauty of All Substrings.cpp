class Solution {
public:
    int beautySum(string s) {
        int ans=0,n=s.size();
        for (int i=0;i<n;i++){
            map<char ,int>m ; 
            multiset<int>st;   
            for (int j=i;j<n;j++){
            m[s[j]]++;
            int mf=0;
            int lf=INT_MAX;
            for(auto a:m){
                mf=max(mf,a.second);
                lf=min(lf,a.second);
            }
            ans+=(mf-lf);

            }
        }
        return ans;
    }
};