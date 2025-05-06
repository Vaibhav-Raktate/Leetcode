class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxsi=1;
        int maxsd=1;
        int inccount = 1;
        int deccount = 1;

        if(n == 1) return 1;

        for(int i=1; i<n; i++){
        if(nums[i]>nums[i-1]){
            inccount++;
            deccount=1;
        }
        else if(nums[i] < nums[i-1]){
            inccount =1;
            deccount++;
        }
        else{
            inccount =1;
            deccount = 1;
        }
        maxsi = max(maxsi , inccount);
        maxsd = max(maxsd , deccount);
    }
        return max(maxsi, maxsd);
    }
};
