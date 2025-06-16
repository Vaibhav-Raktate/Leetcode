class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minEl = nums[0];
        int maxdiff = -1;
        for(int j=1; j<n; j++){
            if(nums[j] > minEl){
                maxdiff = max(maxdiff , nums[j]- minEl);
            }else{
                minEl = nums[j];
            }
        }
        return maxdiff;
    }
};
