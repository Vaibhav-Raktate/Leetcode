class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n=nums.size();
            vector<int>ans(n,1);
            int suffix=1;
    
            for(int i=1;i<n;i++){
                ans[i]=ans[i-1] * nums[i-1];
    
            }
    
            for(int i=n-2;i>=0;i--){
                suffix *=nums[i+1];
                ans[i] *= suffix;
    
            }
            
            
            // for(int i=0;i<n;i++){
            //     int product=1;
            //     for(int j=0;j<n;j++){
            //         if(i != j){
            //             product *= nums[j];   
            //         }
            //     }  
            //     ans[i]=product; 
            // }
            
            return ans;
        }
    };