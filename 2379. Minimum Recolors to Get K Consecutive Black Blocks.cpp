class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int i = 0;
        int j= 0;
        int W =0;
        int  ops  = k;
        while(j<n){
            if(blocks[j] == 'W'){
                W++;
            }
            if(j-i+1 == k){
                ops = min(ops, W);

                if(blocks[i] == 'W'){
                    W--;
                }
                i++;
            }
            j++;
        }
        return ops;
    }
};
