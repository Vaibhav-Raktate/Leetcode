class NumArray {
    public:
        vector<int> prefix;  // Stores prefix sums
    
        NumArray(vector<int>& nums) {
            int n = nums.size();
            prefix.resize(n);
            
            // Initialize prefix sum array
            prefix[0] = nums[0];  // Set the first element correctly
            for (int i = 1; i < n; i++) {
                prefix[i] = prefix[i - 1] + nums[i];  // Build prefix sum
            }
        }
    
        int sumRange(int left, int right) {
            return left == 0 ? prefix[right] : prefix[right] - prefix[left - 1];
        }
    };
    
    /**
     * Usage Example:
     * NumArray* obj = new NumArray(nums);
     * int param_1 = obj->sumRange(left, right);
     */
    