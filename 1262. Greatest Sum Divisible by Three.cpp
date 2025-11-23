class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<vector<int>> t(n+1, vector<int>(3, INT_MIN));

        t[n][0] = 0;
        t[n][1] = INT_MIN;
        t[n][2] = INT_MIN;

        for(int i = n-1; i>=0; i--){
            for(int remain = 0; remain<=2; remain++){
                int newRemain = (remain + nums[i])%3;
                int take = nums[i] + t[i+1][newRemain];

                int skip = t[i+1][remain];
                t[i][remain] = max(take, skip);
            }
        }
        
        return t[0][0];
    }
};
