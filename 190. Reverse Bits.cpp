class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            long long rev =0;
            for(int i=0;i<=31;i++){
                long long bit= n&1;
                rev = rev <<1;
                rev = rev|bit;
                n = n>>1;
            }
            return rev;
        }
    };