class Solution {
    public:
        bool isAnagram(string s, string t) {
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
           // cout<<s;
            if(s==t) return true;
            return false;
    
    
    
            // unordered_map<char,int> m1;
            // unordered_map<char,int> m2;
            // if(s.size()!=t.size()){
            //     return false;
            // }
    
            // for(int i=0;i<s.size();i++){
            //     m1[s[i]]++;
            //     m2[t[i]]++;
            // }
    
            // if(m1==m2) return true;
            // return false;
    
    
    
            // if(s.size()!=t.size())
            // return false;
    
            // vector<int>h(26);
            // for(int i=0;i<s.size();i++)
            // h[s[i]-'a']++;
    
            // for(int i=0;i<t.size();i++){
            //     int x=--h[t[i]-'a'];
            //     if(x<0);
            //     return false;
            // }
            // return true;
        }
    };