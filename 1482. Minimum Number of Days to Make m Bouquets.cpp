class Solution {
public: 
    int getNumberOfBouqets(vector<int>& bloomDay, int mid, int k){
    int numberOfBouqets = 0;
    int count=0;
    for(int i=0;i < bloomDay.size(); i++){
        if(bloomDay[i] <=mid){
            count++;
            if(count==k){
            numberOfBouqets++;
            count=0;
            }
        }
        else{
            count = 0;
            }
        }
    return numberOfBouqets;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
         long long total = (long long)m * k;
        if (bloomDay.size() < total) return -1;
        int low=1 , high=*max_element(bloomDay.begin(), bloomDay.end());
        int minDays=-1;
        
        while(low<= high){
            int mid = low + (high - low)/2;

            if(getNumberOfBouqets(bloomDay, mid, k) >= m){
                minDays= mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return minDays;
    }
};
