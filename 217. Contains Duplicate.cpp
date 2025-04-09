class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> s(nums.begin(),nums.end());
            return nums.size()!=s.size();
            

            // int n=nums.size();
            // sort(nums.begin(),nums.end());
            // for(int i=1;i<n;i++){
            //     if(nums[i-1]==nums[i]){
            //         return true;
            //     }
            // }
            // if(n==1) {
            //     return false;
            // }
            // for(int i=0;i<n;i++){
            //     for(int j=i+1;j<n;j++){
            //         if(nums[i]==nums[j]){
            //             return true;
            //         }
            //     }
    
            // }
            //return false;
        }
    };
