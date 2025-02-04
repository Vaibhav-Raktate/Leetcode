class Solution {
public:

    int check(string s,int p1,int p2,int &st,int &end){
        int count=0;

        if(p1==p2){
            count++;
            p1--;
            p2++;
        }

        while(p1>=0 and p2<s.length()){
            if(s[p1]!=s[p2]){
                st=p1+1;
                end=p2-1;
                return count;
            }
            else{
                p1--;
                p2++;
                count+=2;
            }
        }
        st=p1+1;
        end=p2-1;
        return count;
    }

    string longestPalindrome(string s) {
        int st=-1;
        int end=-1;
        int length=0;
        int fs=-1;
        int fe=-1;

        for(int i=0;i<s.length();i++){
            int x=check(s,i,i,st,end);
            if(x>length){
                length=x;
                fs=st;
                fe=end;
            }

            int y=check(s,i,i+1,st,end);
                if(y>length){
                    length=y;
                    fs=st;
                    fe=end;

                }
            }
            return s.substr(fs,fe-fs+1);
        }   
};