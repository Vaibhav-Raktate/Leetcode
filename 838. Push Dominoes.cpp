class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        const int Inf = n+1;

        vector<int> Rdist(n,Inf);
            for(int i=0; i<n; i++){
                if(dominoes[i]=='R')    Rdist[i]=0;
                else if(dominoes[i]=='L')   Rdist[i]=Inf;
                else if(i>0) Rdist[i] = Rdist[i-1]+1;
            }
        
        vector<int> Ldist(n,Inf);
        for(int i=n-1; i>=0; i--){
            if(dominoes[i]=='L')    Ldist[i]=0;
            else if(dominoes[i]=='R') Ldist[i]=Inf;
            else if(i<n-1) Ldist[i]=Ldist[i+1]+1;
        }

        string ans = "";
        for(int i=0;i<n;i++){
            if(dominoes[i]!='.')    ans += dominoes[i];
            else if((Rdist[i] >= Inf && Ldist[i] >= Inf) || (Rdist[i]== Ldist[i])) 
            ans +='.';
            else if(Rdist[i] < Ldist[i])    ans +='R';
            else if(Rdist[i] > Ldist[i])    ans+='L';

        }
        return ans;
    }
};
