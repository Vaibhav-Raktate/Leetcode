class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();

        string maxgood ="";

        for(int i=0; i+2<n; i++){
            if(num[i] == num[i+1] && num[i+1]==num[i+2]){
                string cur = num.substr(i,3);
                if(cur > maxgood){
                    maxgood = cur;
                }
            }
        }

        return maxgood;
    }
};
