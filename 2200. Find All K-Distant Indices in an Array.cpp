class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;

        for(int j=0; j<n; j++){
           for(int i=0 ;i<n; i++){
            if(nums[i] == key && abs(i-j) <= k){
                result.push_back(j);
                break;
            }
        }
        }
        return result;
        
    }
};
