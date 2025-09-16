class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> hs ;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || j==k || k==i || digits[i]==0) continue;
                    int digit = digits[i]*100 + digits[j]*10 + digits[k];
                    if(digit%2 !=0) continue;
                    hs.insert(digit);
                }
            }
        }
        return hs.size();
    }
};
