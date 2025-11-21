class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int max_cost = 0;
        int sum_cost =0;
        int n = colors.size();

        for(int i=0; i<n; ++i){
            if(i>0 && colors[i] != colors[i-1]){
                res += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }

            sum_cost += neededTime[i];
            max_cost = max(max_cost , neededTime[i]);
        }

        res += sum_cost - max_cost;
        return res;
    }
};
