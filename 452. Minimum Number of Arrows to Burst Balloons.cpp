class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            int ans=1;
            int endpoint=INT_MAX;
            sort(points.begin(),points.end());
    
            for(auto x : points){
                int start= x[0];
                int end= x[1];
    
                if(endpoint<start){
                    ans++;
                    endpoint=end;
                }
                else{
                    endpoint=min(endpoint,end);
                }
            }
            return ans;
        }
    };