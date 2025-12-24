class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(), greater<int>());
        int totalapple = accumulate(apple.begin(), apple.end(),0);

        int count=0;
        int i=0;

        while(totalapple > 0){
            totalapple -= capacity[i];
            count++;
            i++;
        }
        return count;
    }
};
