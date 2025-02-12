#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2; // Avoid overflow
            if (canEatInTime(piles, mid, h)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    bool canEatInTime(vector<int>& piles, long long k, int h) {
        long long hours = 0;  // Prevent overflow
        for (int pile : piles) {
            hours += pile / k;
            if (pile % k != 0) hours++;  // Add extra hour if not a perfect division
            if (hours > h) return false; // Early exit to optimize
        }
        return hours <= h;
    }
};
