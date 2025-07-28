class Solution {
public:
    int countsubsets(int idx, int curror, vector<int>& nums, int maxor){
        if(idx == nums.size()){
            if(curror == maxor)
                return 1;
            return 0;
        }

        int takecount = countsubsets(idx+1, curror | nums[idx], nums, maxor);

        int nottakencount = countsubsets(idx+1, curror, nums , maxor);

        return takecount + nottakencount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
         int maxor = 0;
         for(int &num : nums){
            maxor |= num;
         }

         int curror = 0;
         return countsubsets(0 , curror , nums , maxor);
    }
};
