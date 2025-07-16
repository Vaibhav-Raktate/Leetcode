class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int Evencount =0;
        int Oddcount = 0;
        int alternating =1;
        int n = nums.size();
        for(int &num : nums){
            if(num%2 == 0){
                Evencount++;
            }else{
                Oddcount++;
            }  
        }

        int parity = nums[0]%2;
        for(int i=1; i<n; i++){
            int currentparity = nums[i]%2;
            if(currentparity != parity){
                alternating++;
                parity = currentparity;
            }
        }
        return max({Evencount, Oddcount, alternating});
    }
};
