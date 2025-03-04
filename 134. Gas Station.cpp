class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int totalgas=0;
            int currentgas=0;
            int startindex=0;
            int n=gas.size();
            for(int i=0;i<n;i++){
                currentgas+=gas[i]-cost[i];
                totalgas+=gas[i]-cost[i];
    
                if(currentgas<0){
                    startindex=i+1;
                    currentgas=0;
                }
            }
            return totalgas>=0?startindex:-1;
        }
    };