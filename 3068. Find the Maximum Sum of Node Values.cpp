class Solution {
public:
typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> fayda;
        ll normalsum = 0;

        for(int i=0;i<nums.size();i++){
            normalsum += nums[i];

            fayda.push_back((nums[i]^k) - nums[i]);
        }
        sort(begin(fayda) , end(fayda) , greater<int>());
        int n = fayda.size();
        for(int i=0; i<n-1;i+=2){
            ll pairsum = fayda[i] + fayda[i+1];

            if(pairsum > 0){
                normalsum += pairsum;
            }
        }
        return normalsum;
    }
};
