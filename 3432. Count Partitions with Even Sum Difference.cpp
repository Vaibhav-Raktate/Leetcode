class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums),end(nums),0);
        int result = 0;
        int leftsum = 0;

        for(int i=0; i<=n-2; i++){
            leftsum += sum - leftsum;

            int rightsum = sum - leftsum;

            if((leftsum - rightsum) %2 == 0 ){
                result++;
            }
        }
        return result;

    }
};
