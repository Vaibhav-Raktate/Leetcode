class Solution {
public:
    int myAtoi(string s) {
        int sign =1;
        int Result=0;
        bool Started=false;

        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && Started==false) continue;

            if((s[i]=='+' || s[i]=='-') && Started==false){
                sign=(s[i]=='-')?-1:1;
                Started=true;
                continue;
            }

            if(s[i]>='0' && s[i]<='9'){
                int Digit=s[i]-'0';

                if(Result>((INT_MAX-Digit)/10)|| Result<(INT_MIN/10)){
                    return (sign==1)? INT_MAX:INT_MIN;
                }

                Result=Result*10 +Digit;
                Started =true;
            }
            else if(Started =true) break;
            else break;
        }
        Result*=sign;
        return Result;
    }
};