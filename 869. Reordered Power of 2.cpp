class Solution {
public:

    string getSorted(int n){
        string s = to_string(n);
        sort(begin(s),end(s));
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string s = getSorted(n);

        for(int p=0; p<=29; p++){
            if(s == getSorted(1 << p)){
                return true;
            }
        }
        return false;
    }
};
