class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
    
            for(int i=0;i<nums.size();i++){
                if(mp.count(nums[i])){
                    if(i-mp[nums[i]]<=k){
                        return true;
                    }
                }
                    mp[nums[i]]=i;
                
            }
            return false;
            
            // if(k==0) {
            //     return false;
            // }
            // else{
            //     vector<pair<int,int>>vec;
            //     for(int i=0;i<nums.size();i++){
            //         vec.push_back(make_pair(nums[i],i));
    
            //         sort(vec.begin(),vec.end());
    
            //         for(int i=0;i<vec.size()-1;i++){
            //             if((vec[i].first==vec[i+1].first) && (abs(vec[i].second-vec[i+1].second)<=k))
            //             {
            //                 return true;
            //             }
            //         }
            //     }
            // }
            //  return false;  
        }
    };