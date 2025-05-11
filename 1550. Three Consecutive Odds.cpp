class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n =arr.size();
        int count = 0;
        for(int i = 0; i< n; i++){
            if(count ==2 && arr[i]%2 !=0){
                return true;
            }

            if(arr[i]%2 != 0){
                count++;
            }
            else{
                count = 0;
            }
        }
        return false;
    }
};
